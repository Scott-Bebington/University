
The goal of this project is to create 2 algorithms to find a solution to the Travelling salesman problem (TSP)

The two algorithms being used are:
1. Iterated Local Search (ILS)
2. Simulated Annealing (SA)

The project is being developed in Java.

1. Iterated Local Search (ILS)
The Iterated Local Search algorithm is a metaheuristic that iteratively improves a candidate solution by applying a local search algorithm and perturbing the solution. The algorithm is as follows:
1. Generate an initial solution
2. Apply a local search algorithm to the solution
3. Perturb the solution (in this case by swapping 2 random campuses)
4. Apply the local search algorithm to the perturbed solution 
5. If the new solution is better than the current solution, replace the current solution with the new solution
6. Repeat steps 3-5 until a stopping criterion is met or a maximum number of iterations is reached

Note: in this case i have only perturbed the solution by swapping 2 random campuses as swapping 2 adjacent campuses and then swapping 2 random 
campuses may result in swapping the 2 adjacent campuses back to their original position, this would make no progress and may cause the algorithm to terminate early due to the stopping criteria.

2. Simulated Annealing (SA)
The Simulated Annealing algorithm is a probabilistic metaheuristic that is inspired by the annealing process in metallurgy. The algorithm is as follows:
1. Generate an initial solution
2. Set the initial temperature and cooling rate
3. Repeat until the stopping criterion is met: (In this case when the temp value gets lower than 1 i.e. the temperature is too low to accept any new solution)
    a. Generate 3 new solutions by swapping random campuses
    b. Get the best route from the 3 new solutions
    b. Calculate the cost difference between the new solution and the current solution
    c. If the new solution is better than the current solution, replace the current solution with the new solution
    d. If the new solution is worse than the current solution, accept the new solution with a probability based on the cost difference and the current temperature
    e. Update the temperature


