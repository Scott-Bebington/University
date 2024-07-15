public class RunThreads extends Thread {

    public Server serve;
    public static boolean Done = false;

    RunThreads() {
    }

    RunThreads(Server s) {
        this.serve = s;
    }

    @Override
    public void run() {
        if (getThreadName().split("-")[0].equals("Dev")) {
            for (int i = 0; i < 3; i++) {
                serve.sheduleJob();
            }
            if(Done)
                return;
            else if (Server.jobCount == 12) {
                // System.out.println("Setting Done to true");
                Done = true;
            }
            return;
        }
        while(!Done || Server.jobCountRemoved != 0) {
            // System.out.println("Thread Name: " + getThreadName());
            serve.desheduleJob();
            // System.out.println("JobCount: " + Server.jobCount + " JobCountRemoved: " + Server.jobCountRemoved);
        }
    }

    private String getThreadName() {
        return Thread.currentThread().getName();
    }
}
