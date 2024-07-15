import java.util.concurrent.locks.Lock;

public class Printer {
    Lock l;

	public Printer(Lock l) {
		this.l = l;
	}

	public void Print(int i) {
		if (!l.tryLock())
		{
			System.out.println("Thread-" + getID() + ": Timed Out");
			// l.unlock();
			return;
		}
		// l.lock();
		try 
		{
			String greenColor = "\u001B[32m";
        	String resetColor = "\u001B[0m";
			long random = generateRandomLong(200, 1000);
			Thread.sleep(random);
			// System.out.println("Slept for: " + random + "ms");
			System.out.println(greenColor + "Thread-" + getID() + ": Request " + i + " printing [Random message]" + resetColor);
		} 
		catch (Exception e) 
		{
			System.out.println(e.getMessage());
		}
		finally
		{
			l.unlock();
		}
	}

	public int getID() {
		return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
	}
	
	public static long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }
}
