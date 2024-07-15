package Task_2;

class PetersonLock {
    private volatile boolean[] flag = new boolean[2];
    private volatile int victim;

    public void lock() {
        int id = getThreadId();
        int other = 1 - id;

        flag[id] = true;
        victim = id;

        while (flag[other] && victim == id) {
            // System.out.println("wait");
        }
    }

    public void unlock() {
        int id = getThreadId();
        flag[id] = false;
    }

    private int getThreadId() {
        return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
    }
}
