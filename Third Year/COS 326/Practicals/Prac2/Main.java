/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

import java.time.LocalDate;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;

/**
 *
 * @author scott
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac2.odb");

        EntityManager em = emf.createEntityManager();

        try {
            Query q1 = em.createQuery("SELECT b FROM BankAccount b");
            System.out.println(q1.getResultList());
        } catch (Exception e) {
            System.out.println("No bank accounts found");
        }

        try {
            Query q2 = em.createQuery("SELECT t FROM Transaction t");
            System.out.println(q2.getResultList());
        } catch (Exception e) {
            System.out.println("No transactions found");
        }

        em.close();
        emf.close();
    }
}

class DBTransactions {

    public boolean isDateFormatted(String inTransactionDate) {
        return inTransactionDate.matches("\\d{2}/\\d{2}/\\d{4}");
    }

    public boolean isDateValid(String inTransactionDate) {
        if (!isDateFormatted(inTransactionDate)) {
            return false;
        }

        String[] dateParts = inTransactionDate.split("/");
        int day = Integer.parseInt(dateParts[0]);
        int month = Integer.parseInt(dateParts[1]);
        int year = Integer.parseInt(dateParts[2]);

        if (month < 1 || month > 12) {
            return false;
        }

        if (day < 1 || day > 31) {
            return false;
        }

        LocalDate currentDate = LocalDate.now();
        LocalDate localTransactionDate = LocalDate.of(year, month, day);
        if (localTransactionDate.isAfter(currentDate)) {
            return false;
        }

        return true;
    }

    public void storeTransaction(String accountNumber, String accountHolderName,
            String transactionDate, double amount,
            String senderAccountNumber, String receiverAccountNumber,
            String transactionType) {

        if (accountNumber == null || accountNumber.isEmpty()
                || accountNumber.equals("Enter your bank account number")) {
            throw new IllegalArgumentException("Account number cannot be null or empty");
        }

        if (accountHolderName == null || accountHolderName.isEmpty()
                || accountHolderName.equals("Enter your full name")) {
            throw new IllegalArgumentException("Account holder name cannot be null or empty");
        }

        if (transactionDate == null || transactionDate.isEmpty() || transactionDate.equals("dd/mm/yyyy")) {
            throw new IllegalArgumentException("Transaction date cannot be null or empty");
        }

        if (!isDateValid(transactionDate)) {
            throw new IllegalArgumentException("Transaction date is not valid");
        }

        if (amount <= 0) {
            throw new IllegalArgumentException("Amount must be greater than zero");
        }

        if (senderAccountNumber == null || senderAccountNumber.isEmpty()) {
            throw new IllegalArgumentException("Sender account number cannot be null or empty");
        }

        if (receiverAccountNumber == null || receiverAccountNumber.isEmpty()) {
            throw new IllegalArgumentException("Receiver account number cannot be null or empty");
        }

        if (transactionType == null || transactionType.isEmpty() || transactionType.equals("Choose transaction type")) {
            throw new IllegalArgumentException("Transaction type cannot be null or empty");
        }

        if (senderAccountNumber.equals(receiverAccountNumber)) {
            throw new IllegalArgumentException("Sender and receiver account numbers cannot be the same");
        }

        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac2.odb");

        EntityManager em = emf.createEntityManager();

        try {
            em.getTransaction().begin();

            // Step 1: Retrieve or create the associated BankAccount
            BankAccount bankAccount = em
                    .createQuery("SELECT b FROM BankAccount b WHERE b.accountNumber = :accountNumber",
                            BankAccount.class)
                    .setParameter("accountNumber", accountNumber)
                    .getResultList()
                    .stream()
                    .findFirst()
                    .orElse(new BankAccount(accountNumber, accountHolderName));

            // If the BankAccount is new, persist it
            if (bankAccount.getId() == null) {
                em.persist(bankAccount);
            }

            // Step 2: Create the Transaction object
            Transaction transaction = new Transaction(transactionDate, amount, senderAccountNumber,
                    receiverAccountNumber, transactionType, bankAccount);

            // Step 3: Persist the Transaction
            em.persist(transaction);

            em.getTransaction().commit();
        } catch (Exception e) {
            if (em.getTransaction().isActive()) {
                em.getTransaction().rollback();
            }
            
        } finally {
            em.close();
            emf.close();
        }
    }

    @SuppressWarnings("unchecked")
    public List<BankAccount> readBankAccounts() {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac2.odb");

        EntityManager em = emf.createEntityManager();

        List<BankAccount> bankAccounts = null;

        try {
            Query query = em.createQuery("SELECT b FROM BankAccount b");
            bankAccounts = query.getResultList();

            if (bankAccounts.isEmpty()) {
                throw new IllegalArgumentException("No bank accounts found");
            }
        } catch (Exception e) {

            Popup popup = new Popup("No bank accounts found");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } finally {
            em.close();
            emf.close();
        }

        return bankAccounts;
    }

    public BankAccount searchBankAccount(String accountNumber) {

        if (accountNumber == null || accountNumber.isEmpty()) {
            System.out.println("Account number cannot be null or empty");
            throw new IllegalArgumentException("Account number cannot be null or empty");
        }

        if (accountNumber.equals("Enter account number")) {
            System.out.println("Please enter a valid account number");
            throw new IllegalArgumentException("Please enter a valid account number");
        }

        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac2.odb");

        EntityManager em = emf.createEntityManager();

        BankAccount bankAccount = null;

        try {
            bankAccount = em
                    .createQuery("SELECT b FROM BankAccount b WHERE b.accountNumber = :accountNumber",
                            BankAccount.class)
                    .setParameter("accountNumber", accountNumber)
                    .getSingleResult();
        } catch (IllegalArgumentException e) {
            Popup popup = new Popup(e.getMessage());
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (javax.persistence.NoResultException e) {
            Popup popup = new Popup("Bank account not found");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (Exception e) {
            Popup popup = new Popup("Bank account not found");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } finally {
            System.out.println("Closing EntityManager");
            em.close();
            emf.close();
        }

        return bankAccount;
    }

    public boolean deleteBankAccount(String accountNumber) {
        if (accountNumber == null || accountNumber.isEmpty()) {
            throw new IllegalArgumentException("Account number cannot be null or empty");
        }

        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac2.odb");

        EntityManager em = emf.createEntityManager();

        try {
            em.getTransaction().begin();

            BankAccount bankAccount = em
                    .createQuery("SELECT b FROM BankAccount b WHERE b.accountNumber = :accountNumber",
                            BankAccount.class)
                    .setParameter("accountNumber", accountNumber)
                    .getSingleResult();

            em.remove(bankAccount);

            em.getTransaction().commit();
        } catch (Exception e) {
            if (em.getTransaction().isActive()) {
                em.getTransaction().rollback();
            }
            return false;
        } finally {
            em.close();
            emf.close();
        }

        return true;
    }
}