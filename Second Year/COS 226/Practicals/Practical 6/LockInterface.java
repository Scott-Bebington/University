public interface LockInterface {
    public void enqueue(JobDetails value);
    public JobDetails dequeue() throws Exception;
}
