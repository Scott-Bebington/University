public class Main {
    public static void main(String args[]) {
        int numThreads = 6;
        MCSQueue filter = new MCSQueue();
        Crud C = new Crud(filter);
        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < numThreads; i++) {
            Thread t = new Node(C);
            threads[i] = t;
            t.start();
        }
    }
}
