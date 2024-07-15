public class Info {

    public int ThreadID;
    public String ClientName;
    public boolean reader;

    public Info(int ThreadID_, String ClientName_, boolean reader_) {
        this.ThreadID = ThreadID_;
        this.ClientName = ClientName_;
        this.reader = reader_;
    }

    public void threadToString() {
        System.out.println("Thread ID: " + ThreadID + " Client Name: " + ClientName + " Reader: " + reader);
    }

}
