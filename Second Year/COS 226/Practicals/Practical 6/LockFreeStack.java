import java.util.concurrent.atomic.AtomicReference;

public class LockFreeStack implements LockInterface {
    private AtomicReference<Node<JobDetails>> head = new AtomicReference<>();

    public void enqueue(JobDetails value) {
        Node<JobDetails> newNode = new Node<>(value);
        Node<JobDetails> oldHead;
        do {
            oldHead = head.get();
            newNode.next = oldHead;
        } while (!head.compareAndSet(oldHead, newNode));
    }

    public JobDetails dequeue() throws Exception {
        Node<JobDetails> oldHead;
        Node<JobDetails> newHead;
        do {
            oldHead = head.get();
            if (oldHead == null) {
                throw new Exception("Queue is empty");
            }
            newHead = oldHead.next;
        } while (!head.compareAndSet(oldHead, newHead));
        return oldHead.value;
    }

    private static class Node<T> {
        private final JobDetails value;
        private Node<T> next;

        private Node(JobDetails value) {
            this.value = value;
        }
    }
}
