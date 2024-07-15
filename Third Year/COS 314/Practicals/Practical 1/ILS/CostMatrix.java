import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class CostMatrix {

    String[] CampusHeadings = { "Hatfield", "Hillcrest", "Groenkloof", "Prinsof", "Mamelodi" };
    int[][] costMatrix = {
            { 0, 15, 20, 22, 30 },
            { 15, 0, 10, 12, 25 },
            { 20, 10, 0, 8, 22 },
            { 22, 12, 8, 0, 18 },
            { 30, 25, 22, 18, 0 }
    };

    /**
     * General initial solution
     */
    String[] InitialPath = {"Groenkloof", "Hillcrest", "Prinsof", "Mamelodi" };
    Random random = new Random(1234);
    String[] bestPath = Arrays.copyOf(InitialPath, InitialPath.length);

    /**
     * Randomize the campuses in the Area but keep hetfield as the starting campus
     * I wont be using this as i cant set a seed for the randomization of the campuses
     * Instead i will set the "Random" initial solution as the initial path
     */
    public void randomizeCampuses() {
        List<String> campusesList = new ArrayList<>(Arrays.asList(InitialPath));
        campusesList.remove("Hatfield"); // Remove Hatfield from the list
        Collections.shuffle(campusesList); // Shuffle the remaining campuses
        campusesList.add(0, "Hatfield"); // Add Hatfield back to the beginning
        InitialPath = campusesList.toArray(new String[0]); // Convert the list back to an array
    }

    /**
     * Iterated Local Search Algorithm
     * @return the best path found
     */
    public String[] iteratedLocalSearch() {
        String[] bestPath = Arrays.copyOf(InitialPath, InitialPath.length);
        int bestCost = calculateCost(bestPath);
        int countIterations = 0;
        int totalCount = 0;
        int toalCost = 0;
        for (int i = 0; i < 100; i++) {
            totalCount++;
            String[] newPath = perturb(bestPath);
            int newCost = calculateCost(newPath);

            if (newCost < bestCost) {
                // System.out.println("New best cost: " + newCost);
                bestPath = Arrays.copyOf(newPath, newPath.length);
                bestCost = newCost;
                countIterations = 0;
                System.out.println("New Best Path: " + Arrays.toString(bestPath));
            }

            /**
             * If the cost has not improved for 15 iterations, break out of the loop (Acceptance Criteria)
             */
            if (countIterations >= 15) {
                break;
            }

            countIterations++;

            /**
             * For testing purposes, to be commented out
             */
            // CostMatrix test = new CostMatrix();
            // test.bestPath = bestPath;
            // // System.out.println("Total Iterations: " + totalCount);
            // System.out.println("Current Path: " + test);
            toalCost += newCost;
        }

        System.out.println("Average Cost: " + toalCost / totalCount);
        System.out.println("Best Path: " + Arrays.toString(bestPath));
        return bestPath;
    }

    /**
     * Perturb the path by swapping two random campuses
     * If the two campuses are the same, keep generating a new random index until they are different
     * @param path
     * @return the new path after the swapped campuses
     */
    private String[] perturb(String[] path) {
        String[] newPath = Arrays.copyOf(path, path.length);

        int index1 = random.nextInt(newPath.length);
        int index2 = random.nextInt(newPath.length);

        while (index1 == index2) {
            index2 = random.nextInt(newPath.length);
        }

        // System.out.println("Swapping " + newPath[index1] + " and " + newPath[index2]);

        String temp = newPath[index1];
        newPath[index1] = newPath[index2];
        newPath[index2] = temp;

        return newPath;
    }

    /**
     * Calculate the cost of the path starting and ending at Hatfield
     * @param path
     * @return
     */
    public int calculateCost(String[] path) {
        int cost = costMatrix[getIndex("Hatfield")][getIndex(path[0])];

        for (int i = 0; i < path.length - 1; i++) {
            int fromIndex = getIndex(path[i]);
            int toIndex = getIndex(path[i + 1]);
            cost += costMatrix[fromIndex][toIndex];
        }

        cost += costMatrix[getIndex(path[path.length - 1])][getIndex("Hatfield")];

        return cost;
    }

    /**
     * Get the index of the campus in the CampusHeadings array
     * @param campus
     * @return the index of the campus
     */
    private int getIndex(String campus) {
        for (int i = 0; i < CampusHeadings.length; i++) {
            if (CampusHeadings[i].equals(campus)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Print the path being taken
     */
    @Override
    public String toString() {
        String s = "Hatfield -> ";
        for (int i = 0; i < InitialPath.length; i++) {
            s += InitialPath[i] + " -> ";
        }
        s += "Hatfield";
        return s;
    }

    
}
