import java.io.*;
import java.net.Socket;

public class FTPDownloader {

    public void downloadFile() {
        String server = "localhost";
        int port = 21;
        String user = "scott";
        String pass = "Scott25121";
        String remoteFilePath = "ftpfile.txt";
        String localFilePath = "ftpfile.txt";

        Socket socket = null;
        BufferedReader reader = null;
        BufferedWriter writer = null;
        FileOutputStream fos = null;

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
            sendCommand(writer, reader, "RETR " + remoteFilePath);

            // Read the file from the data connection and write it to the local file
            fos = new FileOutputStream(localFilePath);
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = dataInputStream.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }

            System.out.println("File downloaded successfully.");

            // Close the data connection
            dataInputStream.close();
            dataSocket.close();

            // Log out and close the control connection
            sendCommand(writer, reader, "QUIT");

        } catch (IOException ex) {
            System.out.println("Error: " + ex.getMessage());
            ex.printStackTrace();
        } finally {
            try {
                if (fos != null) {
                    fos.close();
                }
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
        }
    }

    private static String sendCommand(BufferedWriter writer, BufferedReader reader, String command) throws IOException {
        // System.out.println(command);
        writer.write(command + "\r\n");
        writer.flush();
        String response = reader.readLine();
        // System.out.println(response);
        return response;
    }
}
