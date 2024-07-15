public class Node extends Thread {

    private Printer p;
	volatile boolean locked = false;
	volatile Node next = null;
	volatile Node prev = null;
	String threadname = "";
	int count = 1;

	Node() {}

	Node(Printer _p)
	{
		this.p = _p;
	}

	@Override
	public void run()
	{
		for (int i = 1; i <= 5; i++) 
		{
			System.out.println("Thread-" + getID() + ": Request " + (i) + " printing request");
			p.Print(i);
		}
	}

	public int getID() {
		return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
	}
}
