import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class MCSQueue implements Lock {
    AtomicReference<Node> tail;
    ThreadLocal<Node> myNode;
    String StartingThread = "";
    boolean flag = true;

    Condition allAssigned = newCondition();

    public MCSQueue() {
        tail = new AtomicReference<Node>(null);
        myNode = new ThreadLocal<Node>() {
            protected Node initialValue() {
                return new Node();
            }
        };
    }

    public void lock() {
        // System.out.println("Locking " + Thread.currentThread().getName() + " thread");

        Node node = myNode.get();
        Node pred = tail.getAndSet(node);
        node.threadname = Thread.currentThread().getName();

        if (pred != null) {
            node.locked = true;
            pred.next = node;
            while (node.locked) {
                // System.out.print("");
            }
        }
        
        // Setting the starting node
        if (flag) {
            StartingThread = Thread.currentThread().getName();
            flag = false;
        }

        
    }

    public void unlock() {
        Node node = myNode.get();
        node.count++;
        // printQueue();

        if (node.next == null) {
            if (tail.compareAndSet(node, null)) {
                return;
            }

            // wait until successor fills in the next field
            while (node.next == null) {
            }
        }
        node.next.locked = false;
        node.next = null;

        
    }
    
    public void printQueue() {
        Node Node = myNode.get();
        // System.out.println("Printing queue");

        Node temp = Node;
        String str = "QUEUE: ";
        while (temp.next != null) {
            str += "{" + temp.next.threadname + ": Request " + temp.next.count + "} -> ";
            temp = temp.next;
        }
        if (str.length() > 7) {
            str = str.substring(0, str.length() - 4);
            System.out.println(str);
        }
    }
    

    public void lockInterruptibly() {

    }

    public boolean tryLock() {
        lock();
        return true;
    }

    public boolean tryLock(long time, TimeUnit unit) {
        return false;
    }

    public Condition newCondition() {
        return null;
    }

    public static long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }
}