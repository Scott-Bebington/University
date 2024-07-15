public class Lazy implements ListInterface {

    RunThreads head;

    public RunThreads getHead() {
        return head;
    }

    public Lazy() {
        head = new RunThreads(Integer.MIN_VALUE);
        head.next = new RunThreads(Integer.MAX_VALUE);
    }

    public boolean add(JobDetails item) {
        int key = item.hashCode();
        while (true) {
            RunThreads pred = head;
            RunThreads curr = head.next;
            while (curr.key < key) {
                pred = curr;
                curr = curr.next;
            }
            pred.l.lock();
            try {
                curr.l.lock();
                try {
                    if (validate(pred, curr)) {
                        if (curr.key == key) {
                            return false;
                        } else {
                            RunThreads node = new RunThreads(item);
                            node.next = curr;
                            pred.next = node;
                            return true;
                        }
                    }
                } finally {
                    curr.l.unlock();
                }
            } finally {
                pred.l.unlock();
            }
        }
    }
    
    public boolean remove(JobDetails item) {
        int key = item.hashCode();
        while (true) {
            RunThreads pred = head;
            RunThreads curr = head.next;
            while (curr.key < key) {
                pred = curr;
                curr = curr.next;
            }
            pred.l.lock();
            try {
                curr.l.lock();
                try {
                    if (validate(pred, curr)) {
                        if (curr.key != key) {
                            return false;
                        } else {
                            curr.marked = true;
                            pred.next = curr.next;
                            return true;
                        }
                    }
                } finally {
                    curr.l.unlock();
                }
            } finally {
                pred.l.unlock();
            }
        }
    }
    
    public boolean contains(JobDetails item) {
        int key = item.hashCode();
        RunThreads curr = head;
        while (curr.key < key)
            curr = curr.next;
        return curr.key == key && !curr.marked;
    }

    private boolean validate(RunThreads pred, RunThreads curr) {
        RunThreads node = head;
        while (node.key <= pred.key) {
            if (node == pred)
                return pred.next == curr;
            node = node.next;
        }
        return false;
    }  
    
    public void printQueue() {
        RunThreads curr = head.next;
        String str = "Thread-" + getID() + ": ";
        while (curr.next != null) {
            str += "(" + curr.person.name + ", " + curr.person.time + "ms), ";
            curr = curr.next;
        }
        str = str.substring(0, str.length() - 2);
        System.out.println(str + "\n");
    }

    public int getID() {
        return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
    }

}
