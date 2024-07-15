public class MyThreads extends Thread {

	AtomicMRMW<Integer> registerMRMW;
	AtomicMRSW<Integer> registerMRSW;
	AtomicSRSW<Integer> registerSRSW;

	boolean writer;
	boolean wait;
	String type;

	public MyThreads(AtomicSRSW<Integer> register_, boolean writer, String t, boolean wait) {
		this.registerSRSW = register_;
		this.writer = writer;
		this.type = t;
		this.wait = wait;
	}

	public MyThreads(AtomicMRSW<Integer> register_, boolean writer, String t, boolean wait) {
		this.registerMRSW = register_;
		this.writer = writer;
		this.type = t;
		this.wait = wait;
	}

	public MyThreads(AtomicMRMW<Integer> register_, boolean writer, String t, boolean wait) {
		this.registerMRMW = register_;
		this.writer = writer;
		this.type = t;
		this.wait = wait;
	}

	@Override
	public void run() {
		
		if (wait) {
			try {
				synchronized (this) {
					this.wait(Math.round(Math.random() * 1000));

				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		int randomNumber = generateRandomint(0, 100);
		switch (this.type) {
			case "SRSW":
				SRSW(randomNumber);
				break;

			case "MRSW":
				MRSW(randomNumber);
				break;

			case "MRMW":
				MRMW(randomNumber);
				break;
		}
	}

	public int getID() {
		return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
	}

	public static int generateRandomint(int min, int max) {
		int range = max - min + 1;
		int scaled = (int) (range * Math.random());
		return scaled + min;
	}

	public void SRSW(int randomNumber) {
		if (writer) {
			registerSRSW.write(randomNumber);
			System.out.println("(writer) Thread-" + getID() + " : " + randomNumber);
		} else {

			System.out.println("(reader) Thread-" + getID() + " : " + registerSRSW.read());
		}
	}

	public void MRSW(int randomNumber) {
		if (writer) {
			registerMRSW.write(randomNumber);
			System.out.println("(writer) Thread-" + getID() + " : " + randomNumber);
		} else {

			System.out.println("(reader) Thread-" + getID() + " : " + registerMRSW.read());
		}
	}

	public void MRMW(int randomNumber) {
		if (writer) {
			registerMRMW.write(randomNumber);
			System.out.println("(writer) Thread-" + getID() + " : " + randomNumber);
		} else {

			System.out.println("(reader) Thread-" + getID() + " : " + registerMRMW.read());
		}
	}

}
