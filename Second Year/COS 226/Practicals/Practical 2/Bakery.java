import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: Scott Bebington
// Student Number: u21546216

public class Bakery implements Lock {

	private volatile boolean[] flag;
	private volatile int[] label;
	private int n; // number of threads

	public Bakery(int n) {
		this.n = n;
		flag = new boolean[n]; // a flag to determinne which threads are interested in accessing the critical section
		label = new int[n];
		for (int i = 0; i < n; i++) {
			flag[i] = false;
			label[i] = 0;
		}
	}

	public void lock() {
		int i = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
		flag[i] = true;
		int max = label[0];
		for (int z = 1; z < label.length; z++) {
			if (label[z] > max) {
				max = label[z];
			}
		}
		// label[i] = getMax() + 1; // makes them wait in line
		label[i] = max + 1; // makes them wait in line

		System.out.println(Thread.currentThread().getName() + ": flag[" + i + "] = " + flag[i] + " , label[" + i + "] = " + (label[i]));

		// n = number of threads
		// i = current thread's id
		for (int k = 0; k < n; k++) {
			while ((k != i) && (flag[k] && (label[k]) <= (label[i]) && k < i)) {};
		}
	}

	public void unlock() {
		flag[Integer.parseInt(Thread.currentThread().getName().split("-")[1])] = false;
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
