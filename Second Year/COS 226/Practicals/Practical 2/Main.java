public class Main {
    public static void main(String[] args) {
        // System.out.println("\nTask 1\n");
        // task1();

        System.out.println("\nTask 2\n");
        task2();
    }

    public static void task1() {

        int numThreads = 5;
        MyThread[] threads = new MyThread[numThreads];
        Filter filter = new Filter(numThreads);
        SharedResources CriticalSection = new SharedResources(filter);

        for (int i = 0; i < numThreads; i++)
            threads[i] = new MyThread(CriticalSection);

        for (MyThread t : threads)
            t.start();

        for (MyThread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public static void task2() 
    {
        int numThreads = 5;
        Bakery newBakery = new Bakery(numThreads);

        MyThread[] threads = new MyThread[numThreads];

        for (int i = 0; i < numThreads; i++) {
            SharedResources newSharedResources = new SharedResources(newBakery);
            MyThread thread = new MyThread(newSharedResources);
            thread.setName("Thread-" + i);
            threads[i] = thread;
            thread.start();
        }

        for (int index = 0; index < numThreads; index++) {
            try {
                threads[index].join();
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }
}
