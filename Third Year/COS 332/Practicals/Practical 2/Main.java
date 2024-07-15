import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

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
                    break;
                }

                out.println("Would you like to continue? (Y/N): ");
                String cont = in.readLine();
                if (cont.equalsIgnoreCase("N")) {
                    out.println("Your final score is: " + score + "/" + count + "\n");
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
