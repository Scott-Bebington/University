package Task_1;

public class Main {
    public static void main(String[] args) {
        int n = 0;
        int m = 100;

        // Consider adding 1 to the end to include m in the search range
        int size = m - n;
        Integer[] array = new Integer[size];

        // Initialize the array with integers from n to m
        for (int i = 0; i < size; i++) {
            array[i] = n + i;
        }

        int numThreads = 0;
        int rangePerThread = 0;

        // Dynamic option for numThreads Task 1
        {
            for (int i = n; i < m; i++) {
                if (i > 1 && m % i == 0) {
                    numThreads = i;
                    break;
                }
            }

            if (numThreads == 0) {
                numThreads = 1;
            }
        }

        // Static option for numThreads Task 1
        {
            numThreads = 4;
            rangePerThread = size / numThreads;
        }

        Task1(array, numThreads, rangePerThread);
    }

    public static void Task1(Integer[] arr, int numThreads, int rangePerThread) {

        System.out.println();
        Thread[] threads = new DivideAndConquer[numThreads];
        for (int i = 0; i < numThreads; i++) {
            int start = i * rangePerThread;
            int end = start + rangePerThread;
            threads[i] = new DivideAndConquer(arr, start, end);
            threads[i].start();
        }

        try {
            for (int i = 0; i < numThreads; i++) {
                threads[i].join();
            }
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
