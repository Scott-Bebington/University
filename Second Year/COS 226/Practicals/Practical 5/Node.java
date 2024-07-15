import java.util.concurrent.atomic.AtomicMarkableReference;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Node extends Thread {

	public Person person;
	public int key;
	public RunThreads next;
	boolean marked = false;
	public Lock l = new ReentrantLock(true);
	public AtomicMarkableReference<RunThreads> nextNonBlocking;


	Node(int i) {
		key = i;
		next = null;
        nextNonBlocking = new AtomicMarkableReference<>(null, false);
	}

	Node(Person person) {
		this.person = person;
		key = person.hashCode();
		next = null;        
		nextNonBlocking = new AtomicMarkableReference<>(null, false);
	}
}
