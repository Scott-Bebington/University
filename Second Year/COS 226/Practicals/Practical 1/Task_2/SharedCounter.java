package Task_2;

public class SharedCounter extends Thread {
    private Integer[] array;
    private int End;
    private static PetersonLock sharedLock = new PetersonLock();
    private static int counter = 0;
    private static int rangeStart;

    public SharedCounter(Integer[] array) {
        this.array = array;
        this.End = this.array[array.length - 1] - this.array[0];
        counter = 0;
        rangeStart = this.array[0];
    }

    public void run() {
        boolean flag = true;
        while (flag) {
            sharedLock.lock();

            while (counter < this.End && !isPrime(this.array[counter])) {
                getAndIncrement();
            }

            if(counter <= this.End && isPrime(this.array[counter]))
            {
                System.out.println(Thread.currentThread().getName() + " [" + (rangeStart + 1) + "-" + this.array[counter] + "]: " + this.array[counter]);
            }

            if (counter < this.End) {
                rangeStart = this.array[counter];
            }
            
            counter++;
            sharedLock.unlock();

            if (counter > this.End) {
                flag = false;
            }
        }
    }

    private boolean isPrime(int num) {
        if (num > 1) {
            int count = 0;
            for (int i = 2; i <= num; i++) {
                if (num % i == 0) {
                    count++;
                }
                if (count > 1) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    private int getAndIncrement() {
        return ++counter;
    }
}
