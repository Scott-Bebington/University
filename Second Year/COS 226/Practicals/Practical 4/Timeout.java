import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class Timeout implements Lock {
    static RunThreads AVAILABLE = new RunThreads();
    AtomicReference<RunThreads> tail;
    ThreadLocal<RunThreads> myNode;

    int count = 0;
    String StartingThread = "";
    boolean flag = true;
    String[] QUEUE = new String[0];

    public Timeout() {
        tail = new AtomicReference<RunThreads>(null);
        myNode = new ThreadLocal<RunThreads>() {
            protected RunThreads initialValue() {
                return new RunThreads();
            }
        };
    }

    public void lock() {

    }

    public void addToQueue(String threadname) {
        String[] temp = new String[QUEUE.length + 1];
        for (int i = 0; i < QUEUE.length; i++) {
            temp[i] = QUEUE[i];
        }
        temp[QUEUE.length] = threadname;
        QUEUE = temp;
    }

    public boolean tryLock() {

        long timeout = 2000;

        RunThreads qnode = new RunThreads();
        qnode.threadname = Thread.currentThread().getName();
        myNode.set(qnode);

        qnode.prev = null;
        RunThreads myPred = tail.getAndSet(qnode);

        // setting next node for printing the queue
        if (myPred != null) {
            myPred.next = qnode;
        }


        if (myPred == null
                || myPred.prev == AVAILABLE) {
            return true;
        }

        long start = System.currentTimeMillis();
        while (System.currentTimeMillis() - start < timeout) {
            RunThreads predPred = myPred.prev;
            if (predPred == AVAILABLE) {
                return true;
            } else if (predPred != null) {
                myPred = predPred;
            }
        }
        if (!tail.compareAndSet(qnode,
                myPred))
            qnode.prev = myPred;

        if (myPred != null) {
            myPred.next = null;
        }
        return false;
    }

    public void unlock() {

        // Setting the starting node
        if (flag) {
            StartingThread = Thread.currentThread().getName();
            flag = false;
        }

        RunThreads Node = myNode.get();
        // Node myPred = tail.getAndSet(Node);

        // setting next node for printing the queue
        

        tail.get().count++;

        printQueue();

        if (!tail.compareAndSet(Node,
                null))
            Node.prev = AVAILABLE;

    }

    public void printQueue() {
        RunThreads Node = myNode.get();

        RunThreads temp = Node;
        String str = "QUEUE: ";
        while (temp.next != null) {
            str += "{" + temp.next.threadname + ": Request " + temp.count + "} -> ";
            temp = temp.next;
        }
        if (str.length() > 7) {
            str = str.substring(0, str.length() - 4);
            System.out.println(str);
        }
    }

    public void lockInterruptibly() {

    }

    public boolean tryLock(long time, TimeUnit unit) {
        return false;
    }

    public Condition newCondition() {
        return null;
    }

}
