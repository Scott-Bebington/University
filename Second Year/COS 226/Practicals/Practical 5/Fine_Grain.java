public class Fine_Grain implements ListInterface {

    public RunThreads head;

    public RunThreads getHead() {
        return head;
    }

    public Fine_Grain() {
        head = new RunThreads(Integer.MIN_VALUE);
        head.next = new RunThreads(Integer.MAX_VALUE);
    }

    // @suppressWarnings("unchecked")
    public boolean add(JobDetails person) {
        // System.out.println("Adding " + person.name);
        int key = person.hashCode();
        head.l.lock();
        RunThreads pred = head;
        try {
            RunThreads curr = pred.next;
            curr.l.lock();
            try {
                while (curr.key < key) {
                    pred.l.unlock();
                    pred = curr;
                    curr = curr.next;
                    curr.l.lock();
                }
                if (curr.key == key) {
                    return false;
                }
                RunThreads newNode = new RunThreads(person);
                newNode.next = curr;
                pred.next = newNode;
                return true;
            } finally {
                curr.l.unlock();
            }
        } finally {
            pred.l.unlock();
        }
    }

    public boolean remove(JobDetails person) {
        // System.out.println("Removing " + person.name);
        RunThreads pred = null, curr = null;
        int key = person.hashCode();
        head.l.lock();
        try {
            pred = head;
            curr = pred.next;
            curr.l.lock();
            try {
                while (curr.key < key) {
                    pred.l.unlock();
                    pred = curr;
                    curr = curr.next;
                    curr.l.lock();
                }
                if (curr.key == key) {
                    pred.next = curr.next;
                    return true;
                }
                return false;
            } finally {
                curr.l.unlock();
            }
        } finally {
            pred.l.unlock();
        }
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
