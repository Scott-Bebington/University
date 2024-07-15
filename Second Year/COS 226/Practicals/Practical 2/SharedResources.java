import java.util.concurrent.locks.Lock;

public class SharedResources {
    Lock l;

	public SharedResources(Lock l) {
		this.l = l;
	}

	public void access(){
		l.lock();
		try
		{
			try
			{
				long random = generateRandomLong(200, 1000);
				Thread.sleep(random);
			}
			catch(Exception e)
			{
				System.out.println("Error: " + e.getMessage());
			}
		}
		finally
		{
			System.out.println(Thread.currentThread().getName() + ":-----------------------DONE");
			l.unlock();
		}
	}

	public static long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }
}
