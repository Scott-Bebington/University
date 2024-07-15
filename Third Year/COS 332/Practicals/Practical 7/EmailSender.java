import java.io.IOException;
import java.net.UnknownHostException;

class EmailSender {
    private static final String SMTP_SERVER = "localhost";
    private static final int SMTP_PORT = 25;

    public void sendEmail(String from, String to, String subject, String message, boolean blindCopy) throws java.io.IOException {
        
        // Connect to SMTP server
        try {
            java.net.Socket socket = new java.net.Socket(SMTP_SERVER, SMTP_PORT);
            java.io.BufferedWriter writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(socket.getOutputStream()));
            
            // Send email headers
            writer.write("HELO " + SMTP_SERVER + "\r\n");
            writer.write("MAIL FROM:<" + from + ">\r\n");
            if (blindCopy) {
                writer.write("RCPT TO:<bcc-" + to + ">\r\n");
            } else {
                writer.write("RCPT TO:<" + to + ">\r\n");
            }
            writer.write("DATA\r\n");
            writer.write("Subject: " + subject + "\r\n");
            writer.write(message + "\r\n");
            writer.write(".\r\n");
            // System.out.println("Email sent successfully!");
            writer.flush();


            socket.close();
        } catch (UnknownHostException e) {
            System.out.println("Unknown host: " + SMTP_SERVER);
        } catch (IOException e) {
            System.out.println("I/O error: " + e.getMessage());
        }
    }
}