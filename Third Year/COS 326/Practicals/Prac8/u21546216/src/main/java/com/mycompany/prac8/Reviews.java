/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.prac8;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

import javax.swing.DefaultListModel;

import org.bson.Document;

import com.mongodb.ConnectionString;
import com.mongodb.MongoClientSettings;
import com.mongodb.MongoException;
import com.mongodb.ServerApi;
import com.mongodb.ServerApiVersion;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;

/**
 *
 * @author scott
 */
public class Reviews extends javax.swing.JFrame {
    private List<Review> reviews = new ArrayList<>();

    /**
     * Creates new form Reviews
     */
    public Reviews() {
        initComponents();
    }

    private void populateReviewsList() {
        String connectionString = "mongodb+srv://Scott_Bebington:Scott25121!@university.koccw.mongodb.net/?retryWrites=true&w=majority&appName=University";
        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();
        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(connectionString))
                .serverApi(serverApi)
                .build();

        try (MongoClient mongoClient = MongoClients.create(settings)) {
            try {
                MongoDatabase database = mongoClient.getDatabase("ecommercedb");
                MongoCollection<Document> collection = database.getCollection("products");

                // Retrieve all the documents from the collection

                collection.find().forEach((Consumer<Document>) document -> {
                    String productId = document.getString("product_id");
                    String productName = document.getString("name");
                    List<Document> newReviews = document.getList("reviews", Document.class);

                    List<Review> productReview = new ArrayList<>();
                    for (Document review : newReviews) {
                        // System.out.println(review);
                        String message = review.getString("review");
                        int rating = review.getInteger("rating");
                        productReview.add(new Review(productId, productName, message, rating));

                    }
                    reviews.addAll(productReview);
                });

                // Populate the JList with the products
                DefaultListModel<Review> model = new DefaultListModel<>();
                reviews.forEach(model::addElement);
                ReviewsList.setModel(model);

            } catch (MongoException e) {
                Popup popup = new Popup("An error occurred while connecting to the database");
                popup.setLocationRelativeTo(null);
                popup.setVisible(true);
            }
        } catch (Exception e) {
            Popup popup = new Popup("An error occurred");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        }
    }

    private void populateCollectionNamesList() {
        String connectionString = "mongodb+srv://Scott_Bebington:Scott25121!@university.koccw.mongodb.net/?retryWrites=true&w=majority&appName=University";
        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();
        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(connectionString))
                .serverApi(serverApi)
                .build();

        try (MongoClient mongoClient = MongoClients.create(settings)) {
            try {
                MongoDatabase database = mongoClient.getDatabase("ecommercedb");

                // Retrieve all the collection names from the database
                List<String> collectionNames = database.listCollectionNames().into(new ArrayList<>());

                // Populate the JList with the collection names
                DefaultListModel<String> model = new DefaultListModel<>();
                collectionNames.forEach(model::addElement);
                CollectionNamesList.setModel(model);

            } catch (MongoException e) {
                Popup popup = new Popup("An error occurred while connecting to the database");
                popup.setLocationRelativeTo(null);
                popup.setVisible(true);
            }
        } catch (Exception e) {
            Popup popup = new Popup("An error occurred");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        }
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

        jPanel1 = new javax.swing.JPanel();
        ViewReviewsButton = new javax.swing.JButton();
        GetCollectionNamesButton = new javax.swing.JButton();
        GoToProductsButton = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        ReviewsList = new javax.swing.JList<>();
        jScrollPane2 = new javax.swing.JScrollPane();
        CollectionNamesList = new javax.swing.JList<>();
        ProductNameLabel = new javax.swing.JLabel();
        ReviewLabel = new javax.swing.JLabel();
        RatingLabel = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        ViewReviewsButton.setText("View Reviews Collection");
        ViewReviewsButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                ViewReviewsButtonMouseClicked(evt);
            }
        });

        GetCollectionNamesButton.setText("Get Collection Names");
        GetCollectionNamesButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                GetCollectionNamesButtonMouseClicked(evt);
            }
        });

        GoToProductsButton.setText("Products");
        GoToProductsButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                GoToProductsButtonMouseClicked(evt);
            }
        });

        ReviewsList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                ReviewsListValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(ReviewsList);

        jScrollPane2.setViewportView(CollectionNamesList);

        ProductNameLabel.setText("Product Name:");

        ReviewLabel.setText("Review:");

        RatingLabel.setText("Rating:");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 400,
                                                        Short.MAX_VALUE)
                                                .addComponent(ViewReviewsButton, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                        javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                .addComponent(ProductNameLabel, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                        javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                        .addComponent(ReviewLabel, javax.swing.GroupLayout.DEFAULT_SIZE, 406,
                                                Short.MAX_VALUE)
                                        .addComponent(RatingLabel, javax.swing.GroupLayout.Alignment.TRAILING,
                                                javax.swing.GroupLayout.DEFAULT_SIZE, 406, Short.MAX_VALUE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout
                                        .createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(GetCollectionNamesButton, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                400, Short.MAX_VALUE)
                                        .addComponent(jScrollPane2))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 99,
                                        Short.MAX_VALUE)
                                .addComponent(GoToProductsButton)
                                .addContainerGap()));
        jPanel1Layout.setVerticalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(jPanel1Layout
                                                .createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                .addComponent(ViewReviewsButton, javax.swing.GroupLayout.PREFERRED_SIZE,
                                                        40, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addComponent(GetCollectionNamesButton,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE, 40,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addComponent(GoToProductsButton))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jScrollPane2)
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 400,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(ProductNameLabel, javax.swing.GroupLayout.PREFERRED_SIZE,
                                                        40, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(ReviewLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(RatingLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40,
                                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(0, 180, Short.MAX_VALUE)))
                                .addContainerGap()));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE,
                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE));
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE,
                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ViewReviewsButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_ViewReviewsButtonMouseClicked
        
        reviews.clear();    
        
        ViewReviewsButton.setEnabled(false);
        populateReviewsList();
        ViewReviewsButton.setEnabled(true);
    }// GEN-LAST:event_ViewReviewsButtonMouseClicked

    private void GetCollectionNamesButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_GetCollectionNamesButtonMouseClicked
        GetCollectionNamesButton.setEnabled(false);
        populateCollectionNamesList();
        GetCollectionNamesButton.setEnabled(true);
    }// GEN-LAST:event_GetCollectionNamesButtonMouseClicked

    private void ReviewsListValueChanged(javax.swing.event.ListSelectionEvent evt) {// GEN-FIRST:event_ReviewsListValueChanged
        Review selectedReview = ReviewsList.getSelectedValue();
        if (selectedReview != null) {
            ProductNameLabel.setText("Product Name: " + selectedReview.getProduct_name());
            ReviewLabel.setText("Review: " + selectedReview.getReview());
            RatingLabel.setText("Rating: " + selectedReview.getRating());
        }
    }// GEN-LAST:event_ReviewsListValueChanged

    private void GoToProductsButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_GoToProductsButtonMouseClicked
        Products products = new Products();
        products.setLocationRelativeTo(null);
        products.setVisible(true);
        this.dispose();
    }// GEN-LAST:event_GoToProductsButtonMouseClicked

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
            java.util.logging.Logger.getLogger(Reviews.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Reviews.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Reviews.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Reviews.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        // </editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Reviews().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JList<String> CollectionNamesList;
    private javax.swing.JButton GetCollectionNamesButton;
    private javax.swing.JButton GoToProductsButton;
    private javax.swing.JLabel ProductNameLabel;
    private javax.swing.JLabel RatingLabel;
    private javax.swing.JLabel ReviewLabel;
    private javax.swing.JList<Review> ReviewsList;
    private javax.swing.JButton ViewReviewsButton;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    // End of variables declaration//GEN-END:variables
}
