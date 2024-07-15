import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Formatter;

public class FTPUploader {

    public static void main(String[] args) {
        String server = "localhost";
        int port = 21;
        String user = "scott";
        String pass = "Scott25121";
        String remoteFilePath = "ftpfile.txt";
        String localFilePath = "uploadfile.txt";
        String hashedPath = "hashedfile.txt";

        // Prompt the user for file contents

        Socket socket = null;
        BufferedReader reader = null;
        BufferedWriter writer = null;
        FileInputStream fis = null;

        try {
            String fileContents = promptUserForFileContents();
            uploadFile(fileContents, server, port, user, pass, remoteFilePath, localFilePath, socket, reader, writer,
                    fis);

            // Hash the file contents
            String algorithm = "SHA-256";
            String hash = hashString(fileContents, algorithm);
            uploadFile(hash, server, port, user, pass, hashedPath, localFilePath, socket, reader, writer, fis);
            System.out.println("Hash: " + hash);
        } catch (IOException e) {
            e.printStackTrace();
        }

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

    private static void uploadFile(String fileContents, String server, int port, String user, String pass,
            String remoteFilePath, String localFilePath, Socket socket, BufferedReader reader, BufferedWriter writer,
            FileInputStream fis) {
        try {
            // Prompt the user for file contents

            // Create the local file with the user-provided contents
            createLocalFile(localFilePath, fileContents);

            // Connect to the server
            socket = new Socket(server, port);
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

            // Read server response
            System.out.println(reader.readLine());

            // Send user credentials
            sendCommand(writer, reader, "USER " + user);
            sendCommand(writer, reader, "PASS " + pass);

            // Open a data connection for file transfer
            String pasvResponse = sendCommand(writer, reader, "PASV");
            String[] pasvParts = pasvResponse.split("[()]")[1].split(",");
            String ip = String.join(".", pasvParts[0], pasvParts[1], pasvParts[2], pasvParts[3]);
            int port1 = Integer.parseInt(pasvParts[4]);
            int port2 = Integer.parseInt(pasvParts[5]);
            int dataPort = port1 * 256 + port2;

            // Connect to the data port
            Socket dataSocket = new Socket(ip, dataPort);

            // Send STOR command to store the file on the server
            sendCommand(writer, reader, "STOR " + remoteFilePath);

            // Read the file and write it to the data connection
            fis = new FileInputStream(localFilePath);
            OutputStream os = dataSocket.getOutputStream();
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = fis.read(buffer)) != -1) {
                os.write(buffer, 0, bytesRead);
            }

            // Close the data connection
            os.close();
            dataSocket.close();

            System.out.println("File uploaded successfully.");
        } catch (IOException ex) {
            System.out.println("Error: " + ex.getMessage());
            ex.printStackTrace();
        } finally {
            try {
                if (fis != null) {
                    fis.close();
                }
                if (writer != null) {
                    writer.close();
                }
                if (socket != null) {
                    socket.close();
                }
                // Delete the local file after upload
                deleteLocalFile(localFilePath);
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    private static String sendCommand(BufferedWriter writer, BufferedReader reader, String command) throws IOException {
        System.out.println(command);
        writer.write(command + "\r\n");
        writer.flush();
        String response = reader.readLine();
        System.out.println(response);
        return response;
    }

    // Method to prompt the user for file contents
    private static String promptUserForFileContents() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the contents of the file: ");
        return br.readLine();
    }

    // Method to create a local file with the provided contents
    private static void createLocalFile(String filePath, String contents) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filePath));
        bw.write(contents);
        bw.close();
    }

    // Method to delete the local file
    private static void deleteLocalFile(String filePath) {
        File file = new File(filePath);
        if (file.exists()) {
            file.delete();
        }
    }
}
