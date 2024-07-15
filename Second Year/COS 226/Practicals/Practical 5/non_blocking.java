import java.util.concurrent.atomic.AtomicMarkableReference;

class Window {
    public RunThreads pred, curr;

    Window(RunThreads myPred, RunThreads myCurr) {
        pred = myPred;
        curr = myCurr;
    }

}

public class non_blocking implements ListInterface {

    RunThreads head;

    public non_blocking() {
        head = new RunThreads(Integer.MIN_VALUE);
        head.nextNonBlocking = new AtomicMarkableReference<>(new RunThreads(Integer.MAX_VALUE), false);
    }

    public boolean add(JobDetails item) {
        int key = item.hashCode();
        while (true) {
            Window window = find(head, key);
            RunThreads pred = window.pred, curr = window.curr;
            if (curr.key == key) {
                return false;
            } else {
                RunThreads node = new RunThreads(item);
                node.nextNonBlocking = new AtomicMarkableReference<>(curr, false);
                if (pred.nextNonBlocking.compareAndSet(curr, node, false, false)) {
                    return true;
                }
            }
        }
    }

    public boolean remove(JobDetails item) {
        int key = item.hashCode();
        boolean snip;
        while (true) {
            Window window = find(head, key);
            RunThreads pred = window.pred, curr = window.curr;
            if (curr.key != key) {
                return false;
            } else {
                RunThreads succ = curr.nextNonBlocking.getReference();
                snip = curr.nextNonBlocking.compareAndSet(succ, succ, false, true);
                if (!snip)
                    continue;
                pred.nextNonBlocking.compareAndSet(curr, succ, false, false);
                return true;
            }
        }
    }

    public Window find(RunThreads head, int key) {
        RunThreads pred = null, curr = null, succ = null;
        boolean[] marked = { false };
        boolean snip;
        retry: while (true) {
            pred = head;
            curr = pred.nextNonBlocking.getReference();
            while (true) {
                succ = curr.nextNonBlocking.get(marked);
                while (marked[0]) {
                    snip = pred.nextNonBlocking.compareAndSet(curr, succ, false, false);
                    if (!snip)
                        continue retry;
                    curr = succ;
                    succ = curr.nextNonBlocking.get(marked);
                }
                if (curr.key >= key)
                    return new Window(pred, curr);
                pred = curr;
                curr = succ;
            }
        }
    }

    public void printQueue() {
        RunThreads curr = head.nextNonBlocking.getReference();
        String str = "Thread-" + getID() + ": ";
        while (curr.nextNonBlocking.getReference() != null) {
            str += "(" + curr.person.name + ", " + curr.person.time + "ms), ";
            curr = curr.nextNonBlocking.getReference();
        }
        str = str.substring(0, str.length() - 2);
        System.out.println(str + "\n");
    }

    public int getID() {
        return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
    }

}
