import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: Scott Bebington
// Student Number: u21546216

public class Filter implements Lock {

	private volatile int[] level;
	private volatile int[] victim;
	int n;

	public Filter(int n) {
		this.n = n;
		level = new int[n];
		victim = new int[n];
		for (int i = 0; i < n; i++) {
			level[i] = 0;
		}
	}

	public void lock() {
		int me = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
		// int me = ThreadID.get();
		for (int i = 1; i < n; i++) { // attempt level i

			System.out.println("Thread-" + me + ": level[" + me + "] = " + i + " , victim[" + i + "] = " + me);
			level[me] = i;
			victim[i] = me;
			// spin while conflicts exist
			for (int j = 0; j < n; j++) 
			{
				while ((j != me) && (level[j] >= i && victim[i] == me)) {
					// System.out.println("Waiting");
				};
			}
		}
		
		
	}

	public void unlock() {
		int me = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
		level[me] = 0;
		
	}

	public void lockInterruptibly() throws InterruptedException {
		throw new UnsupportedOperationException();
	}

	public boolean tryLock() {
		throw new UnsupportedOperationException();
	}

	public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
		throw new UnsupportedOperationException();
	}

	public Condition newCondition() {
		throw new UnsupportedOperationException();
	}

}
