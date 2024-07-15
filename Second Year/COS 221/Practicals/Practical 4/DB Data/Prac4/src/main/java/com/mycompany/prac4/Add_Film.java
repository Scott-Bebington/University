/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.prac4;

/**
 *
 * @author scott
 */
public class Add_Film extends javax.swing.JFrame
{

    /**
     * Creates new form Add_Film
     */
    public Add_Film()
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

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jSeparator1 = new javax.swing.JSeparator();
        Title = new javax.swing.JTextField();
        Description = new javax.swing.JTextField();
        Release_Year = new javax.swing.JTextField();
        Rental_Duration = new javax.swing.JTextField();
        Rental_Cost = new javax.swing.JTextField();
        Replacement_Cost = new javax.swing.JTextField();
        Length = new javax.swing.JTextField();
        Submit_Film = new javax.swing.JButton();
        Back_Button = new javax.swing.JButton();
        Rating = new javax.swing.JComboBox<>();
        Language = new javax.swing.JComboBox<>();
        Original_Language = new javax.swing.JComboBox<>();
        jLabel2 = new javax.swing.JLabel();
        Trailers = new javax.swing.JCheckBox();
        Commentaries = new javax.swing.JCheckBox();
        Deleted_scenes = new javax.swing.JCheckBox();
        Behind_The_Scenes = new javax.swing.JCheckBox();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));

        jLabel1.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Add Film");

        jSeparator1.setBackground(new java.awt.Color(0, 0, 0));
        jSeparator1.setForeground(new java.awt.Color(0, 0, 0));

        Title.setText("Title");
        Title.setPreferredSize(new java.awt.Dimension(250, 50));
        Title.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                TitleMouseClicked(evt);
            }
        });
        Title.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                TitleActionPerformed(evt);
            }
        });

        Description.setText("Description");
        Description.setPreferredSize(new java.awt.Dimension(250, 50));
        Description.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                DescriptionMouseClicked(evt);
            }
        });

        Release_Year.setText("Release Year");
        Release_Year.setPreferredSize(new java.awt.Dimension(250, 50));
        Release_Year.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                Release_YearMouseClicked(evt);
            }
        });

        Rental_Duration.setText("Rental Duration (Days)");
        Rental_Duration.setPreferredSize(new java.awt.Dimension(250, 50));
        Rental_Duration.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                Rental_DurationMouseClicked(evt);
            }
        });

        Rental_Cost.setText("Rental Cost eg. 12.99");
        Rental_Cost.setPreferredSize(new java.awt.Dimension(250, 50));
        Rental_Cost.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                Rental_CostMouseClicked(evt);
            }
        });

        Replacement_Cost.setText("Replacement Cost eg. 12.99");
        Replacement_Cost.setPreferredSize(new java.awt.Dimension(250, 50));
        Replacement_Cost.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                Replacement_CostMouseClicked(evt);
            }
        });
        Replacement_Cost.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Replacement_CostActionPerformed(evt);
            }
        });

        Length.setText("Length (Mins)");
        Length.setPreferredSize(new java.awt.Dimension(250, 50));
        Length.addMouseListener(new java.awt.event.MouseAdapter()
        {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
                LengthMouseClicked(evt);
            }
        });

        Submit_Film.setText("Submit");
        Submit_Film.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Submit_FilmActionPerformed(evt);
            }
        });

        Back_Button.setText("Back");
        Back_Button.addActionListener(new java.awt.event.ActionListener()
        {
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                Back_ButtonActionPerformed(evt);
            }
        });

        Rating.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Select Rating", "G", "PG", "PG-13", "R", "NC-17" }));

        Language.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Language", "Item 2", "Item 3", "Item 4" }));

        Original_Language.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Original Language", "Item 2", "Item 3", "Item 4" }));

        jLabel2.setText("Special Features");

        Trailers.setText("Trailers");

        Commentaries.setText("Commentaries");

        Deleted_scenes.setText("Deleted Scenes");

        Behind_The_Scenes.setText("Behind the Scenes");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(136, 136, 136)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(jPanel1Layout.createSequentialGroup()
                                    .addComponent(Release_Year, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGap(18, 18, 18)
                                    .addComponent(Replacement_Cost, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGroup(jPanel1Layout.createSequentialGroup()
                                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                        .addComponent(Submit_Film, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(Length, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(Language, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(Original_Language, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                    .addGap(18, 18, 18)
                                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(Back_Button, javax.swing.GroupLayout.DEFAULT_SIZE, 250, Short.MAX_VALUE)
                                        .addComponent(Rating, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                                .addComponent(Trailers, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                .addComponent(Commentaries, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 125, Short.MAX_VALUE))
                                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                .addComponent(Deleted_scenes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                .addComponent(Behind_The_Scenes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(Description, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(Title, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(18, 18, 18)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(Rental_Duration, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(Rental_Cost, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addGap(0, 134, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(33, 33, 33)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Rental_Duration, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Title, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Description, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Rental_Cost, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Release_Year, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Replacement_Cost, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Rating, javax.swing.GroupLayout.DEFAULT_SIZE, 46, Short.MAX_VALUE)
                    .addComponent(Language))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(Original_Language, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(Trailers, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(Deleted_scenes))))
                .addGap(22, 22, 22)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Length, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Commentaries)
                    .addComponent(Behind_The_Scenes))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(Submit_Film, javax.swing.GroupLayout.DEFAULT_SIZE, 52, Short.MAX_VALUE)
                    .addComponent(Back_Button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void TitleActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_TitleActionPerformed
    {//GEN-HEADEREND:event_TitleActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_TitleActionPerformed

    private void Back_ButtonActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Back_ButtonActionPerformed
    {//GEN-HEADEREND:event_Back_ButtonActionPerformed
        Films form = new Films();
        form.setSize(800, 650);
        form.setLocationRelativeTo(null);
        form.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_Back_ButtonActionPerformed

    private void Submit_FilmActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Submit_FilmActionPerformed
    {//GEN-HEADEREND:event_Submit_FilmActionPerformed
        
    }//GEN-LAST:event_Submit_FilmActionPerformed

    private void Replacement_CostActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_Replacement_CostActionPerformed
    {//GEN-HEADEREND:event_Replacement_CostActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_Replacement_CostActionPerformed

    private void TitleMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_TitleMouseClicked
    {//GEN-HEADEREND:event_TitleMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_TitleMouseClicked

    private void Rental_DurationMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_Rental_DurationMouseClicked
    {//GEN-HEADEREND:event_Rental_DurationMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_Rental_DurationMouseClicked

    private void DescriptionMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_DescriptionMouseClicked
    {//GEN-HEADEREND:event_DescriptionMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_DescriptionMouseClicked

    private void Release_YearMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_Release_YearMouseClicked
    {//GEN-HEADEREND:event_Release_YearMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_Release_YearMouseClicked

    private void Rental_CostMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_Rental_CostMouseClicked
    {//GEN-HEADEREND:event_Rental_CostMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_Rental_CostMouseClicked

    private void Replacement_CostMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_Replacement_CostMouseClicked
    {//GEN-HEADEREND:event_Replacement_CostMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_Replacement_CostMouseClicked

    private void LengthMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_LengthMouseClicked
    {//GEN-HEADEREND:event_LengthMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_LengthMouseClicked

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
            java.util.logging.Logger.getLogger(Add_Film.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex)
        {
            java.util.logging.Logger.getLogger(Add_Film.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex)
        {
            java.util.logging.Logger.getLogger(Add_Film.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex)
        {
            java.util.logging.Logger.getLogger(Add_Film.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable()
        {
            public void run()
            {
                new Add_Film().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Back_Button;
    private javax.swing.JCheckBox Behind_The_Scenes;
    private javax.swing.JCheckBox Commentaries;
    private javax.swing.JCheckBox Deleted_scenes;
    private javax.swing.JTextField Description;
    private javax.swing.JComboBox<String> Language;
    private javax.swing.JTextField Length;
    private javax.swing.JComboBox<String> Original_Language;
    private javax.swing.JComboBox<String> Rating;
    private javax.swing.JTextField Release_Year;
    private javax.swing.JTextField Rental_Cost;
    private javax.swing.JTextField Rental_Duration;
    private javax.swing.JTextField Replacement_Cost;
    private javax.swing.JButton Submit_Film;
    private javax.swing.JTextField Title;
    private javax.swing.JCheckBox Trailers;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
}
