/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import java.time.LocalDate;
import java.io.Serializable;
import javax.persistence.*;

/**
 *
 * @author Scott Bebington - u21546216
 * private String transactionID;
 * private String transactionDate;
 * private double amount;
 * private String senderAccountNumber;
 * private String receiverAccountNumber;
 * private String transactionType;
 */

@Entity
public class Transaction implements Serializable {

    //The serialVersionUID is a universal version identifier for a Serializable class
    private static final long serialVersionUID = 1L;
    //This annotation specifies the primary key of the entity
    @Id
    //generate primary key value automatically
    @GeneratedValue
    private long transactionID;

    private String transactionDate;
    private double amount;
    private String senderAccountNumber;
    private String receiverAccountNumber;
    private String transactionType;

    public Transaction(String transactionDate, double amount, String senderAccountNumber, String receiverAccountNumber, String transactionType) {
        this.transactionDate = transactionDate;
        this.amount = amount;
        this.senderAccountNumber = senderAccountNumber;
        this.receiverAccountNumber = receiverAccountNumber;
        this.transactionType = transactionType;
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
            || transactionType.equals("None selected")
        ) {
            return false;
        } 
        
        return true;
    }

    public boolean isDateFormatted() {
        return transactionDate.matches("\\d{2}/\\d{2}/\\d{4}");
    }
    
    public boolean isDateValid() {
        // Check if the date is in the correct format
        if (!isDateFormatted()) {
            return false;
        }
        
        // Split the date into day, month, and year
        String[] dateParts = transactionDate.split("/");
        int day = Integer.parseInt(dateParts[0]);
        int month = Integer.parseInt(dateParts[1]);
        int year = Integer.parseInt(dateParts[2]);
        
        // Check if the month is valid
        if (month < 1 || month > 12) {
            return false;
        }
        
        // Check if the day is valid
        if (day < 1 || day > 31) {
            return false;
        }
        
        // Check if the date is not more than today
        LocalDate currentDate = LocalDate.now();
        LocalDate transactionDate = LocalDate.of(year, month, day);
        if (transactionDate.isAfter(currentDate)) {
            return false;
        }
        
        return true;
    }
}
