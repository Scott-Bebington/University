public class Main {
    public static void main(String args[]) {
        // Task_1();
        Task_2();
    }

    public static void Task_1() 
    {
        int numThreads = 5;
        MCSQueue filter = new MCSQueue();
        Printer p = new Printer(filter);
        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < numThreads; i++) {
            Thread t = new Node(p);
            threads[i] = t;
            t.start();
        }
    }

    public static void Task_2() 
    {
        int numThreads = 5;
        Timeout filter = new Timeout();
        Printer p = new Printer(filter);
        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < numThreads; i++) {
            Thread t = new Node(p);
            threads[i] = t;
            t.start();
        }
    }
}
