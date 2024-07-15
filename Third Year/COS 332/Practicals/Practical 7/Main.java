// Authors: 
// Scott Bebington u21546216
// Stefan Hendrik Jansen van Rensburg u22550055


public class Main {

    // Main function
    public static void main(String[] args) {

        EmailSender sender = new EmailSender();
        EmailReceiver receiver = new EmailReceiver();

        try {
            sender.sendEmail("sender@localhost", "scott@example", "Quiz Results", "Your final score is: 5/5", false);
            sender.sendEmail("sender@localhost", "scott@localhost", "Quiz Results", "Your final score is: 5/5", true);
            receiver.receiveMail();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
