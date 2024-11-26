

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;

/**
 *
 * @author Scott Bebington - u21546216
 */

@Entity
public class Transaction implements Serializable {

    private static final long serialVersionUID = 1L;

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private long transactionID;

    private String transactionDate;
    private double amount;
    private String senderAccountNumber;
    private String receiverAccountNumber;
    private String transactionType;

    @ManyToOne
    @JoinColumn(name = "bank_account_id")
    private BankAccount bankAccount;

    public Transaction(String transactionDate, double amount, String senderAccountNumber, String receiverAccountNumber,
                       String transactionType, BankAccount bankAccount) {
        this.transactionDate = transactionDate;
        this.amount = amount;
        this.senderAccountNumber = senderAccountNumber;
        this.receiverAccountNumber = receiverAccountNumber;
        this.transactionType = transactionType;
        this.bankAccount = bankAccount;
    }

    public String getTransactionID() {
        return transactionID + "";
    }

    public String getTransactionDate() {
        return transactionDate;
    }

    public void setTransactionDate(String transactionDate) {
        this.transactionDate = transactionDate;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getSenderAccountNumber() {
        return senderAccountNumber;
    }

    public void setSenderAccountNumber(String senderAccountNumber) {
        this.senderAccountNumber = senderAccountNumber;
    }

    public String getReceiverAccountNumber() {
        return receiverAccountNumber;
    }

    public void setReceiverAccountNumber(String receiverAccountNumber) {
        this.receiverAccountNumber = receiverAccountNumber;
    }

    public String getTransactionType() {
        return transactionType;
    }

    public void setTransactionType(String transactionType) {
        this.transactionType = transactionType;
    }

    public BankAccount getBankAccount() {
        return bankAccount;
    }

    public void setBankAccount(BankAccount bankAccount) {
        this.bankAccount = bankAccount;
    }

    @Override
    public String toString() {
        return "ID: " + transactionID + ", Date: " + transactionDate;
    }

    public boolean checkTransactionDetails() {
        if (transactionDate.isEmpty()
                || transactionDate.equals("dd/mm/yyyy")
                || amount == 0
                || senderAccountNumber.isEmpty()
                || receiverAccountNumber.isEmpty()
                || transactionType.isEmpty()
                || transactionType.equals("None selected")) {
            return false;
        }

        return true;
    }

    
}
