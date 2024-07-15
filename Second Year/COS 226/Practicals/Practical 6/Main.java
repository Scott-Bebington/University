public class Main {
    public static void main(String args[]) {
        // Task_1();
        Task_2();
    }

    public static void Task_1() {
        int numThreads = 6;
        LockInterface LockFreeQueue = new LockFreeQueue();
        Server server = new Server(LockFreeQueue);
        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < 4; i++) {
            Thread t = new RunThreads(server);
            t.setName("Dev-" + (i + 1));
            threads[i] = t;
        }

        for (int i = 0; i < 2; i++) {
            Thread t = new RunThreads(server);
            t.setName("Admin-" + (i + 1));
            threads[i + 4] = t;
        }

        for (int i = 0; i < numThreads; i++) {
            threads[i].start();
        }

        for (int i = 0; i < numThreads; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }

    public static void Task_2() {
        int numThreads = 6;
        LockInterface LockFreeStack = new LockFreeStack();
        Server server = new Server(LockFreeStack);
        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < 4; i++) {
            Thread t = new RunThreads(server);
            t.setName("Dev-" + (i + 1));
            threads[i] = t;
        }

        for (int i = 0; i < 2; i++) {
            Thread t = new RunThreads(server);
            t.setName("Admin-" + (i + 1));
            threads[i + 4] = t;
        }

        for (int i = 0; i < numThreads; i++) {
            threads[i].start();
        }

        for (int i = 0; i < numThreads; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }
}
