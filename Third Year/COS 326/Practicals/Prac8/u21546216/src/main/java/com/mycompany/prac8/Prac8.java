/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prac8;

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
import org.json.JSONArray;
import org.json.JSONObject;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Prac8 {

    public static void main(String[] args) {
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

                // Check if the collection is empty, if yes, create it and insert data
                if (collection.countDocuments() == 0) {
                    // Read the JSON file content
                    String jsonFilePath = "EcommerceData.json";
                    String content = new String(Files.readAllBytes(Paths.get(jsonFilePath)));

                    // Parse the JSON data
                    JSONObject jsonObject = new JSONObject(content);
                    JSONArray productsArray = jsonObject.getJSONArray("products");

                    // Prepare the list of documents to insert
                    List<Document> documents = new ArrayList<>();
                    for (int i = 0; i < productsArray.length(); i++) {
                        JSONObject product = productsArray.getJSONObject(i);
                        Document document = Document.parse(product.toString());
                        documents.add(document);
                    }

                    // Insert the documents into the collection
                    collection.insertMany(documents);
                    System.out.println("Data inserted successfully!");
                } else {
                    System.out.println("Collection already has data.");
                }

            } catch (MongoException e) {
                Popup popup = new Popup("Error connecting to MongoDB: ");
                popup.setLocationRelativeTo(null);
                popup.setVisible(true);
                return;
            } catch (Exception e) {
                Popup popup = new Popup("Could not add the content to the database");
                popup.setLocationRelativeTo(null);
                popup.setVisible(true);
                return;
            }
        }

        Products products = new Products();
        products.setLocationRelativeTo(null);
        products.setVisible(true);

    }
}

class Product {
    private String product_id;
    private String name;
    private String category;
    private double price;
    private Integer stock;
    private List<Review> reviews;

    public Product(String product_id, String name, String category, double price, int stock, List<Review> reviews) {
        this.product_id = product_id;
        this.name = name;
        this.category = category;
        this.price = price;
        this.stock = stock;
        this.reviews = reviews;
    }

    public String getProduct_id() {
        return product_id;
    }

    public void setProduct_id(String product_id) {
        this.product_id = product_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public List<Review> getReviews() {
        return reviews;
    }

    public void setReviews(List<Review> reviews) {
        this.reviews = reviews;
    }

    public String toString() {
        return name;
    }
}

class Review {
    private String product_id;
    private String product_name;
    private String review;
    private int rating;

    public Review(String product_id, String product_name, String review, int rating) {
        this.product_id = product_id;
        this.product_name = product_name;
        this.review = review;
        this.rating = rating;
    }

    public String getProduct_id() {
        return product_id;
    }

    public void setProduct_id(String product_id) {
        this.product_id = product_id;
    }

    public String getProduct_name() {
        return product_name;
    }

    public void setProduct_name(String product_name) {
        this.product_name = product_name;
    }

    public String getReview() {
        return review;
    }

    public void setReview(String review) {
        this.review = review;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public String toString() {
        return review;
    }
}
