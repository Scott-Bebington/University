public class Optimistic implements ListInterface {

    RunThreads head;

    public RunThreads getHead() {
        return head;
    }

    public Optimistic() {
        head = new RunThreads(Integer.MIN_VALUE);
        head.next = new RunThreads(Integer.MAX_VALUE);
    }

    public boolean add(JobDetails person) {
        // System.out.println("Adding " + person.name);
        int key = person.hashCode();
        // System.out.println("Key: " + key);
        while (true) {
            RunThreads pred = head;
            RunThreads curr = pred.next;
            while (curr.key < key) {
                pred = curr;
                curr = curr.next;
            }
            pred.l.lock();
            curr.l.lock();
            try {
                if (validate(pred, curr)) {
                    if (curr.key == key) {
                        // System.out.println("Already in the list");
                        return false;
                    } else {
                        RunThreads node = new RunThreads(person);
                        node.next = curr;
                        pred.next = node;
                        // System.out.println("Added " + person.name);
                        return true;
                    }
                }
            } finally {
                pred.l.unlock();
                curr.l.unlock();
            }
        }
    }

    public boolean remove(JobDetails person) {
        // System.out.println("Removing " + person.name);
        int key = person.hashCode();
        while (true) {
            RunThreads pred = head;
            RunThreads curr = pred.next;
            while (curr.key < key) {
                pred = curr;
                curr = curr.next;
            }
            pred.l.lock();
            curr.l.lock();
            try {
                if (validate(pred, curr)) {
                    if (curr.key == key) {
                        pred.next = curr.next;
                        return true;
                    } else {
                        return false;
                    }
                }
            } finally {
                pred.l.unlock();
                curr.l.unlock();
            }
        }
    }

    public boolean contains(JobDetails person) {
        int key = person.hashCode();
        while (true) {
            RunThreads pred = this.head; // sentinel node;
            RunThreads curr = pred.next;
            while (curr.key < key) {
                pred = curr;
                curr = curr.next;
            }
            pred.l.lock();
            curr.l.lock();
            try {
                if (validate(pred, curr)) {
                    return (curr.key == key);
                }
            } finally { // always.l.unlock
                pred.l.unlock();
                curr.l.unlock();
            }
        }
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
