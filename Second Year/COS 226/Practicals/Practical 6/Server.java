public class Server {

    LockInterface l;
    public static int jobCount = 0;
    public static int jobCountRemoved = 0;

    String greenColorCode = "\u001B[32m";
    String redColorCode = "\u001B[31m";
    String resetColorCode = "\u001B[0m";

    public Server(LockInterface l) {
        this.l = l;
    }

    public void sheduleJob() {
        try {
            JobDetails job = new JobDetails(jobCount++, generateRandomLong(1, 24));
            jobCountRemoved++;
            job.setThreadName(getThreadName());
            job.printDetails("IN", null);
            l.enqueue(job);
            Thread.sleep(generateRandomLong(100, 200));
        } catch (Exception e) {
            System.out.println(redColorCode + "Error: " + e.getMessage() + resetColorCode);
        }
    }

    public void desheduleJob() {
        if(jobCount != 0) {
            try {
                JobDetails job = l.dequeue();
                jobCountRemoved--;

                long time = generateRandomLong(1, 24);
                String acceptedRejected = null;
                if(job.JobTime >= time) {
                    acceptedRejected = greenColorCode + "Accepted" + resetColorCode;
                } else {
                    acceptedRejected = redColorCode + "Rejected" + resetColorCode;
                }

                job.printDetails("OUT", acceptedRejected);
                Thread.sleep(generateRandomLong(100, 200));
            } catch (Exception e) {
                if(!e.getMessage().equals("Queue is empty"))
                    System.out.println(redColorCode + "Error: " + e.getMessage() + resetColorCode);
            }
        }
    }

    public static long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }

    public String getThreadName() {
        return Thread.currentThread().getName();
    }
}