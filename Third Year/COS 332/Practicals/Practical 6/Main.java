import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
// import java.util.Base64;
import java.util.List;
import java.util.Random;
import java.io.*;

public class Main {
    // Read questions from the file
    public static List<Question> readQuestions(String filename) {
        List<Question> quiz = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            String question = null;
            List<String> answers = null;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.startsWith("?")) {
                    if (question != null)
                        quiz.add(new Question(question, answers));
                    answers = new ArrayList<>();
                    question = line.substring(1);
                } else {
                    answers.add(line);
                }
            }
            if (question != null)
                quiz.add(new Question(question, answers));
        } catch (Exception e) {
            System.out.println("Error in readQuestions()");
            // e.printStackTrace();
        }
        return quiz;
    }

    // Set up server to wait for Telnet connections
    public static void startServer(List<Question> questions) {
        try (ServerSocket serverSocket = new ServerSocket(55555)) {
            System.out.println("Server is listening on port 55555...");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Connection established with " + clientSocket.getInetAddress());
                Thread clientThread = new Thread(() -> handleClient(clientSocket, questions));
                clientThread.start();
            }
        } catch (Exception e) {
            System.out.println("Error Starting the server");
            // e.printStackTrace();
        }
    }

    // Handle client connection
    public static void handleClient(Socket clientSocket, List<Question> questions) {
        try {
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            EmailSender sender = new EmailSender();

            int score = 0;
            int count = 0;

            while (!questions.isEmpty()) {
                count++;
                Question question = getRandomQuestion(questions);

                out.println(question.getQuestion() + "?");
                for (int i = 0; i < question.getOptions().size(); i++) {
                    out.println((char) ('A' + i) + ". " + question.getOptions().get(i));
                }
                String response = in.readLine();
                if (question.isCorrect(response)) {
                    out.println("\u001B[32mYour answer of " + response.toUpperCase() + " is Correct!\u001B[0m\n");
                    score++;
                } else {
                    out.println("\u001B[31mYour answer of " + response.toUpperCase() + " is Incorrect!\u001B[0m\n");
                    out.println("The correct answer is: " + question.getAnswer() + "\n");
                }

                questions.remove(question);

                if (questions.isEmpty()) {
                    out.println("No more questions left!\n");
                    out.println("Your final score is: " + score + "/" + count + "\n");
                    out.println("Please enter the email address you would like to email the results to:");
                    String res = in.readLine();
                    sender.sendEmail("sender@localhost", res, "Quiz Results", "Your final score is: " + score + "/" + count);
                    break;
                }

                out.println("Would you like to continue? (Y/N): ");
                String cont = in.readLine();
                if (cont.equalsIgnoreCase("N")) {
                    out.println("Your final score is: " + score + "/" + count + "\n");
                    out.println("Please enter the email address you would like to email the results to:");
                    String res = in.readLine();
                    sender.sendEmail("sender@localhost", res, "Quiz Results", "Your final score is: " + score + "/" + count);
                    break;
                }
            }

            out.close();
            in.close();
        } catch (Exception e) {
            // System.out.println("Error in handleClient()");
            // e.printStackTrace();
            System.out.println("Client: " + clientSocket.getInetAddress() + " disconnected");
        } finally {
            try {
                clientSocket.close();
            } catch (Exception e) {
                System.out.println("Error in closing client socket");
                e.printStackTrace();
            }
        }
    }

    // Get a random question from the list
    public static Question getRandomQuestion(List<Question> questions) {
        Random random = new Random();
        int index = random.nextInt(questions.size());
        return questions.get(index);
    }

    public static void sendResults(String email, int score, int total) {
        // Send the results to the email using the SMTP protocol
        
    }

    // Main function
    public static void main(String[] args) {
        String filename = "questions.txt"; // Specify the file containing the questions
        List<Question> questions = readQuestions(filename);
        startServer(questions);
    }
}

class Question {
    private String question;
    private List<String> options;
    private String answer;

    public Question(String question, List<String> options) {
        this.question = question;
        this.options = new ArrayList<>(options);
        handleOptions();
    }

    public String getQuestion() {
        return question;
    }

    public List<String> getOptions() {
        return options;
    }

    public String getAnswer() {
        return answer;
    }

    public void handleOptions() {
        int correctAnswerCount = 0;
        for (int i = 0; i < options.size(); i++) {
            if (options.get(i).startsWith("+")) {

                answer = options.get(i).substring(1);
                correctAnswerCount++;
            }
            options.set(i, options.get(i).substring(1));
        }

        if (correctAnswerCount == 0) {
            answer = "None of the above";
            options.add(answer);
        }

        if (correctAnswerCount > 1) {
            answer = "More than one of the above";
            options.add(answer);
        }
    }

    public boolean isCorrect(String letter) {
        // get the index equivalent to the letter
        int index = letter.toUpperCase().charAt(0) - 'A';
        return options.get(index).equals(answer);
    }

    @Override
    public String toString() {
        String str = question + "\n";
        for (int i = 0; i < options.size(); i++) {
            str += (char) ('A' + i) + ". " + options.get(i) + "\n";
        }
        str += "Answer: " + answer + "\n";
        return str;
    }

}

class EmailSender {
    private static final String SMTP_SERVER = "localhost";
    private static final int SMTP_PORT = 25;

    public void sendEmail(String from, String to, String subject, String message) throws java.io.IOException {
        
        // Connect to SMTP server
        try {
            java.net.Socket socket = new java.net.Socket(SMTP_SERVER, SMTP_PORT);
            java.io.BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(socket.getInputStream()));
            java.io.BufferedWriter writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(socket.getOutputStream()));

            // Read initial server response
            String response = reader.readLine();
            System.out.println(response);
            
            // Send email headers
            writer.write("HELO " + SMTP_SERVER + "\r\n");
            writer.write("MAIL FROM:<" + from + ">\r\n");
            writer.write("RCPT TO:<" + to + ">\r\n");
            writer.write("DATA\r\n");
            writer.write("Subject: " + subject + "\r\n");
            writer.write(message + "\r\n");
            writer.write(".\r\n");
            writer.flush();

            socket.close();

            System.out.println("Email sent successfully!");
        } catch (UnknownHostException e) {
            System.out.println("Unknown host: " + SMTP_SERVER);
        } catch (IOException e) {
            System.out.println("I/O error: " + e.getMessage());
        }
    }
}
