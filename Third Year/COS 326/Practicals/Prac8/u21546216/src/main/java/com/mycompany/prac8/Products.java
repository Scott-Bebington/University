/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.prac8;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

import com.mongodb.ConnectionString;
import com.mongodb.MongoClientSettings;
import com.mongodb.MongoException;
import com.mongodb.ServerApi;
import com.mongodb.ServerApiVersion;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

/**
 *
 * @author scott
 */
public class Products extends javax.swing.JFrame {
    private List<Product> products = new ArrayList<>();

    /**
     * Creates new form Products
     */
    public Products() {
        initComponents();
    }

    private void populateProductList() {
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
                    String category = document.getString("category");
                    double price = document.getInteger("price");
                    int stock = document.getInteger("stock");
                    List<Document> reviews = document.getList("reviews", Document.class);

                    List<Review> productReview = new ArrayList<>();
                    for (Document review : reviews) {
                        String message = review.getString("review");
                        int rating = review.getInteger("rating");
                        productReview.add(new Review(productId, productName, message, rating));
                    }

                    Product product = new Product(productId, productName, category, price, stock, productReview);
                    products.add(product);
                });

                // Populate the JList with the products
                DefaultListModel<Product> model = new DefaultListModel<>();
                products.forEach(model::addElement);
                ProductList.setModel(model);

                if (!CountProductsLabel.getText().isEmpty()) {
                    countProducts();
                }
            } catch (MongoException e) {
                Popup popup = new Popup("An error occurred while connecting to the database");
                popup.setLocationRelativeTo(null);
                popup.setVisible(true);
            }
        } catch (Exception e) {
            // Popup popup = new Popup("An error occurred");
            // popup.setLocationRelativeTo(null);
            // popup.setVisible(true);
        }
    }

    private void countProducts() {
        String connectionString = "mongodb+srv://Scott_Bebington:Scott25121!@university.koccw.mongodb.net/?retryWrites=true&w=majority&appName=University";
        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();
        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(connectionString))
                .serverApi(serverApi)
                .build();

        try (MongoClient mongoClient = MongoClients.create(settings)) {
            MongoDatabase database = mongoClient.getDatabase("ecommercedb");
            MongoCollection<Document> collection = database.getCollection("products");
            long count = collection.countDocuments();
            CountProductsLabel.setText("Number of products: " + count);
        } catch (MongoException e) {
            Popup popup = new Popup("An error occurred while connecting to the database");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (Exception e) {
            // Popup popup = new Popup("An error occurred");
            // popup.setLocationRelativeTo(null);
            // popup.setVisible(true);
        }
    }

    private void findExpensiveProducts() {
        String connectionString = "mongodb+srv://Scott_Bebington:Scott25121!@university.koccw.mongodb.net/?retryWrites=true&w=majority&appName=University";
        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();
        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(connectionString))
                .serverApi(serverApi)
                .build();

        try (MongoClient mongoClient = MongoClients.create(settings)) {
            MongoDatabase database = mongoClient.getDatabase("ecommercedb");
            MongoCollection<Document> collection = database.getCollection("products");

            // Find the products with price greater than 100
            Document query = new Document("price", new Document("$gt", 500));
            List<Document> expensiveProducts = collection.find(query).into(new ArrayList<>());

            for (Document product : expensiveProducts) {
                String productId = product.getString("product_id");
                String productName = product.getString("name");
                String category = product.getString("category");
                double price = product.getInteger("price");
                int stock = product.getInteger("stock");
                List<Document> reviews = product.getList("reviews", Document.class);

                System.out.println("Price: " + price);

                List<Review> productReview = new ArrayList<>();
                for (Document review : reviews) {
                    String message = review.getString("review");
                    int rating = review.getInteger("rating");
                    productReview.add(new Review(productId, productName, message, rating));
                }

                Product newProduct = new Product(productId, productName, category, price, stock, productReview);
                products.add(newProduct);
            }

            // Populate the JList with the products
            DefaultListModel<Product> model = new DefaultListModel<>();
            products.forEach(model::addElement);
            ProductList.setModel(model);

        } catch (MongoException e) {
            Popup popup = new Popup("An error occurred while connecting to the database");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (Exception e) {
            // System.out.println(e);
            // Popup popup = new Popup("An error occurred");
            // popup.setLocationRelativeTo(null);
            // popup.setVisible(true);
        }
    }

    private void DisplayProductIOnDetail(Product product) {
        ProductNameLabel.setText("Product Name: " + product.getName());
        ProductCategoryLabel.setText("Category: " + product.getCategory());
        ProductPriceLabel1.setText("Price: " + product.getPrice());
        ProductStockLabel.setText("Stock: " + product.getStock());
        ProductReviewsLabel.setText("Number of Reviews: " + product.getReviews().size());
    }

    private void extractReviews() {
        String connectionString = "mongodb+srv://Scott_Bebington:Scott25121!@university.koccw.mongodb.net/?retryWrites=true&w=majority&appName=University";
        ServerApi serverApi = ServerApi.builder()
            .version(ServerApiVersion.V1)
            .build();
        MongoClientSettings settings = MongoClientSettings.builder()
            .applyConnectionString(new ConnectionString(connectionString))
            .serverApi(serverApi)
            .build();
    
        try (MongoClient mongoClient = MongoClients.create(settings)) {
            MongoDatabase database = mongoClient.getDatabase("ecommercedb");
            MongoCollection<Document> productsCollection = database.getCollection("products");
            MongoCollection<Document> reviewsCollection = database.getCollection("reviews");
    
            productsCollection.find().forEach((Consumer<Document>) document -> {
                String productId = document.getString("product_id");
                String productName = document.getString("name");
                List<Document> reviews = document.getList("reviews", Document.class);
    
                for (Document review : reviews) {
                    String message = review.getString("review");
                    int rating = review.getInteger("rating");
    
                    Document reviewDocument = new Document("product_id", productId)
                        .append("product_name", productName)
                        .append("review", message)
                        .append("rating", rating);
    
                    // Check if this review already exists in the reviews collection
                    Document existingReview = reviewsCollection.find(new Document("product_id", productId)
                            .append("review", message)
                            .append("rating", rating)).first();
    
                    if (existingReview == null) {
                        // If review does not exist, insert it
                        reviewsCollection.insertOne(reviewDocument);
                    }
                }
            });
    
            JOptionPane.showMessageDialog(this, "Reviews have been extracted and stored in the 'reviews' collection.");
        } catch (MongoException e) {
            Popup popup = new Popup("An error occurred while connecting to the database");
            popup.setLocationRelativeTo(null);
            popup.setVisible(true);
        } catch (Exception e) {
            // Popup popup = new Popup("An error occurred");
            // popup.setLocationRelativeTo(null);
            // popup.setVisible(true);
        }
    }
    
    

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        GetProductListButton = new javax.swing.JButton();
        CountProductsButton = new javax.swing.JButton();
        GetExpensiveProductsButton = new javax.swing.JButton();
        ExtractReviewsButton = new javax.swing.JButton();
        GoToReviewsButton = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        ProductList = new javax.swing.JList<>();
        CountProductsLabel = new javax.swing.JLabel();
        ProductNameLabel = new javax.swing.JLabel();
        ProductCategoryLabel = new javax.swing.JLabel();
        ProductPriceLabel1 = new javax.swing.JLabel();
        ProductStockLabel = new javax.swing.JLabel();
        ProductReviewsLabel = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        GetProductListButton.setText("Get Product List");
        GetProductListButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                GetProductListButtonMouseClicked(evt);
            }
        });

        CountProductsButton.setText("Count Products");
        CountProductsButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                CountProductsButtonMouseClicked(evt);
            }
        });

        GetExpensiveProductsButton.setText("Find Expensive Products");
        GetExpensiveProductsButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                GetExpensiveProductsButtonMouseClicked(evt);
            }
        });

        ExtractReviewsButton.setText("Extract Reviews");
        ExtractReviewsButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                ExtractReviewsButtonMouseClicked(evt);
            }
        });

        GoToReviewsButton.setText("Reviews");
        GoToReviewsButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                GoToReviewsButtonMouseClicked(evt);
            }
        });

        ProductList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                ProductListValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(ProductList);

        ProductNameLabel.setText("Product Name:");

        ProductCategoryLabel.setText("Category:");

        ProductPriceLabel1.setText("Price:");

        ProductStockLabel.setText("Stock:");

        ProductReviewsLabel.setText("Number Of Reviews:");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(GetProductListButton, javax.swing.GroupLayout.PREFERRED_SIZE, 400, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 516, Short.MAX_VALUE)
                        .addComponent(GoToReviewsButton))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(ProductStockLabel, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(ProductPriceLabel1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(CountProductsButton, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 400, Short.MAX_VALUE)
                            .addComponent(GetExpensiveProductsButton, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 400, Short.MAX_VALUE)
                            .addComponent(ExtractReviewsButton, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 400, Short.MAX_VALUE)
                            .addComponent(CountProductsLabel, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(ProductNameLabel, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(ProductCategoryLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(ProductReviewsLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane1)))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(GetProductListButton, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(GoToReviewsButton))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(GetExpensiveProductsButton, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(ExtractReviewsButton, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(CountProductsButton, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(CountProductsLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(ProductNameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(ProductPriceLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(ProductCategoryLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(ProductStockLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(ProductReviewsLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 238, Short.MAX_VALUE))
                    .addComponent(jScrollPane1))
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

    private void ProductListValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_ProductListValueChanged
        Product product = ProductList.getSelectedValue();
        DisplayProductIOnDetail(product);
    }//GEN-LAST:event_ProductListValueChanged

    private void GetProductListButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_GetProductListButtonMouseClicked
        products.clear();

        GetProductListButton.setEnabled(false);
        GetProductListButton.setText("Fetching Products...");
        populateProductList();
        GetProductListButton.setEnabled(true);
        GetProductListButton.setText("Get Product List");
    }// GEN-LAST:event_GetProductListButtonMouseClicked

    private void CountProductsButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_CountProductsButtonMouseClicked
        CountProductsButton.setEnabled(false);
        CountProductsButton.setText("Counting Products...");
        countProducts();
        CountProductsButton.setEnabled(true);
        CountProductsButton.setText("Count Products");
    }// GEN-LAST:event_CountProductsButtonMouseClicked

    private void GetExpensiveProductsButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_GetExpensiveProductsButtonMouseClicked
        products.clear();

        GetExpensiveProductsButton.setEnabled(false);
        GetExpensiveProductsButton.setText("Fetching Expensive Products...");
        findExpensiveProducts();
        GetExpensiveProductsButton.setEnabled(true);
        GetExpensiveProductsButton.setText("Find Expensive Products");
    }// GEN-LAST:event_GetExpensiveProductsButtonMouseClicked

    private void ExtractReviewsButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_ExtractReviewsButtonMouseClicked
        extractReviews();
    }// GEN-LAST:event_ExtractReviewsButtonMouseClicked

    private void GoToReviewsButtonMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_GoToReviewsButtonMouseClicked
        Reviews reviews = new Reviews();
        reviews.setLocationRelativeTo(null);
        reviews.setVisible(true);
        this.dispose();
    }// GEN-LAST:event_GoToReviewsButtonMouseClicked

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
            java.util.logging.Logger.getLogger(Products.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Products.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Products.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Products.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        // </editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Products().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton CountProductsButton;
    private javax.swing.JLabel CountProductsLabel;
    private javax.swing.JButton ExtractReviewsButton;
    private javax.swing.JButton GetExpensiveProductsButton;
    private javax.swing.JButton GetProductListButton;
    private javax.swing.JButton GoToReviewsButton;
    private javax.swing.JLabel ProductCategoryLabel;
    private javax.swing.JList<Product> ProductList;
    private javax.swing.JLabel ProductNameLabel;
    private javax.swing.JLabel ProductPriceLabel1;
    private javax.swing.JLabel ProductReviewsLabel;
    private javax.swing.JLabel ProductStockLabel;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration//GEN-END:variables
}
