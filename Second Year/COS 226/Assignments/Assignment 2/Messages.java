public class Messages {
    public String MessageString;
    public String Sender;
    public String Receiver;
    public int ThreadID;

    public Messages(String MessageStr_, String Sender_, String Receiver_, int ThreadID_){
        this.MessageString = MessageStr_;
        this.Sender = Sender_;
        this.Receiver = Receiver_;
        this.ThreadID = ThreadID_;
    }
}
