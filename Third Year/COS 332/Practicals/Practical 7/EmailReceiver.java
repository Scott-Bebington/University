import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class EmailReceiver {
    public void receiveMail() {
        try {
            // Connect to the POP3 server
            Socket socket = new Socket("localhost", 110); // 110 is the default port for POP3

            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            OutputStreamWriter writer = new OutputStreamWriter(socket.getOutputStream());

            // Read the server response
            String response = reader.readLine();

            if (!response.startsWith("+OK")) {
                System.out.println("Error: " + response);
                socket.close();
                return;
            }

            // Send the username
            writer.write("USER scott\r\n");
            writer.flush();

            // Read the server response
            response = reader.readLine();

            if (!response.startsWith("+OK")) {
                System.out.println("Error: " + response);
                socket.close();
                return;
            }

            // Send the password
            writer.write("PASS Scott25121\r\n");
            writer.flush();

            // Read the server response
            response = reader.readLine();

            if (!response.startsWith("+OK Logged in.")) {
                System.out.println("Error: " + response);
                socket.close();
                return;
            }

            // Get the last email number
            writer.write("STAT\r\n");
            writer.flush();

            // Read the server response
            response = reader.readLine();

            if (!response.startsWith("+OK")) {
                System.out.println("Error: " + response);
                socket.close();
                return;
            }

            String[] parts = response.split(" ");
            int emailCount = Integer.parseInt(parts[1]);

            // Retrieve the last email sent
            writer.write("RETR " + emailCount + "\r\n");
            writer.flush();

            // Read the server response
            response = reader.readLine();
            // System.out.println("Server: " + response);

            if (!response.startsWith("+OK")) {
                System.out.println("Error: " + response);
                socket.close();
                return;
            }

            // Read the email
            String subject = "[BCC WARNING] ";
            boolean blindCopy = false;
            String line;
            while (!(line = reader.readLine()).equals(".")) {
                if (line.startsWith("X-Original-To: bcc-")) {
                    blindCopy = true;
                } else if (line.startsWith("Subject: ")) {
                    subject += line.substring(9);
                }
            }

            // System.out.println("Email received: " + subject + " (BCC: " + blindCopy + ")");
            EmailSender sender = new EmailSender();
            sender.sendEmail("BCCWARNING@localhost", "scott@localhost", subject, "This is a BCC Warning email fo the email, please be aware that replying to all may make other receivers aware that you were copied", blindCopy);


            // Close the connection
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
