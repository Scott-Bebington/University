import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static List<Question> questions = readQuestions("questions.txt");
    static int currentQuestion = 1;
    static boolean isAnswered = false;
    static String answer = "";
    static int score = 0, count = 0;

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
                handleClient(clientSocket, questions);
            }
        } catch (Exception e) {
            System.out.println("Error Starting the server");
            // e.printStackTrace();
        }
    }

    // Handle client connection
    public static void handleClient(Socket clientSocket, List<Question> questions) {
        try {
            String response = "";
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            // get the data that was sent
            String query = in.readLine();
            System.out.println("Query: " + query);

            if (query.startsWith("GET /?continue=No") || currentQuestion > questions.size()) {
                response = ShowScore();
            } else if (query.startsWith("GET /?answer=")) {
                // answer = query.substring(7).toUpperCase();
                answer = getAnswer(query);
                isAnswered = true;
                response = htmlResponse(
                        String.valueOf(currentQuestion),
                        questions.get(currentQuestion - 1).getQuestion(),
                        questions.get(currentQuestion - 1).getOptions());
                currentQuestion++;
            } else if (query.startsWith("GET / HTTP/1.1") || query.startsWith("GET /?continue=Yes")) {
                isAnswered = false;
                response = htmlResponse(
                        String.valueOf(currentQuestion),
                        questions.get(currentQuestion - 1).getQuestion(),
                        questions.get(currentQuestion - 1).getOptions());
            }

            // Set response headers
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            // Send the response to the browser
            out.println(response);
            out.flush();

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static String htmlResponse(
            String QuestionNumber,
            String Question,
            List<String> Options) {

        String formattedOptions = "";
        for (int i = 0; i < Options.size(); i++) {
            char option = (char) ('A' + i);
            formattedOptions += "<li>" + option + ") " + Options.get(i) + "</li>\n";
        }

        String response = "HTTP/1.1 200 OK\r\n" +
                "Content-Type: text/html\r\n" +
                "<html lang=\"en\">\n" +
                "\n" +
                "<head>\n" +
                "    <meta charset=\"UTF-8\">\n" +
                "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n" +
                "    <title>Document</title>\n" +
                "</head>\n" +
                "\n" +
                "<body>\n" +
                "    <div class=\"outerDiv\">\n" +
                "        <h1>Question " + QuestionNumber + "</h1>\n" +
                "        <p>" + Question + "</p>\n" +
                "        <!-- Options -->\n" +
                "        <ul>\n" +
                "            " + formattedOptions +
                "        </ul>\n";

        if (!isAnswered) {
            response += "        <form action=\"http://localhost:55555\" method=\"get\">\n" +
                    "            <!-- Create a name and surname input field -->\n" +
                    "            <!-- <label for=\"answer\">Answer:</label> -->\n" +
                    "            <input type=\"text\" id=\"answer\" name=\"answer\" placeholder=\"Answer\"><br><br>\n" +
                    "            <!-- <input type=\"submit\" value=\"Submit\"> -->\n" +
                    "            <button class=\"submitButton\" type=\"submit\">Submit form</button>\n" +
                    "        </form>\n";
        } else {
            if (questions.get(currentQuestion - 1).isCorrect(answer)) {
                System.out.println("The answer is correct");
                score++;
                response += "<div class=\"correct\">Your answer of " + answer + ": "
                        + questions.get(currentQuestion - 1).getAnswer() + " is correct!</div>";
            } else {
                System.out.println("The answer is incorrect");
                response += "<div class=\"incorrect\">Your answer of " + answer + " is incorrect!</div>" +
                        "<div>The correct answer is " + questions.get(currentQuestion - 1).getAnswer() + "</div>";
            }
            response += "<br /><br />" +
                    "<div>Would you like to continue?</div>" +
                    "<div class=\"ButtonContainer\">" +
                    "    <form style=\"width: 50%;\" action=\"http://localhost:55555\" method=\"get\">" +
                    "        <button class=\"NoButton\" name=\"continue\" value=\"No\">No</button>" +
                    "    </form>" +
                    "    <form style=\"width: 50%;\" action=\"http://localhost:55555\" method=\"get\">" +
                    "        <button class=\"YesButton\" name=\"continue\" value=\"Yes\">Yes</button>" +
                    "    </form>" +
                    "</div>";
        }

        response += "    </div>\n" +
                "\n" +
                "</body>\n" +
                "\n" +
                CSS() +
                "\n" +
                "</html>";
        return response;
    }

    public static String ShowScore() {
        String response = "HTTP/1.1 200 OK\r\n" +
                "Content-Type: text/html\r\n" +
                "<html lang=\"en\">\n" +
                "\n" +
                "<head>\n" +
                "    <meta charset=\"UTF-8\">\n" +
                "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n" +
                "    <title>Document</title>\n" +
                "</head>\n" +
                "\n" +
                "<body>\n" +
                "    <div class=\"outerDiv\">\n" +
                "        <h1>Quiz is finished</h1>\n" +
                "        <h1>Your score is: " + score + " / " + (currentQuestion - 1) + "</h1>\n" +
                "    </div>\n" +
                "\n" +
                "</body>\n" +
                "\n" +
                CSS() +
                "\n" +
                "</html>";

        return response;
    }

    // CSS for the HTML
    public static String CSS() {
        String response = "<style>\n" +
                "    body {\n" +
                "        font-family: Arial, sans-serif;\n" +
                "        margin: 0;\n" +
                "        padding: 0;\n" +
                "        background-color: black;\n" +
                "        display: flex;\n" +
                "        justify-content: center;\n" +
                "        align-items: center;\n" +
                "        height: 100vh;\n" +
                "        width: 100vw;\n" +
                "    }\n" +
                "\n" +
                "    .outerDiv {\n" +
                "        /* background-color: white; */\n" +
                "        outline: solid 1px white;\n" +
                "        color: white;\n" +
                "        padding: 20px;\n" +
                "        border-radius: 10px;\n" +
                "        box-shadow: 0 0 10px rgba(255, 255, 255, 0.5);\n" +
                "        width: 20vw;\n" +
                "    }\n" +
                "\n" +
                "    form input {\n" +
                "        height: 3vh;\n" +
                "        width: 100%;\n" +
                "        border: none;\n" +
                "        background-color: transparent;\n" +
                "        outline: solid 1px white;\n" +
                "        color: white;\n" +
                "        border-radius: 10px;\n" +
                "    }\n" +
                "\n" +
                "    .submitButton {\n" +
                "        height: 5vh;\n" +
                "        width: 100%;\n" +
                "        border: none;\n" +
                "        background-color: transparent;\n" +
                "        outline: solid 1px white;\n" +
                "        color: white;\n" +
                "        border-radius: 20px;\n" +
                "        /* make it ease in and out */\n" +
                "        transition: all 1s;\n" +
                "    }\n" +
                "\n" +
                "    .submitButton:hover {\n" +
                "        height: 5vh;\n" +
                "        width: 100%;\n" +
                "        border: none;\n" +
                "        background-color: blue;\n" +
                "        color: white;\n" +
                "        outline: none;\n" +
                "        border-radius: 20px;\n" +
                "    }\n" +
                "\n" +
                "    .correct {\n" +
                "        color: green;\n" +
                "    }\n" +
                "\n" +
                "    .incorrect {\n" +
                "        color: red;\n" +
                "    }\n" +
                "\n" +
                "    .ButtonContainer {\n" +
                "        display: flex;\n" +
                "        justify-content: space-between;\n" +
                "    }\n" +
                "\n" +
                "    .YesButton {\n" +
                "        height: 5vh;\n" +
                "        width: 95%;\n" +
                "        border: none;\n" +
                "        background-color: transparent;\n" +
                "        outline: solid 1px white;\n" +
                "        color: white;\n" +
                "        border-radius: 20px;\n" +
                "        transition: all 1s;\n" +
                "    }\n" +
                "\n" +
                "    .YesButton:hover {\n" +
                "        height: 5vh;\n" +
                "        width: 95%;\n" +
                "        border: none;\n" +
                "        background-color: green;\n" +
                "        color: white;\n" +
                "        outline: none;\n" +
                "        border-radius: 20px;\n" +
                "    }\n" +
                "\n" +
                "    .NoButton {\n" +
                "        height: 5vh;\n" +
                "        width: 95%;\n" +
                "        border: none;\n" +
                "        background-color: transparent;\n" +
                "        outline: solid 1px white;\n" +
                "        color: white;\n" +
                "        border-radius: 20px;\n" +
                "        transition: all 1s;\n" +
                "    }\n" +
                "\n" +
                "    .NoButton:hover {\n" +
                "        height: 5vh;\n" +
                "        width: 95%;\n" +
                "        border: none;\n" +
                "        background-color: red;\n" +
                "        color: white;\n" +
                "        outline: none;\n" +
                "        border-radius: 20px;\n" +
                "    }\n" +
                "</style>\n";
        return response;
    }

    private static String getAnswer(String request) {
        String value = "";
        String[] lines = request.split("\r\n");
        for (String line : lines) {
            if (line.startsWith("GET /?answer=")) {
                value = line.substring(13, 14);
                break;
            }
        }
        return value;
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
