import java.util.Arrays;

public class ILS {
    public static void main(String[] args) {
        CostMatrix costMatrix = new CostMatrix();
        // costMatrix.randomizeCampuses();

        System.out.println("\nInitial Path: " + costMatrix);
        System.out.println("Initial Cost: " + costMatrix.calculateCost(costMatrix.InitialPath));

        CostMatrix BestPath = new CostMatrix();
        // BestPath.bestPath = costMatrix.iteratedLocalSearch();
        // System.out.println("Best Path test: " + BestPath);
        // int bestCost = costMatrix.calculateCost(BestPath.bestPath);

        // System.out.println("\nBest Path: " + BestPath);
        // System.out.println("Best Cost: " + bestCost);
        System.out.println("Best Path: " + Arrays.toString(costMatrix.iteratedLocalSearch()));
    }
}
