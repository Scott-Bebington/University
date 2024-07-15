import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Formatter;

public class FTPListner {

    public void listen() {
        String server = "localhost";
        int port = 21;
        String user = "scott";
        String pass = "Scott25121";
        String localFilePath = "ftpfile.txt";
        String hashPath = "hashedfile.txt";

        Socket socket = null;
        BufferedReader reader = null;
        BufferedWriter writer = null;
        FTPDownloader downloader = new FTPDownloader();

        while (true) {
            try {
                // Connect to the server
                socket = new Socket(server, port);
                reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

                // Read server response
                reader.readLine();

                // Login to the server
                sendCommand(writer, reader, "USER " + user);
                sendCommand(writer, reader, "PASS " + pass);

                // Set to passive mode
                String pasvResponse = sendCommand(writer, reader, "PASV");
                String[] pasvParts = pasvResponse.split("[()]")[1].split(",");
                String ip = String.join(".", pasvParts[0], pasvParts[1], pasvParts[2], pasvParts[3]);
                int port1 = Integer.parseInt(pasvParts[4]);
                int port2 = Integer.parseInt(pasvParts[5]);
                int dataPort = port1 * 256 + port2;

                // Connect to the data port
                Socket dataSocket = new Socket(ip, dataPort);
                InputStream dataInputStream = dataSocket.getInputStream();

                // Send RETR command to download the file
                sendCommand(writer, reader, "RETR " + hashPath);

                // Read the file from the data connection and compare it with the local file
                byte[] ftpFileBytes = dataInputStream.readAllBytes();
                byte[] localFileBytes = Files.readAllBytes(Paths.get(localFilePath));

                // Hash the local file content
                String localFileHash = hashString(new String(localFileBytes), "SHA-256");

                if (!localFileHash.equals(new String(ftpFileBytes))) {
                    System.out.println("File has been modified, downloading file from ftp server.");
                    downloader.downloadFile();
                }

                // Close the data connection
                dataInputStream.close();
                dataSocket.close();

                // Log out and close the control connection
                sendCommand(writer, reader, "QUIT");

            } catch (NoSuchFileException ex) {
                System.out.println("File not found, downloading file from ftp server.");
                downloader.downloadFile();
            } catch (IOException ex) {
                System.out.println("Error: " + ex.getMessage());
                ex.printStackTrace();
            } finally {
                try {
                    if (reader != null) {
                        reader.close();
                    }
                    if (writer != null) {
                        writer.close();
                    }
                    if (socket != null) {
                        socket.close();
                    }
                } catch (IOException ex) {
                    ex.printStackTrace();
                }

                try {
                    Thread.sleep(15000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private static String sendCommand(BufferedWriter writer, BufferedReader reader, String command) throws IOException {
        writer.write(command + "\r\n");
        writer.flush();
        String response = reader.readLine();
        return response;
    }

    public static String hashString(String input, String algorithm) {
        try {
            MessageDigest messageDigest = MessageDigest.getInstance(algorithm);
            byte[] hashBytes = messageDigest.digest(input.getBytes(StandardCharsets.UTF_8));
            return bytesToHex(hashBytes);
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("Algorithm not found", e);
        }
    }

    private static String bytesToHex(byte[] bytes) {
        Formatter formatter = new Formatter();
        for (byte b : bytes) {
            formatter.format("%02x", b);
        }
        String result = formatter.toString();
        formatter.close();
        return result;
    }
}
