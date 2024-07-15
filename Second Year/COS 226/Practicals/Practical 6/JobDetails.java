public class JobDetails {
    String ThreadName;
    int JobNumber;
    long JobTime;

    public JobDetails(int JobNumber, long JobTime) {
        this.JobNumber = JobNumber;
        this.JobTime = JobTime;
    }

    public void setThreadName(String ThreadName) {
        this.ThreadName = ThreadName;
    }

    public void printDetails(String inOut, String acceptedRejected) {
        String str = "(" + inOut + ") [" + getThreadName()  + "] [Job Number: " + JobNumber + "] [Job Time: " + JobTime + "]";
        if (acceptedRejected != null) {
            str += " [" + acceptedRejected + "]";
        }
        System.out.println(str);
    }

    public String getThreadName() {
        return Thread.currentThread().getName();
    }
}
