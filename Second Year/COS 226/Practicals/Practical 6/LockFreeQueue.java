
import java.util.concurrent.atomic.AtomicReference;

public class LockFreeQueue implements LockInterface {
    private AtomicReference<Node<JobDetails>> head;
    private AtomicReference<Node<JobDetails>> tail;

    public LockFreeQueue() {
        Node<JobDetails> sentinel = new Node<>(null);
        head = new AtomicReference<>(sentinel);
        tail = new AtomicReference<>(sentinel);
    }

    public void enqueue(JobDetails value) {
        Node<JobDetails> newNode = new Node<>(value);
        while (true) {
            Node<JobDetails> currentTail = tail.get();
            Node<JobDetails> tailNext = currentTail.next.get();
            if (currentTail == tail.get()) {
                if (tailNext == null) {
                    if (currentTail.next.compareAndSet(null, newNode)) {
                        tail.compareAndSet(currentTail, newNode);
                        return;
                    }
                } else {
                    tail.compareAndSet(currentTail, tailNext);
                }
            }
        }
    }

    public JobDetails dequeue() throws Exception {
        while (true) {
            Node<JobDetails> first = head.get();
            Node<JobDetails> last = tail.get();
            Node<JobDetails> next = first.next.get();
            if (first == head.get()) {
                if (first == last) {
                    if (next == null) {
                        throw new Exception("Queue is empty");
                    }
                    tail.compareAndSet(last, next);
                } else {
                    JobDetails value = next.value;
                    if (head.compareAndSet(first, next)) {
                        return value;
                    }
                }
            }
        }
    }
    

    
    private static class Node<T> {
        private T value;
        private AtomicReference<Node<T>> next;

        public Node(T value) {
            this.value = value;
            next = new AtomicReference<>(null);
        }
    }
}