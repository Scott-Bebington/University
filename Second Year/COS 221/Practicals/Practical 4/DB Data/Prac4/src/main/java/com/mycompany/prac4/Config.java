/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prac4;

/**
 *
 * @author scott
 */
public class Config {
    private final String DBURL = "jdbc:mariadb://localhost:3306/u21546216_sakila";
    private final String Username = "root";
    private final String Password = "Scott25121";
    private final String classname = "org.mariadb.jdbc.Driver";

    public String getDBURL() {
        return DBURL;
    }

    public String getUsername() {
        return Username;
    }

    public String getPassword() {
        return Password;
    }

    public String getClassName() {
        return classname;
    }
}

