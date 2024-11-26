/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

import java.util.ArrayList;
import java.util.List;

import javax.persistence.*;
import java.util.*;

/**
 *
 * @author scott
 */
public class DeleteTransaction extends javax.swing.JFrame {

    public boolean verifyActiveTransaction() {

        if (transactionIdText.getText().equals("Select a transaction to view details")
                || transactionDateText.getText().equals("Select a transaction to view details")
                || transactionAmountText.getText().equals("Select a transaction to view details")
                || transactionSenderAccNum.getText().equals("Select a transaction to view details")
                || transactionReceiverAccNum.getText().equals("Select a transaction to view details")) {
            return false;
        }

        return true;

    }

    public void populateList() {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac1.odb");
        EntityManager em = emf.createEntityManager();

        Query q1 = em.createQuery("SELECT t FROM Transaction t");
        @SuppressWarnings("unchecked")
        List<Transaction> results = q1.getResultList();

        em.close();
        emf.close();

        List<Transaction> transactions = new ArrayList<>();

        for (Transaction t : results) {
            transactions.add(t);
        }

        transactionList.setModel(new javax.swing.AbstractListModel<Transaction>() {
            public int getSize() {
                return transactions.size();
            }

            public Transaction getElementAt(int i) {
                return transactions.get(i);
            }
        });
        jScrollPane1.setViewportView(transactionList);
    }

    public void selectTransaction() {

        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac1.odb");
        EntityManager em = emf.createEntityManager();
        Query q1 = em.createQuery("SELECT t FROM Transaction t WHERE t.transactionID = :id");
        try {

            if (searchTransactionInput.getText().equals("Search Transaction by ID")
                    || searchTransactionInput.getText().equals("")) {
                throw new Exception("Please enter a valid transaction ID.");
            }

            String input = searchTransactionInput.getText();
            if (input.matches("\\d+")) {
                long transactionId = Integer.parseInt(input);
                q1.setParameter("id", transactionId);
                Object results = q1.getSingleResult();

                if (results != null) {
                    Transaction t = (Transaction) results;
                    transactionIdText.setText(t.getTransactionID());
                    transactionDateText.setText(t.getTransactionDate());
                    transactionAmountText.setText(String.valueOf(t.getAmount()));
                    transactionSenderAccNum.setText(t.getSenderAccountNumber());
                    transactionReceiverAccNum.setText(t.getReceiverAccountNumber());
                } else {
                    throw new Exception("Transaction not found.");
                }

            } else {
                throw new Exception("Invalid input. Please enter a valid number.");
            }

        } catch (Exception e) {
            Popup popup = new Popup(e.getMessage());
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } finally {
            searchTransactionInput.setText("Search Transaction by ID");
            em.close();
            emf.close();
        }
    }

    public void deleteTransaction() {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/prac1.odb");
        EntityManager em = emf.createEntityManager();
        EntityTransaction transaction = em.getTransaction();

        try {
            transaction.begin();
            Query q1 = em.createQuery("SELECT t FROM Transaction t WHERE t.transactionID = :id");
            long transactionId = Integer.parseInt(transactionIdText.getText());
            q1.setParameter("id", transactionId);
            Object results = q1.getSingleResult();

            if (results != null) {
                Transaction t = (Transaction) results;
                em.remove(t);
                transaction.commit();
                Popup popup = new Popup("Transaction deleted successfully.");
                popup.setLocationRelativeTo(null);
                popup.setVisible(true);
            } else {
                throw new Exception("Transaction not found.");
            }

        } catch (Exception e) {
            transaction.rollback();
            Popup popup = new Popup(e.getMessage());
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } finally {
            em.close();
            emf.close();
        }
    }

