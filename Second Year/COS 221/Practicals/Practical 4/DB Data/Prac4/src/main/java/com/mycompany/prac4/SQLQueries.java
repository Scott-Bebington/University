/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prac4;

/**
 *
 * @author scott
 */
public class SQLQueries 
{
    private final String StaffPopulateStatement = "SELECT s.first_name AS Name, s.last_name AS Surname, a.phone AS Phone, "
            + "a.address AS Address, a.address2 AS Address_2, a.district AS District, "
            + "c.city AS City, a.postal_code AS Postal_Code, s.store_id AS Store_ID, "
            + "s.active AS Active "
            + "FROM u21546216_sakila.staff s "
            + "JOIN u21546216_sakila.address a ON s.address_id = a.address_id "
            + "JOIN u21546216_sakila.city c ON a.city_id = c.city_id "
            + "ORDER BY Name, Surname, Phone, Address, Address_2, District, City, Postal_Code, Store_ID, Active;";

    private final String FilmsPopulateStatement = "SELECT title AS Title, "
            + "description AS Description, "
            + "release_year AS Year, "
            + "rating AS Rating, "
            + "rental_rate AS 'Rental Cost', "
            + "replacement_cost AS 'Replacement Cost' "
            + "FROM film;";

    private String CheckClient = "";

    public String StaffPopulate() {
        return StaffPopulateStatement;
    }
    public String FIlmsPopulate()
    {
        return FilmsPopulateStatement;
    }
    public void setClientID(int ID)
    {
        CheckClient = "SELECT * FROM u21546216_sakila.customer "
                    + "WHERE customer_id = " + ID + ";";
    }
    public String getClient()
    {
        return CheckClient;
    }
}

