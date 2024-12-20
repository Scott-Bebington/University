/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

// import java.time.LocalDate;
// import java.util.List;

// import javax.persistence.EntityManager;
// import javax.persistence.EntityManagerFactory;
// import javax.persistence.Persistence;
// import javax.persistence.Query;

/**
 *
 * @author scott
 */
public class Store extends javax.swing.JFrame {

    // Main prac2 = new Main();
    DBTransactions dbTransactions = new DBTransactions();

    /**
     * Creates new form Store
     */
    public Store() {
        initComponents();
        selectBankAccountDropdown.removeAllItems();
        for (BankAccount bankAccount : dbTransactions.readBankAccounts()) {
            selectBankAccountDropdown.addItem(bankAccount);
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        deleteNavbarButton = new javax.swing.JButton();
        readNavbarButton = new javax.swing.JButton();
        storeNavbarButton = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        transactionTypeLabel = new javax.swing.JLabel();
        transactionTypeValue = new javax.swing.JLabel();
        transactionDateLabel = new javax.swing.JLabel();
        saveButton = new javax.swing.JButton();
        transactionDateInput = new javax.swing.JTextField();
        selectBankAccountDropdown = new javax.swing.JComboBox<>();
        transactionAmountLabel = new javax.swing.JLabel();
        chooseExistingBankAccountLabel = new javax.swing.JLabel();
        transactionAmountInput = new javax.swing.JTextField();
        orLabel = new javax.swing.JLabel();
        transactionSenderBankAccNumLabel = new javax.swing.JLabel();
        myNameInput = new javax.swing.JTextField();
        senderAccountNumValue = new javax.swing.JLabel();
        myNameLabel = new javax.swing.JLabel();
        receiverAccNumLabel = new javax.swing.JLabel();
        myBankAccountNumberInput = new javax.swing.JTextField();
        receiverAccountNumInput = new javax.swing.JTextField();
        myBankAccountNumberLabel = new javax.swing.JLabel();
        bankAccountDetailsLabel = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        transactionTypeList = new javax.swing.JList<>();
        transactionDetailsLabel = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        deleteNavbarButton.setText("Delete");
        deleteNavbarButton.setActionCommand("Delete Bank Account");
        deleteNavbarButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                deleteNavbarButtonMouseClicked(evt);
            }
        });

        readNavbarButton.setText("Read");
        readNavbarButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                readNavbarButtonMouseClicked(evt);
            }
        });

        storeNavbarButton.setText("Store");
        storeNavbarButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                storeNavbarButtonMouseClicked(evt);
            }
        });

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));

        transactionTypeLabel.setText("Transaction Type");

        transactionTypeValue.setText("Choose transaction type");

        transactionDateLabel.setText("Transaction Date");

        saveButton.setText("Save");
        saveButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                saveButtonMouseClicked(evt);
            }
        });

        transactionDateInput.setText("dd/mm/yyyy");
        transactionDateInput.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                transactionDateInputFocusLost(evt);
            }
        });
        transactionDateInput.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                transactionDateInputMouseClicked(evt);
            }
        });

        selectBankAccountDropdown.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                selectBankAccountDropdownItemStateChanged(evt);
            }
        });

        transactionAmountLabel.setText("Transaction Amount");

        chooseExistingBankAccountLabel.setText("Choose an existing bank account");

        transactionAmountInput.setText("00.00");
        transactionAmountInput.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                transactionAmountInputFocusLost(evt);
            }
        });
        transactionAmountInput.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                transactionAmountInputMouseClicked(evt);
            }
        });

        orLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        orLabel.setText("Or");

        transactionSenderBankAccNumLabel.setText("Sender Account Number");

        myNameInput.setText("Enter your full name");
        myNameInput.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                myNameInputFocusLost(evt);
            }
        });
        myNameInput.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                myNameInputMouseClicked(evt);
            }
        });

        senderAccountNumValue.setText("Input number from bank details section");

        myNameLabel.setText("Your name");

        receiverAccNumLabel.setText("Receiver Account Number");

        myBankAccountNumberInput.setText("Enter your bank account number");
        myBankAccountNumberInput.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                myBankAccountNumberInputFocusLost(evt);
            }
        });
        myBankAccountNumberInput.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                myBankAccountNumberInputMouseClicked(evt);
            }
        });
        myBankAccountNumberInput.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                myBankAccountNumberInputKeyReleased(evt);
            }
        });

        receiverAccountNumInput.setText("123456");
        receiverAccountNumInput.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                receiverAccountNumInputFocusLost(evt);
            }
        });
        receiverAccountNumInput.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                receiverAccountNumInputMouseClicked(evt);
            }
        });

        myBankAccountNumberLabel.setText("Your bank account number");

        bankAccountDetailsLabel.setText("Bank Account Details");

        transactionTypeList.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = { "Withdrawl", "Deposit", "Transfer" };

            public int getSize() {
                return strings.length;
            }

            public String getElementAt(int i) {
                return strings[i];
            }
        });
        transactionTypeList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                transactionTypeListValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(transactionTypeList);

        transactionDetailsLabel.setText("Transaction Details");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addGap(270, 270, 270)
                                        .addGroup(
                                                jPanel1Layout
                                                        .createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING,
                                                                false)
                                                        .addComponent(saveButton,
                                                                javax.swing.GroupLayout.Alignment.LEADING,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                                .addGroup(jPanel1Layout.createParallelGroup(
                                                                        javax.swing.GroupLayout.Alignment.LEADING,
                                                                        false)
                                                                        .addComponent(bankAccountDetailsLabel)
                                                                        .addComponent(myBankAccountNumberLabel)
                                                                        .addComponent(myBankAccountNumberInput)
                                                                        .addComponent(myNameInput,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                200, Short.MAX_VALUE)
                                                                        .addComponent(myNameLabel)
                                                                        .addComponent(orLabel,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(chooseExistingBankAccountLabel)
                                                                        .addComponent(selectBankAccountDropdown, 0,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE))
                                                                .addGap(138, 138, 138)
                                                                .addGroup(jPanel1Layout.createParallelGroup(
                                                                        javax.swing.GroupLayout.Alignment.LEADING,
                                                                        false)
                                                                        .addComponent(transactionTypeValue,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(transactionTypeLabel)
                                                                        .addComponent(transactionDetailsLabel)
                                                                        .addComponent(transactionDateLabel)
                                                                        .addComponent(transactionDateInput)
                                                                        .addComponent(transactionAmountLabel)
                                                                        .addComponent(transactionAmountInput)
                                                                        .addComponent(transactionSenderBankAccNumLabel)
                                                                        .addComponent(senderAccountNumValue,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                                Short.MAX_VALUE)
                                                                        .addComponent(receiverAccNumLabel)
                                                                        .addComponent(receiverAccountNumInput)
                                                                        .addComponent(jScrollPane1))))
                                        .addContainerGap(271, Short.MAX_VALUE))));
        jPanel1Layout.setVerticalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGap(0, 759, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addGap(133, 133, 133)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                .addComponent(bankAccountDetailsLabel)
                                                .addComponent(transactionDetailsLabel))
                                        .addGap(18, 18, 18)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                .addComponent(myBankAccountNumberLabel)
                                                .addComponent(transactionDateLabel))
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                .addComponent(myBankAccountNumberInput,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addComponent(transactionDateInput,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGap(18, 18, 18)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                .addGroup(jPanel1Layout.createSequentialGroup()
                                                        .addComponent(myNameLabel)
                                                        .addPreferredGap(
                                                                javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                        .addComponent(myNameInput,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addGroup(jPanel1Layout.createSequentialGroup()
                                                        .addComponent(transactionAmountLabel)
                                                        .addPreferredGap(
                                                                javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                        .addComponent(transactionAmountInput,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE)))
                                        .addGap(18, 18, 18)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                .addGroup(jPanel1Layout.createSequentialGroup()
                                                        .addComponent(orLabel)
                                                        .addGap(18, 18, 18)
                                                        .addComponent(chooseExistingBankAccountLabel))
                                                .addGroup(jPanel1Layout.createSequentialGroup()
                                                        .addComponent(transactionSenderBankAccNumLabel)
                                                        .addPreferredGap(
                                                                javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                        .addComponent(senderAccountNumValue,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE,
                                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                                        .addGap(8, 8, 8)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                .addComponent(selectBankAccountDropdown,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGroup(jPanel1Layout.createSequentialGroup()
                                                        .addComponent(receiverAccNumLabel)
                                                        .addPreferredGap(
                                                                javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                        .addComponent(receiverAccountNumInput,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                                javax.swing.GroupLayout.PREFERRED_SIZE)))
                                        .addGap(18, 18, 18)
                                        .addComponent(transactionTypeLabel)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 71,
                                                javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(18, 18, 18)
                                        .addComponent(transactionTypeValue, javax.swing.GroupLayout.PREFERRED_SIZE, 30,
                                                javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(18, 18, 18)
                                        .addComponent(saveButton, javax.swing.GroupLayout.PREFERRED_SIZE, 31,
                                                javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addContainerGap(134, Short.MAX_VALUE))));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addGroup(layout.createSequentialGroup()
                                                .addGap(0, 860, Short.MAX_VALUE)
                                                .addComponent(storeNavbarButton)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(readNavbarButton)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(deleteNavbarButton)))
                                .addContainerGap()));
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(deleteNavbarButton)
                                        .addComponent(readNavbarButton)
                                        .addComponent(storeNavbarButton))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE,
                                        javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addContainerGap()));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void deleteNavbarButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_deleteNavbarButtonMouseClicked
        System.out.println("Navigating to Delete Transaction");
        this.dispose();
        Delete deleteTransaction = new Delete();
        deleteTransaction.setLocationRelativeTo(null);
        deleteTransaction.setVisible(true);
    }// GEN-LAST:event_deleteNavbarButtonMouseClicked

    private void readNavbarButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_readNavbarButtonMouseClicked
        System.out.println("Navigating to Read Transaction");
        this.dispose();
        Read readTransaction = new Read();
        readTransaction.setLocationRelativeTo(null);
        readTransaction.setVisible(true);
    }// GEN-LAST:event_readNavbarButtonMouseClicked

    private void storeNavbarButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_storeNavbarButtonMouseClicked
        System.out.println("Navigating to Store Transaction");
        this.dispose();
        Store storeTransaction = new Store();
        storeTransaction.setLocationRelativeTo(null);
        storeTransaction.setVisible(true);
    }// GEN-LAST:event_storeNavbarButtonMouseClicked

    private void selectBankAccountDropdownItemStateChanged(java.awt.event.ItemEvent evt) {// GEN-FIRST:event_selectBankAccountDropdownItemStateChanged
        System.out.println("Item changed to: " + selectBankAccountDropdown.getSelectedItem());
        BankAccount selectedAccount = (BankAccount) selectBankAccountDropdown.getSelectedItem();
        myBankAccountNumberInput.setText(selectedAccount.getAccountNumber());
        myNameInput.setText(selectedAccount.getAccountHolderName());
        senderAccountNumValue.setText(selectedAccount.getAccountNumber());

    }// GEN-LAST:event_selectBankAccountDropdownItemStateChanged

    private void myBankAccountNumberInputMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_myBankAccountNumberInputMouseClicked
        if (myBankAccountNumberInput.getText().equals("Enter your bank account number")) {
            myBankAccountNumberInput.setText("");
        }
    }// GEN-LAST:event_myBankAccountNumberInputMouseClicked

    private void myBankAccountNumberInputFocusLost(java.awt.event.FocusEvent evt) {// GEN-FIRST:event_myBankAccountNumberInputFocusLost
        if (myBankAccountNumberInput.getText().equals("")) {
            myBankAccountNumberInput.setText("Enter your bank account number");
        }
    }// GEN-LAST:event_myBankAccountNumberInputFocusLost

    private void myBankAccountNumberInputKeyReleased(java.awt.event.KeyEvent evt) {// GEN-FIRST:event_myBankAccountNumberInputKeyReleased
        senderAccountNumValue.setText(myBankAccountNumberInput.getText());
    }// GEN-LAST:event_myBankAccountNumberInputKeyReleased

    private void myNameInputMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_myNameInputMouseClicked
        if (myNameInput.getText().equals("Enter your full name")) {
            myNameInput.setText("");
        }
    }// GEN-LAST:event_myNameInputMouseClicked

    private void myNameInputFocusLost(java.awt.event.FocusEvent evt) {// GEN-FIRST:event_myNameInputFocusLost
        if (myNameInput.getText().equals("")) {
            myNameInput.setText("Enter your full name");
        }
    }// GEN-LAST:event_myNameInputFocusLost

    private void transactionDateInputMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_transactionDateInputMouseClicked
        if (transactionDateInput.getText().equals("dd/mm/yyyy")) {
            transactionDateInput.setText("");
        }
    }// GEN-LAST:event_transactionDateInputMouseClicked

    private void transactionDateInputFocusLost(java.awt.event.FocusEvent evt) {// GEN-FIRST:event_transactionDateInputFocusLost
        if (transactionDateInput.getText().equals("")) {
            transactionDateInput.setText("dd/mm/yyyy");
        }
    }// GEN-LAST:event_transactionDateInputFocusLost

    private void transactionAmountInputMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_transactionAmountInputMouseClicked
        if (transactionAmountInput.getText().equals("00.00")) {
            transactionAmountInput.setText("");
        }
    }// GEN-LAST:event_transactionAmountInputMouseClicked

    private void transactionAmountInputFocusLost(java.awt.event.FocusEvent evt) {// GEN-FIRST:event_transactionAmountInputFocusLost
        if (transactionAmountInput.getText().equals("")) {
            transactionAmountInput.setText("00.00");
        }
    }// GEN-LAST:event_transactionAmountInputFocusLost

    private void receiverAccountNumInputMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_receiverAccountNumInputMouseClicked
        if (receiverAccountNumInput.getText().equals("123456")) {
            receiverAccountNumInput.setText("");
        }
    }// GEN-LAST:event_receiverAccountNumInputMouseClicked

    private void receiverAccountNumInputFocusLost(java.awt.event.FocusEvent evt) {// GEN-FIRST:event_receiverAccountNumInputFocusLost
        if (receiverAccountNumInput.getText().equals("")) {
            receiverAccountNumInput.setText("123456");
        }
    }// GEN-LAST:event_receiverAccountNumInputFocusLost

    private void transactionTypeListValueChanged(javax.swing.event.ListSelectionEvent evt) {// GEN-FIRST:event_transactionTypeListValueChanged
        transactionTypeValue.setText(transactionTypeList.getSelectedValue());
    }// GEN-LAST:event_transactionTypeListValueChanged

    private void saveButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_saveButtonMouseClicked
        System.out.println("Saving transaction");
        String accountNumber = myBankAccountNumberInput.getText();
        String accountHolderName = myNameInput.getText();
        String transactionDate = transactionDateInput.getText();
        double amount = 0;

        try {
            amount = Double.parseDouble(transactionAmountInput.getText());
        } catch (Exception e) {
            System.out.println("Amount is not a valid number");
            Popup popup = new Popup("Amount is not a valid number");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
            return;
        }

        String senderAccountNumber = senderAccountNumValue.getText();
        String receiverAccountNumber = receiverAccountNumInput.getText();
        String transactionType = transactionTypeValue.getText();

        try {
            dbTransactions.storeTransaction(accountNumber, accountHolderName, transactionDate, amount, senderAccountNumber,
                    receiverAccountNumber, transactionType);

            System.out.println("Transaction stored successfully");
            Popup popup = new Popup("Transaction stored successfully");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            Popup popup = new Popup(e.getMessage());
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (Exception e) {
            System.out.println("An error occurred while storing the transaction");
            Popup popup = new Popup("An error occurred while storing the transaction");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        }
    }// GEN-LAST:event_saveButtonMouseClicked

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
            java.util.logging.Logger.getLogger(Store.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Store.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Store.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Store.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        // </editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                Store store = new Store();
                store.setLocationRelativeTo(null); // Set the location to the center of the screen
                store.setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel bankAccountDetailsLabel;
    private javax.swing.JLabel chooseExistingBankAccountLabel;
    private javax.swing.JButton deleteNavbarButton;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField myBankAccountNumberInput;
    private javax.swing.JLabel myBankAccountNumberLabel;
    private javax.swing.JTextField myNameInput;
    private javax.swing.JLabel myNameLabel;
    private javax.swing.JLabel orLabel;
    private javax.swing.JButton readNavbarButton;
    private javax.swing.JLabel receiverAccNumLabel;
    private javax.swing.JTextField receiverAccountNumInput;
    private javax.swing.JButton saveButton;
    private javax.swing.JComboBox<BankAccount> selectBankAccountDropdown;
    private javax.swing.JLabel senderAccountNumValue;
    private javax.swing.JButton storeNavbarButton;
    private javax.swing.JTextField transactionAmountInput;
    private javax.swing.JLabel transactionAmountLabel;
    private javax.swing.JTextField transactionDateInput;
    private javax.swing.JLabel transactionDateLabel;
    private javax.swing.JLabel transactionDetailsLabel;
    private javax.swing.JLabel transactionSenderBankAccNumLabel;
    private javax.swing.JLabel transactionTypeLabel;
    private javax.swing.JList<String> transactionTypeList;
    private javax.swing.JLabel transactionTypeValue;
    // End of variables declaration//GEN-END:variables
}
