public class SA {
    public static void main(String[] args) {
        CostMatrix intialTrip = new CostMatrix();
        // intialTrip.randomizeCampuses();
        System.out.println("\nInitial Path: " + intialTrip);
        System.out.println("Initial Distance: " + intialTrip.getTotalDistance());

        CostMatrix bestTrip = new CostMatrix();
        bestTrip.Campuses = intialTrip.Campuses.clone();
        int bestDistance = intialTrip.getTotalDistance();

        /**
         * Set the initial temperature, cooling rateand iteration count
         */
        double temp = 10;
        double coolingRate = 0.05;
        int count = 0;
        int totalCost = 0;

        while (temp > 1) {
            
            /**
             * Create 3 new trips to compare with the initial trip
             */
            CostMatrix newTrip1 = new CostMatrix();
            newTrip1.Campuses = intialTrip.Campuses.clone();
            CostMatrix newTrip2 = new CostMatrix();
            newTrip2.Campuses = intialTrip.Campuses.clone();
            CostMatrix newTrip3 = new CostMatrix();
            newTrip3.Campuses = intialTrip.Campuses.clone();

            CostMatrix newTrip = new CostMatrix();

            /**
             * Randomly swap 2 campuses for each new trip
             * Compare the 3 new trips and choose the best one
             */
            newTrip1.swapCampusesRandomly();
            newTrip2.swapCampusesRandomly();
            newTrip3.swapCampusesRandomly();

            int currentDistance = intialTrip.getTotalDistance();
            int neighbourDistance = newTrip1.getTotalDistance();
            newTrip.Campuses = newTrip1.Campuses.clone();

            if (neighbourDistance > newTrip2.getTotalDistance()) {
                neighbourDistance = newTrip2.getTotalDistance();
                newTrip.Campuses = newTrip2.Campuses.clone();
            }

            if (neighbourDistance > newTrip3.getTotalDistance()) {
                neighbourDistance = newTrip3.getTotalDistance();
                newTrip.Campuses = newTrip3.Campuses.clone();
            }

            /**
             * Decide whether to accept the new trip or not
             */
            double rand = Maths.randomDouble();
            if (Maths.acceptanceProbability(currentDistance, neighbourDistance, temp) > rand) {
                intialTrip.Campuses = newTrip.Campuses.clone();
            }

            /**
             * If the new trip is better than the best trip, update the best trip
             */
            if (intialTrip.getTotalDistance() < bestDistance) {
                bestTrip.Campuses = intialTrip.Campuses.clone();
                bestDistance = intialTrip.getTotalDistance();
            }

            /**
             * Output the cost after each iteration, to be used for plotting the graph
             * Will comment out when not needed
             */
            // System.out.println("y," + bestDistance);

            /**
             * "Cool" the temperature by the cooling rate
             */
            temp *= 1 - coolingRate;
            count++;
            totalCost += intialTrip.getTotalDistance();
        }

        System.out.println("\nFinal Path: " + bestTrip);
        System.out.println("Final distance: " + bestDistance);
        System.out.println("\nTotal iterations: " + count);
        System.out.println("Average cost: " + totalCost / count);
    }
}
