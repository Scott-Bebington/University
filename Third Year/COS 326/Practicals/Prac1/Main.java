/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author scott
 * To run
 * cd src/prac1
 * javac -cp ../../objectdb.jar *.java
 * java -classpath ".;../../objectdb.jar" Prac1.java
 * rm *.class
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CreateTransaction createTransaction = new CreateTransaction();
        createTransaction.setLocationRelativeTo(null);
        createTransaction.setVisible(true);
    }
    
}
