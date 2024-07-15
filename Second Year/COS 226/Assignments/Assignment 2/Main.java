public class Main {
    public static void main(String args[]) {
        int numThreads = 8;
        MCSQueue filter = new MCSQueue();
        Server C = new Server(filter);
        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < numThreads; i++) {
            Thread t = new Node(C);
            t.setName("Thread " + i);
            threads[i] = t;
            t.start();
        }
    }
}
