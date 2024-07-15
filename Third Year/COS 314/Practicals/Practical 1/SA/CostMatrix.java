import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class CostMatrix {
    int[][] costMatrix = {
            { 0, 15, 20, 22, 30 },
            { 15, 0, 10, 12, 25 },
            { 20, 10, 0, 8, 22 },
            { 22, 12, 8, 0, 18 },
            { 30, 25, 22, 18, 0 }
    };

    String[] CampusHeadings = { "Hatfield", "Hillcrest", "Groenkloof", "Prinsof", "Mamelodi" };
    // String[] Campuses = { "Hatfield", "Groenkloof", "Hillcrest", "Prinsof", "Mamelodi" };
    String[] Campuses = { "Hatfield", "Groenkloof", "Prinsof", "Hillcrest", "Mamelodi" };

    /**
     * Randomize the campuses in the Area but keep hetfield as the starting campus
     */
    public void randomizeCampuses() {
        List<String> campusesList = new ArrayList<>(Arrays.asList(Campuses));
        campusesList.remove("Hatfield"); // Remove Hatfield from the list
        Collections.shuffle(campusesList); // Shuffle the remaining campuses
        campusesList.add(0, "Hatfield"); // Add Hatfield back to the beginning
        Campuses = campusesList.toArray(new String[0]); // Convert the list back to an array
    }

    @Override
    /**
     * To print out a list of all the cities in the area
     * 
     * @return a string of all the cities in the area ina list ending at the start
     *         campus
     */
    public String toString() {
        String s = "";
        for (int i = 0; i < Campuses.length; i++) {
            s += Campuses[i] + " -> ";
        }
        s += Campuses[0];
        return s;
    }

    /**
     * To get the total distance of the path taken to visit each campus
     * 
     * @return the total distance of the path
     */
    public int getTotalDistance() {
        int distance = 0;
        for (int i = 0; i < Campuses.length - 1; i++) {

            distance += getCost(Campuses[i], Campuses[i + 1]);
            // System.out.println("Distance between " + Campuses[i] + " and " + Campuses[i +
            // 1] + " is "
            // + getCost(Campuses[i], Campuses[i + 1]));
        }
        distance += getCost(Campuses[Campuses.length - 1], Campuses[0]);
        // System.out.println("Distance between " + Campuses[Campuses.length - 1] + "
        // and " + Campuses[0] + " is "
        // + getCost(Campuses[Campuses.length - 1], Campuses[0]));
        return distance;
    }

    /**
     * To get the cost of travelling from one campus to another
     * 
     * @param from the campus you are travelling from
     * @param to   the campus you are travelling to
     * @return the cost of travelling from one campus to another
     */
    public int getCost(String from, String to) {
        int fromIndex = -1;
        int toIndex = -1;
        for (int i = 0; i < CampusHeadings.length; i++) {
            if (CampusHeadings[i].equals(from)) {
                fromIndex = i;
            }
            if (CampusHeadings[i].equals(to)) {
                toIndex = i;
            }
        }
        return costMatrix[fromIndex][toIndex];
    }

    /**
     * To swap two campuses randomly
     */
    public void swapCampusesRandomly() {
        int i = Maths.randomInt(1, 4);
        int j = Maths.randomInt(1, 4);
        while (i == j) {
            j = Maths.randomInt(1, 4);
        }

        // System.out.println("Swapping " + Campuses[i] + " and " + Campuses[j]);

        String temp = Campuses[i];
        Campuses[i] = Campuses[j];
        Campuses[j] = temp;
    }

}