    /**
     * Creates new form DeleteTransaction
     */
    public DeleteTransaction() {
        initComponents();
        populateList();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated
    // Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Logo = new javax.swing.JLabel();
        NavigateToDeletePage = new javax.swing.JButton();
        NavigateToUpdatePage = new javax.swing.JButton();
        NavigateToReadPage = new javax.swing.JButton();
        NavigateToCreatePage = new javax.swing.JButton();
        transactionAmountLabel = new javax.swing.JLabel();
        transactionDetailsLabel = new javax.swing.JLabel();
        transactionAmountText = new javax.swing.JLabel();
        transactionsLabel = new javax.swing.JLabel();
        transactionSenderLabel = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        transactionList = new javax.swing.JList<>();
        transactionSenderAccNum = new javax.swing.JLabel();
        transactionReceiverLabel = new javax.swing.JLabel();
        searchTransactionInput = new javax.swing.JTextField();
        transactionReceiverAccNum = new javax.swing.JLabel();
        searchTransactionButton = new javax.swing.JButton();
        transactionIdLabel = new javax.swing.JLabel();
        transactionIdText = new javax.swing.JLabel();
        transactionDateLabel = new javax.swing.JLabel();
        transactionDateText = new javax.swing.JLabel();
        seperator = new javax.swing.JSeparator();
        deleteTransactionButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Logo.setText("FinGuard Solutions");

        NavigateToDeletePage.setText("Delete Transaction");
        NavigateToDeletePage.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                NavigateToDeletePageMouseClicked(evt);
            }
        });

        NavigateToUpdatePage.setText("Update Transaction");
        NavigateToUpdatePage.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                NavigateToUpdatePageMouseClicked(evt);
            }
        });

        NavigateToReadPage.setText("Read Transaction");
        NavigateToReadPage.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                NavigateToReadPageMouseClicked(evt);
            }
        });

        NavigateToCreatePage.setText("Create Transaction");
        NavigateToCreatePage.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                NavigateToCreatePageMouseClicked(evt);
            }
        });

        transactionAmountLabel.setText("Transaction Amount");

        transactionDetailsLabel.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        transactionDetailsLabel.setText("Transaction Details");

        transactionAmountText.setText("Select a transaction to view details");
        transactionAmountText.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 1, true));

        transactionsLabel.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        transactionsLabel.setText("Transactions");

        transactionSenderLabel.setText("Sender Account Number");

        List<Transaction> transactions = new ArrayList<>();

        transactionList.setModel(new javax.swing.AbstractListModel<Transaction>() {
            public int getSize() {
                return transactions.size();
            }

            public Transaction getElementAt(int i) {
                return transactions.get(i);
            }
        });
        transactionList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                transactionListValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(transactionList);

        transactionSenderAccNum.setText("Select a transaction to view details");
        transactionSenderAccNum.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 1, true));

        transactionReceiverLabel.setText("Receiver Account Number");

        searchTransactionInput.setText("Search Transaction by ID");
        searchTransactionInput.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                searchTransactionInputFocusLost(evt);
            }
        });
        searchTransactionInput.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                searchTransactionInputMouseClicked(evt);
            }
        });
        searchTransactionInput.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                searchTransactionInputKeyPressed(evt);
            }
        });

        transactionReceiverAccNum.setText("Select a transaction to view details");
        transactionReceiverAccNum.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 1, true));

        searchTransactionButton.setText("Search");
        searchTransactionButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                searchTransactionButtonMouseClicked(evt);
            }
        });

        transactionIdLabel.setText("Transaction ID");

        transactionIdText.setText("Select a transaction to view details");
        transactionIdText.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 1, true));

        transactionDateLabel.setText("Transaction Date");

        transactionDateText.setText("Select a transaction to view details");
        transactionDateText.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 1, true));

        seperator.setOrientation(javax.swing.SwingConstants.VERTICAL);

        deleteTransactionButton.setText("Delete Transaction");
        deleteTransactionButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                deleteTransactionButtonMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout
                                                .createSequentialGroup()
                                                .addComponent(Logo)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 60,
                                                        Short.MAX_VALUE)
                                                .addComponent(NavigateToCreatePage)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(NavigateToReadPage)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(NavigateToUpdatePage)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(NavigateToDeletePage))
                                        .addGroup(layout.createSequentialGroup()
                                                .addGroup(layout
                                                        .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addComponent(transactionsLabel)
                                                                .addPreferredGap(
                                                                        javax.swing.LayoutStyle.ComponentPlacement.RELATED,
                                                                        javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                        Short.MAX_VALUE))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(
                                                                        javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jScrollPane1)
                                                                        .addGroup(layout.createSequentialGroup()
                                                                                .addComponent(searchTransactionInput,
                                                                                        javax.swing.GroupLayout.PREFERRED_SIZE,
                                                                                        208,
                                                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                                .addPreferredGap(
                                                                                        javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                .addComponent(searchTransactionButton,
                                                                                        javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                        javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                        Short.MAX_VALUE)))
                                                                .addPreferredGap(
                                                                        javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                                                .addComponent(seperator, javax.swing.GroupLayout.PREFERRED_SIZE,
                                                        javax.swing.GroupLayout.DEFAULT_SIZE,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout
                                                        .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addComponent(transactionDetailsLabel,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(
                                                                        javax.swing.GroupLayout.Alignment.LEADING,
                                                                        false)
                                                                        .addComponent(transactionSenderLabel)
                                                                        .addComponent(transactionIdLabel)
                                                                        .addComponent(transactionDateLabel)
                                                                        .addComponent(transactionAmountLabel)
                                                                        .addComponent(transactionAmountText,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(transactionReceiverLabel)
                                                                        .addComponent(transactionSenderAccNum,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(transactionReceiverAccNum,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(transactionIdText,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(transactionDateText,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                382, Short.MAX_VALUE)
                                                                        .addComponent(deleteTransactionButton,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE))
                                                                .addGap(0, 0, Short.MAX_VALUE)))))
                                .addContainerGap()));
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(NavigateToDeletePage)
                                        .addComponent(NavigateToUpdatePage)
                                        .addComponent(NavigateToReadPage)
                                        .addComponent(NavigateToCreatePage)
                                        .addComponent(Logo))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(seperator)
                                        .addGroup(layout.createSequentialGroup()
                                                .addComponent(transactionsLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout
                                                        .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING,
                                                                false)
                                                        .addComponent(searchTransactionButton,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                        .addComponent(searchTransactionInput,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE, 31,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 391,
                                                        Short.MAX_VALUE))
                                        .addGroup(layout.createSequentialGroup()
                                                .addComponent(transactionDetailsLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(transactionIdLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(transactionIdText, javax.swing.GroupLayout.PREFERRED_SIZE,
                                                        30, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(transactionDateLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(transactionDateText,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(transactionAmountLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(transactionAmountText,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(transactionSenderLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(transactionSenderAccNum,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(transactionReceiverLabel)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(transactionReceiverAccNum,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(deleteTransactionButton,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 31,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(0, 0, Short.MAX_VALUE)))
                                .addContainerGap()));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void transactionListValueChanged(javax.swing.event.ListSelectionEvent evt) {// GEN-FIRST:event_transactionListValueChanged
        Transaction selectedTransaction = transactionList.getSelectedValue();
        if (selectedTransaction != null) {
            transactionIdText.setText(selectedTransaction.getTransactionID());
            transactionDateText.setText(selectedTransaction.getTransactionDate());
            transactionAmountText.setText(String.valueOf(selectedTransaction.getAmount()));
            transactionSenderAccNum.setText(selectedTransaction.getSenderAccountNumber());
            transactionReceiverAccNum.setText(selectedTransaction.getReceiverAccountNumber());
        }
    }// GEN-LAST:event_transactionListValueChanged

    private void searchTransactionInputFocusLost(java.awt.event.FocusEvent evt) {// GEN-FIRST:event_searchTransactionInputFocusLost
        if (searchTransactionInput.getText().equals("")) {
            searchTransactionInput.setText("Search Transaction by ID");
        }
    }// GEN-LAST:event_searchTransactionInputFocusLost

    private void searchTransactionInputMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_searchTransactionInputMouseClicked
        if (searchTransactionInput.getText().equals("Search Transaction by ID")) {
            searchTransactionInput.setText("");
        }
    }// GEN-LAST:event_searchTransactionInputMouseClicked

    private void searchTransactionInputKeyPressed(java.awt.event.KeyEvent evt) {// GEN-FIRST:event_searchTransactionInputKeyPressed
        if (evt.getKeyCode() == 10) {
            selectTransaction();
        }
    }// GEN-LAST:event_searchTransactionInputKeyPressed

    private void searchTransactionButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_searchTransactionButtonMouseClicked
        selectTransaction();
    }// GEN-LAST:event_searchTransactionButtonMouseClicked

    private void deleteTransactionButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_deleteTransactionButtonMouseClicked
        if (!verifyActiveTransaction()) {
            Popup popup = new Popup("Please select a transaction to delete.");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
            return;
        }
        
        deleteTransaction();
        populateList();
    }// GEN-LAST:event_deleteTransactionButtonMouseClicked

    private void NavigateToCreatePageMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_NavigateToCreatePageMouseClicked
        System.out.println("Navigating to Create Transaction");
        this.dispose();
        CreateTransaction createTransaction = new CreateTransaction();
        createTransaction.setLocationRelativeTo(null);
        createTransaction.setVisible(true);
    }// GEN-LAST:event_NavigateToCreatePageMouseClicked

    private void NavigateToReadPageMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_NavigateToReadPageMouseClicked
        System.out.println("Navigating to Read Transaction");
        this.dispose();
        ReadTransaction readTransaction = new ReadTransaction();
        readTransaction.setLocationRelativeTo(null);
        readTransaction.setVisible(true);
    }// GEN-LAST:event_NavigateToReadPageMouseClicked

    private void NavigateToUpdatePageMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_NavigateToUpdatePageMouseClicked
        System.out.println("Navigating to Update Transaction");
        this.dispose();
        UpdateTransaction updateTransaction = new UpdateTransaction();
        updateTransaction.setLocationRelativeTo(null);
        updateTransaction.setVisible(true);
    }// GEN-LAST:event_NavigateToUpdatePageMouseClicked

    private void NavigateToDeletePageMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_NavigateToDeletePageMouseClicked
        System.out.println("Navigating to Delete Transaction");
        this.dispose();
        DeleteTransaction deleteTransaction = new DeleteTransaction();
        deleteTransaction.setLocationRelativeTo(null);
        deleteTransaction.setVisible(true);
    }// GEN-LAST:event_NavigateToDeletePageMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        // <editor-fold defaultstate="collapsed" desc=" Look and feel setting code
        // (optional) ">
        /*
         * If Nimbus (introduced in Java SE 6) is not available, stay with the default
         * look and feel.
         * For details see
         * http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(DeleteTransaction.class.getName()).log(java.util.logging.Level.SEVERE,
                    null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(DeleteTransaction.class.getName()).log(java.util.logging.Level.SEVERE,
                    null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(DeleteTransaction.class.getName()).log(java.util.logging.Level.SEVERE,
                    null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(DeleteTransaction.class.getName()).log(java.util.logging.Level.SEVERE,
                    null, ex);
        }
        // </editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new DeleteTransaction().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Logo;
    private javax.swing.JButton NavigateToCreatePage;
    private javax.swing.JButton NavigateToDeletePage;
    private javax.swing.JButton NavigateToReadPage;
    private javax.swing.JButton NavigateToUpdatePage;
    private javax.swing.JButton deleteTransactionButton;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton searchTransactionButton;
    private javax.swing.JTextField searchTransactionInput;
    private javax.swing.JSeparator seperator;
    private javax.swing.JLabel transactionAmountLabel;
    private javax.swing.JLabel transactionAmountText;
    private javax.swing.JLabel transactionDateLabel;
    private javax.swing.JLabel transactionDateText;
    private javax.swing.JLabel transactionDetailsLabel;
    private javax.swing.JLabel transactionIdLabel;
    private javax.swing.JLabel transactionIdText;
    private javax.swing.JList<Transaction> transactionList;
    private javax.swing.JLabel transactionReceiverAccNum;
    private javax.swing.JLabel transactionReceiverLabel;
    private javax.swing.JLabel transactionSenderAccNum;
    private javax.swing.JLabel transactionSenderLabel;
    private javax.swing.JLabel transactionsLabel;
    // End of variables declaration//GEN-END:variables
}
