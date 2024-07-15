public class Node extends Thread {

    public Server serve;
    volatile boolean locked = false;
    volatile Node next = null;
    volatile Node prev = null;
    String threadname = "";
    int count = 1;

    int assignedCount = 0;

    Node() {
    }

    Node(Server s) {
        this.serve = s;
    }

    @Override
    public void run() {
        serve.AssignThreadToPeople();


        while (serve.peopleCount != 4) {
            System.out.print("");
        }

        if (serve.isReader(getThreadId())) {
            while (serve.writeflag) {
                serve.ReceiveMessage();
            }
        }

        if (!serve.isReader(getThreadId())) {
            while (serve.MessageListOutgoing.size() > 0) {
                serve.sendMessage();
            }
            serve.writeflag = false;
        }
    }

    private int getThreadId() {
        return Integer.parseInt(Thread.currentThread().getName().split(" ")[1]);
    }
}
