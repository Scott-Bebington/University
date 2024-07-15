import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.locks.Lock;

public class Server {
    public volatile Queue<Info> ThreadDatabaseWriters = new LinkedList<>();
    public volatile Queue<Info> ThreadDatabaseReaders = new LinkedList<>();
    public volatile Queue<String> MessageListOutgoing = new LinkedList<>();
    public volatile Queue<Messages> MessageListIncoming = new LinkedList<>();
    Messages IncommingMessage = null;
    public volatile Queue<String> PeopleList = new LinkedList<>();

    Lock l;

    String redColorCode = "\u001B[31m";
    String resetColorCode = "\u001B[0m";

    // Assigning People to threads
    public volatile int peopleCount = 0;
    boolean Reader = true;
    volatile boolean writeflag = true;

    public Server(Lock l) {
        this.l = l;

        String[] Messasges = {
                "Hello, world!",
                "How are you today?",
                "This is a random message.",
                "Java is awesome!",
                "Coding is fun.",
                "Have a great day!",
                "Random message generator.",
                "OpenAI GPT-3.5 is amazing!",
                "Programming is a superpower.",
                "Enjoy your coding journey!"
        };

        String People[] = {
                "Scott",
                "Kyla",
                "Tim",
                "Stefan"
        };

        for (int i = 0; i < Messasges.length; i++) {
            MessageListOutgoing.add(Messasges[i]);
        }

        for (int i = 0; i < People.length; i++) {
            PeopleList.add(People[i]);
        }

        // System.out.println("\nMessages");
        // System.out.println("--------");
        // Object[] arr = MessageListOutgoing.toArray();
        // for (int i = 0; i < Messasges.length; i++) {
        //     System.out.println(arr[i]);
        // }
        // System.out.println("--------\n");
    }

    public void AssignThreadToPeople() {
        l.lock();
        try {
            if (peopleCount < 4) {
                Object[] arr = PeopleList.toArray();
                if (Reader) {
                    ThreadDatabaseReaders.add(new Info(getThreadId(), (String) arr[peopleCount], true));
                    System.out.println("Thread " + getThreadId() + " is a reader for: " + arr[peopleCount]);
                    Reader = false;
                } else {
                    ThreadDatabaseWriters.add(new Info(getThreadId(), (String) arr[peopleCount], false));
                    System.out.println("Thread " + getThreadId() + " is a writer for: " + arr[peopleCount]);
                    peopleCount++;
                    Reader = true;
                }
            }
        } finally {
            l.unlock();
            while (peopleCount != 4 && !Reader) {
                System.out.print("");
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private int getThreadId() {
        return Integer.parseInt(Thread.currentThread().getName().split(" ")[1]);
    }

    public void sendMessage() {
        l.lock();
        Info td = ThreadDatabaseWriters.poll();
        try {
            if (MessageListOutgoing.size() > 0) {

                String message = MessageListOutgoing.poll();
                String recipient = pickRandomClient();
                while (recipient.equals(td.ClientName)) {
                    recipient = pickRandomClient();
                }
                System.out.println("(SEND) Thread " + td.ThreadID + " {sender: " + td.ClientName + ", recipient: "
                        + recipient + "}");
                System.out.println("(SEND) Thread " + td.ThreadID + ": Successful");
                IncommingMessage = new Messages(message, td.ClientName, recipient, td.ThreadID);
                ThreadDatabaseWriters.add(td);

                Thread.sleep(500);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            l.unlock();
        }
    }

    public void ReceiveMessage() {
        Info t = getThreadDetails(getThreadId());

        if (IncommingMessage != null && IncommingMessage.Receiver.equals(t.ClientName)) {
            System.out.println("(Receive) Thread " + getThreadId() + " {recipient: " + IncommingMessage.Receiver
                    + ", sender: " + IncommingMessage.Sender + ", Message: " + IncommingMessage.MessageString + "}\n");
            IncommingMessage = null;
        }
    }

    // Helper Functions
    public String pickRandomClient() {
        int min = 0;
        int max = 4;
        int random = (int) ((Math.random() * (max - min)) + min);
        Object[] arr = PeopleList.toArray();
        return (String) arr[random];
    }

    public Info getThreadDetails(int ThreadID) {
        for (Info i : ThreadDatabaseReaders) {
            if (i.ThreadID == ThreadID) {
                return i;
            }
        }
        for (Info i : ThreadDatabaseWriters) {
            if (i.ThreadID == ThreadID) {
                return i;
            }
        }
        return null;
    }

    public boolean isReader(int ThreadID) {
        for (Info i : ThreadDatabaseReaders) {
            if (i.ThreadID == ThreadID) {
                if (i.reader) {
                    return i.reader;
                }
            }
        }
        return false;
    }
}