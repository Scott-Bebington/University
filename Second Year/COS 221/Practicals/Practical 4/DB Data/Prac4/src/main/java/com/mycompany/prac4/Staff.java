/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.prac4;

import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableRowSorter;
import javax.swing.RowFilter;

/**
 *
 * @author scott
 */
public class Staff extends javax.swing.JFrame
{

    /**
     * Creates new form Staff
     */
    public Staff()
    {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents()
    {

        jScrollPane1 = new javax.swing.JScrollPane();
        Staff_Info_Table = new javax.swing.JTable();
        Homepage_Container = new javax.swing.JPanel();
        Searchbar = new javax.swing.JTextField();
        jScrollPane2 = new javax.swing.JScrollPane();
        Staff_Info_Table1 = new javax.swing.JTable();
        jSeparator1 = new javax.swing.JSeparator();
        jLabel1 = new javax.swing.JLabel();
        Home_Page = new javax.swing.JButton();
        Staff_Page = new javax.swing.JButton();
        Films_Page = new javax.swing.JButton();
        Reports_Page = new javax.swing.JButton();
        Notifications_Page = new javax.swing.JButton();
        Exit = new javax.swing.JButton();

        Staff_Info_Table.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][]
            {
                {null, null, null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null, null, null}
            },
            new String []
            {
                "Name", "Surname", "Address", "Adress 2", "District", "City", "Postal Code", "Phone", "Store", "Active"
            }
        )
        {
            boolean[] canEdit = new boolean []
            {
                false, false, false, false, false, false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex)
            {
                return canEdit [columnIndex];
            }
        });
        Staff_Info_Table.setGridColor(new java.awt.Color(0, 0, 0));
        Staff_Info_Table.setSelectionBackground(new java.awt.Color(255, 255, 255));
        jScrollPane1.setViewportView(Staff_Info_Table);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Homepage_Container.setBackground(new java.awt.Color(0, 0, 0));

        Searchbar.setText("Search...");
        Searchbar.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(51, 102, 255)));
        Searchbar.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                SearchbarMouseClicked(evt);
            }
        });
        Searchbar.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                SearchbarActionPerformed(evt);
            }
        });
        Searchbar.addKeyListener(new java.awt.event.KeyAdapter()
        {
            public void keyReleased(java.awt.event.KeyEvent evt)
            {
                SearchbarKeyReleased(evt);
            }
        });

        Staff_Info_Table1.setAutoCreateRowSorter(true);
        Staff_Info_Table1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][]
            {
                {"Aaron", "Bailey", "1111 Main St.", "Suite 100", "Central", "Arlington", "76010", "555-555-0197", 1, 1},
                {"Adam", "Bryant", "1234 Elm St.", "Apt. 5C", "Downtown", "Dallas", "75201", "555-555-0132", 1, 1},
                {"Alex", "Carter", "5678 Maple St.", "Unit 10", "North", "Houston", "77001", "555-555-0143", 2, 1},
                {"Amanda", "Davis", "9999 Oak St.", null, "West", "San Diego", "92101", "555-555-0165", 2, 1},
                {"Ashley", "Evans", "4444 Pine St.", "Suite 200", "Central", "Austin", "78701", "555-555-0187", 1, 1},
                {"Benjamin", "Fisher", "7777 Cedar St.", "Apt. 3B", "Downtown", "Houston", "77002", "555-555-0101", 2, 1},
                {"Brian", "Garcia", "5555 Birch St.", null, "North", "Dallas", "75202", "555-555-0154", 1, 1},
                {"Carol", "Hernandez", "2222 Laurel St.", null, "West", "San Diego", "92102", "555-555-0112", 2, 1},
                {"Charles", "Jackson", "3333 Maple Ave.", "Suite 500", "Central", "Austin", "78702", "555-555-0176", 1, 1},
                {"Christina", "Kim", "4567 Oak St.", null, "West", "San Diego", "92103", "555-555-0123", 2, 1}
            },
            new String []
            {
                "Name", "Surname", "Address", "Adress 2", "District", "City", "Postal Code", "Phone", "Store", "Active"
            }
        )
        {
            boolean[] canEdit = new boolean []
            {
                false, false, false, false, false, false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex)
            {
                return canEdit [columnIndex];
            }
        });
        Staff_Info_Table1.setAutoResizeMode(javax.swing.JTable.AUTO_RESIZE_ALL_COLUMNS);
        Staff_Info_Table1.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        Staff_Info_Table1.setFocusable(false);
        Staff_Info_Table1.setGridColor(new java.awt.Color(51, 102, 255));
        Staff_Info_Table1.setOpaque(false);
        Staff_Info_Table1.setRequestFocusEnabled(false);
        Staff_Info_Table1.setRowSelectionAllowed(false);
        Staff_Info_Table1.setSelectionBackground(new java.awt.Color(255, 255, 255));
        jScrollPane2.setViewportView(Staff_Info_Table1);

        jSeparator1.setBackground(new java.awt.Color(0, 0, 0));
        jSeparator1.setForeground(new java.awt.Color(0, 0, 0));
        jSeparator1.setOrientation(javax.swing.SwingConstants.VERTICAL);
        jSeparator1.setAlignmentX(0.0F);
        jSeparator1.setAlignmentY(0.0F);

        jLabel1.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Staff");

        Home_Page.setBackground(new java.awt.Color(51, 102, 255));
        Home_Page.setText("Home");
        Home_Page.setPreferredSize(new java.awt.Dimension(75, 25));
        Home_Page.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Home_PageActionPerformed(evt);
            }
        });

        Staff_Page.setBackground(new java.awt.Color(51, 102, 255));
        Staff_Page.setText("Staff");
        Staff_Page.setPreferredSize(new java.awt.Dimension(75, 25));
        Staff_Page.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Staff_PageActionPerformed(evt);
            }
        });

        Films_Page.setBackground(new java.awt.Color(51, 102, 255));
        Films_Page.setText("Films");
        Films_Page.setPreferredSize(new java.awt.Dimension(75, 25));
        Films_Page.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Films_PageActionPerformed(evt);
            }
        });

        Reports_Page.setBackground(new java.awt.Color(51, 102, 255));
        Reports_Page.setText("Reports");
        Reports_Page.setPreferredSize(new java.awt.Dimension(75, 25));
        Reports_Page.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Reports_PageActionPerformed(evt);
            }
        });

        Notifications_Page.setBackground(new java.awt.Color(51, 102, 255));
        Notifications_Page.setText("Notifications");
        Notifications_Page.setPreferredSize(new java.awt.Dimension(75, 25));
        Notifications_Page.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Notifications_PageActionPerformed(evt);
            }
        });

        Exit.setBackground(new java.awt.Color(51, 102, 255));
        Exit.setText("Exit");
        Exit.setPreferredSize(new java.awt.Dimension(75, 25));
        Exit.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                ExitActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout Homepage_ContainerLayout = new javax.swing.GroupLayout(Homepage_Container);
        Homepage_Container.setLayout(Homepage_ContainerLayout);
        Homepage_ContainerLayout.setHorizontalGroup(
            Homepage_ContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(Homepage_ContainerLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(Homepage_ContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Home_Page, javax.swing.GroupLayout.DEFAULT_SIZE, 116, Short.MAX_VALUE)
                    .addComponent(Staff_Page, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Reports_Page, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Films_Page, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Exit, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Notifications_Page, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(Homepage_ContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 638, Short.MAX_VALUE)
                    .addComponent(Searchbar))
                .addContainerGap(25, Short.MAX_VALUE))
        );
        Homepage_ContainerLayout.setVerticalGroup(
            Homepage_ContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(Homepage_ContainerLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(Homepage_ContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(Homepage_ContainerLayout.createSequentialGroup()
                        .addComponent(Searchbar, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane2))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, Homepage_ContainerLayout.createSequentialGroup()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(43, 43, 43)
                        .addComponent(Home_Page, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(62, 62, 62)
                        .addComponent(Staff_Page, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(62, 62, 62)
                        .addComponent(Films_Page, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(62, 62, 62)
                        .addComponent(Reports_Page, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(62, 62, 62)
                        .addComponent(Notifications_Page, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 92, Short.MAX_VALUE)
                        .addComponent(Exit, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Homepage_Container, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Homepage_Container, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void Home_PageActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Home_PageActionPerformed
    {//GEN-HEADEREND:event_Home_PageActionPerformed
        HomePage form = new HomePage();
        form.setSize(800, 650);
        form.setLocationRelativeTo(null);
        form.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_Home_PageActionPerformed

    private void Staff_PageActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Staff_PageActionPerformed
    {//GEN-HEADEREND:event_Staff_PageActionPerformed

    }//GEN-LAST:event_Staff_PageActionPerformed

    private void Films_PageActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Films_PageActionPerformed
    {//GEN-HEADEREND:event_Films_PageActionPerformed
        Films form = new Films();
        form.setSize(800, 650);
        form.setLocationRelativeTo(null);
        form.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_Films_PageActionPerformed

    private void Reports_PageActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Reports_PageActionPerformed
    {//GEN-HEADEREND:event_Reports_PageActionPerformed
        Reports form = new Reports();
        form.setSize(800, 650);
        form.setLocationRelativeTo(null);
        form.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_Reports_PageActionPerformed

    private void Notifications_PageActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Notifications_PageActionPerformed
    {//GEN-HEADEREND:event_Notifications_PageActionPerformed
        Notifications form = new Notifications();
        form.setSize(800, 650);
        form.setLocationRelativeTo(null);
        form.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_Notifications_PageActionPerformed

    private void ExitActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_ExitActionPerformed
    {//GEN-HEADEREND:event_ExitActionPerformed
        this.dispose();
    }//GEN-LAST:event_ExitActionPerformed

    private void SearchbarActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_SearchbarActionPerformed
    {//GEN-HEADEREND:event_SearchbarActionPerformed

    }//GEN-LAST:event_SearchbarActionPerformed

    private void SearchbarKeyReleased(java.awt.event.KeyEvent evt)//GEN-FIRST:event_SearchbarKeyReleased
    {//GEN-HEADEREND:event_SearchbarKeyReleased
        String searchValue = Searchbar.getText();
        DefaultTableModel tableModel = (DefaultTableModel) Staff_Info_Table1.getModel();
        TableRowSorter<DefaultTableModel> tableRowSorter = new TableRowSorter<>(tableModel);
        Staff_Info_Table1.setRowSorter(tableRowSorter);
        if (searchValue.trim().length() == 0)
        {
            tableRowSorter.setRowFilter(null);
        } else
        {
            tableRowSorter.setRowFilter(RowFilter.regexFilter("(?i)" + searchValue));
        }
    }//GEN-LAST:event_SearchbarKeyReleased

    private void SearchbarMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_SearchbarMouseClicked
    {//GEN-HEADEREND:event_SearchbarMouseClicked
        if (Searchbar.getText().equals("Search..."))
        {
            Searchbar.setText("");
        }
    }//GEN-LAST:event_SearchbarMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[])
    {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try
        {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels())
            {
                if ("Nimbus".equals(info.getName()))
                {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex)
        {
            java.util.logging.Logger.getLogger(Staff.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex)
        {
            java.util.logging.Logger.getLogger(Staff.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex)
        {
            java.util.logging.Logger.getLogger(Staff.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex)
        {
            java.util.logging.Logger.getLogger(Staff.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable()
        {
            public void run()
            {
                new Staff().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Exit;
    private javax.swing.JButton Films_Page;
    private javax.swing.JButton Home_Page;
    private javax.swing.JPanel Homepage_Container;
    private javax.swing.JButton Notifications_Page;
    private javax.swing.JButton Reports_Page;
    private javax.swing.JTextField Searchbar;
    private javax.swing.JTable Staff_Info_Table;
    private javax.swing.JTable Staff_Info_Table1;
    private javax.swing.JButton Staff_Page;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
}
