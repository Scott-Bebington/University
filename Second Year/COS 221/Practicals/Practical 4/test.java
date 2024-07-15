import java.sql.*;

public class test {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;

        String url = "jdbc:mysql://172.0.0.1:3306/sakila";
        String user = "root";
        String password = "password";

        try {
            conn = DriverManager.getConnection(url, user, password);
            stmt = conn.createStatement();

            String sql = "SELECT s.first_name AS Name, s.last_name AS Surname, a.phone AS Phone, " +
                    "a.address AS Address, a.address2 AS Address_2, a.district AS District, " +
                    "c.city AS City, a.postal_code AS Postal_Code, s.store_id AS Store_ID, s.active AS Active " +
                    "FROM sakila.staff s " +
                    "JOIN sakila.address a ON s.address_id = a.address_id " +
                    "JOIN sakila.city c ON a.city_id = c.city_id " +
                    "ORDER BY Name, Surname, Phone, Address, Address_2, District, City, Postal_Code, Store_ID, Active";

            rs = stmt.executeQuery(sql);

            while (rs.next()) {
                String name = rs.getString("Name");
                String surname = rs.getString("Surname");
                String phone = rs.getString("Phone");
                String address = rs.getString("Address");
                String address2 = rs.getString("Address_2");
                String district = rs.getString("District");
                String city = rs.getString("City");
                String postalCode = rs.getString("Postal_Code");
                int storeID = rs.getInt("Store_ID");
                int active = rs.getInt("Active");

                System.out.println(name + " " + surname + " " + phone + " " + address + " " +
                        address2 + " " + district + " " + city + " " + postalCode + " " + storeID + " " + active);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                if (rs != null) {
                    rs.close();
                }
                if (stmt != null) {
                    stmt.close();
                }
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
