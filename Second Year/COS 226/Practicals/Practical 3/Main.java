public class Main {
    public static void main(String[] args) {

        boolean wait = true;

        // System.out.println("\u001B[32m\nSRSW initial value: -100\n\u001B[0m");
        // SRSW(wait);

        // System.out.println("\u001B[38;5;208m\nMRSW initial value: -100\n\u001B[0m");
        // MRSW(wait);

        System.out.println("\u001B[31m\nMRMW initial value: -100\n\u001B[0m");
        MRMW(wait);
    }

    public static void SRSW(boolean wait) {
        int threadCount = 2;
        MyThreads[] threads = new MyThreads[threadCount];
        AtomicSRSW<Integer> reg = new AtomicSRSW<Integer>(-100);

        threads[0] = new MyThreads(reg, false, "SRSW", wait);
        threads[1] = new MyThreads(reg, true, "SRSW", wait);

        for (MyThreads t : threads)
            t.start();

        for (MyThreads t : threads)
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
    }

    public static void MRSW(boolean wait) {
        int threadCount = 10;
        MyThreads[] threads = new MyThreads[threadCount];
        AtomicMRSW<Integer> reg = new AtomicMRSW<Integer>(-100, threadCount - 1);

        for (int i = 0; i < threadCount; i++) {
            threads[i] = new MyThreads(reg, false, "MRSW", wait);
            threads[i].setName("Thread-" + i);
        }

        threads[threadCount - 1] = new MyThreads(reg, true, "MRSW", wait);
        threads[threadCount - 1].setName("Thread-" + (threadCount - 1));

        for (MyThreads t : threads)
            t.start();

        for (MyThreads t : threads)
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
    }

    public static void MRMW(boolean wait) {
        int readers = 10;
        int writers = 10;
        MyThreads[] threads = new MyThreads[readers + writers];
        AtomicMRMW<Integer> reg = new AtomicMRMW<>(writers, -100);

        for (int i = 0; i < writers; i++) {
            threads[i] = new MyThreads(reg, true, "MRMW", wait);
            threads[i].setName("Thread-" + i);
        }

        for (int i = writers; i < readers + writers; i++) {
            threads[i] = new MyThreads(reg, false, "MRMW", wait);
            threads[i].setName("Thread-" + i);
        }
        for (MyThreads t : threads)
            t.start();

        for (MyThreads t : threads)
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
    }
}
