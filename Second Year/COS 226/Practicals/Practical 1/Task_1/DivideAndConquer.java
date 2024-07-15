package Task_1;

public class DivideAndConquer extends Thread {
    private Integer[] array;
    private int start;
    private int end;

    public DivideAndConquer(Integer[] array, int start, int end) {
        this.array = array;
        this.start = start;
        this.end = end;
    }

    public void run() {
        for (int i = start; i < end; i++) {
            if (isPrime(array[i])) {
                System.out.println(Thread.currentThread().getName() + " [" + array[start] + "-" + array[end - 1] + "]: " + array[i]);
            }
        }
    }

    private boolean isPrime(int num) {
        if (num > 1) {
            int count = 0;
            for (int i = 1; i <= num; i++) {
                if (num % i == 0) {
                    count++;
                }
                if (count > 2) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
