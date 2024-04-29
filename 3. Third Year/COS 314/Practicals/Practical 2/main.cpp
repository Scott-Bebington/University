#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Item
{
    double value;
    double weight;
};

// Function to initialize population
vector<vector<double>> initialize_population(int population_size, int num_items)
{
    vector<vector<double>> population;

    for (int i = 0; i < population_size; ++i)
    {
        vector<double> chromosome;
        for (int j = 0; j < num_items; ++j)
        {
            chromosome.push_back(rand() % 2);
        }
        population.push_back(chromosome);
    }
    return population;
}

// Function to evaluate fitness
vector<double> evaluate_fitness(const vector<vector<double>> &population, const vector<Item> &items, int knapsack_capacity)
{

    vector<double> fitness_scores;
    for (const auto &chromosome : population)
    {

        double total_weight = 0;
        double total_value = 0;

        for (int i = 0; i < chromosome.size(); ++i)
        {
            if (chromosome[i] == 1)
            {
                total_weight += items[i].weight; // Weight of the item
                total_value += items[i].value;   // Value of the item

                // cout << "Item " << i << ": " << items[i].value << " " << items[i].weight << endl;
            }
        }

        if (total_weight > knapsack_capacity)
        {
            fitness_scores.push_back(0); // If the weight of the items exceeds the capacity, fitness score is 0
        }
        else
        {

            fitness_scores.push_back(total_value); // Fitness score is the total value of the items
        }
    }
    return fitness_scores;
}

// Function for selection
vector<vector<double>> selection(const vector<vector<double>> &population, const vector<double> &fitness_scores)
{
    vector<vector<double>> selected_parents;
    int total_fitness = accumulate(fitness_scores.begin(), fitness_scores.end(), 0);

    if (total_fitness == 0)
    {
        // If total fitness is 0, select parents randomly
        for (int i = 0; i < population.size(); ++i)
        {
            int rand_index = rand() % population.size();
            selected_parents.push_back(population[rand_index]);

            // introduce a few new people with all 0 chromosomes to make the items in the knapsack decrease with the crossover
            if (rand() % 1000 <= 1)
            {
                vector<double> new_person(population[0].size(), 0);
                selected_parents.push_back(new_person);
            }
        }
    }
    else
    {
        for (int i = 0; i < population.size(); ++i)
        {
            int rand_num = rand() % total_fitness;
            int cumulative_prob = 0;
            for (int j = 0; j < population.size(); ++j)
            {
                cumulative_prob += fitness_scores[j];
                if (cumulative_prob > rand_num)
                {
                    selected_parents.push_back(population[j]);
                    break;
                }
            }
        }
    }
    return selected_parents;
}

// Function for crossover
vector<vector<double>> crossover(const vector<vector<double>> &selected_parents)
{
    vector<vector<double>> newGeneration;

    for (int i = 0; i < selected_parents.size(); i += 2)
    {
        if (i + 1 >= selected_parents.size())
        {
            break;
        }
        vector<double> child1, child2, parent1 = selected_parents[i], parent2 = selected_parents[i + 1];
        int crossover_point = rand() % (selected_parents[0].size() - 1) + 1; // Random crossover point between 1 and n - 1

        for (int j = 0; j < crossover_point; ++j)
        {
            child1.push_back(parent1[j]);
            child2.push_back(parent2[j]);
        }

        for (int j = crossover_point; j < parent1.size(); ++j)
        {
            child1.push_back(parent2[j]);
            child2.push_back(parent1[j]);
        }

        newGeneration.push_back(child1);
        newGeneration.push_back(child2);
    }

    return newGeneration;
}

// Function for mutation
vector<vector<double>> mutate(const vector<vector<double>> &newGeneration)
{
    vector<vector<double>> newGenerationMutated;

    for (const auto &chromosome : newGeneration)
    {
        vector<double> mutatedChromosome;
        for (int gene : chromosome)
        {
            if (rand() % 1000 <= 1)
            { // 10 in 1000 chance of mutation happening
                mutatedChromosome.push_back(1 - gene);
            }
            else
            {
                mutatedChromosome.push_back(gene);
            }
        }
        newGenerationMutated.push_back(mutatedChromosome);
    }
    return newGenerationMutated;
}

// Function to select the best solution
vector<double> select_best_solution(const vector<vector<double>> &population, const vector<Item> &items, int knapsack_capacity)
{

    // Sort the population based on fitness scores
    vector<double> fitness_scores = evaluate_fitness(population, items, knapsack_capacity);
    vector<pair<int, vector<double>>> population_with_fitness;
    for (int i = 0; i < population.size(); ++i)
    {
        population_with_fitness.push_back({fitness_scores[i], population[i]});
    }
    sort(population_with_fitness.begin(), population_with_fitness.end(), greater<pair<int, vector<double>>>());

    // Select the best solution
    return population_with_fitness[0].second;
}

void applyHillClimb(vector<vector<double>> &population, const vector<Item> &items, int knapsack_capacity)
{
    for (auto &chromosome : population)
    {
        bool improved = true;
        while (improved)
        {
            improved = false;
            for (int i = 0; i < chromosome.size(); ++i)
            {
                // Flip the value of the gene
                chromosome[i] = 1 - chromosome[i];

                // Evaluate the fitness of the modified chromosome
                double new_fitness = evaluate_fitness({chromosome}, items, knapsack_capacity)[0];

                // If the new fitness is better, keep the modification
                if (new_fitness > evaluate_fitness({chromosome}, items, knapsack_capacity)[0])
                {
                    improved = true;
                }
                else
                {
                    // Revert the modification
                    chromosome[i] = 1 - chromosome[i];
                }
            }
        }
    }
}

int main()
{

    vector<tuple<string, double, unsigned int>> problemInstances = {
        {"f1_l-d_kp_10_269", 295, 1714247743},
        {"f2_l-d_kp_20_878", 1024, 1714241775},
        {"f3_l-d_kp_4_20", 35, 1714241775},
        {"f4_l-d_kp_4_11", 23, 1714241775},
        {"f5_l-d_kp_15_375", 481.0694, 1714245778},
        {"f6_l-d_kp_10_60", 52, 1714241775},
        {"f7_l-d_kp_7_50", 107, 1714302749},
        {"f8_l-d_kp_23_10000", 9767, 1714302872},
        {"f9_l-d_kp_5_80", 130, 1714241775},
        {"f10_l-d_kp_20_879", 1025, 1714245778},
        {"knapPI_1_100_1000_1", 9147, 1714241776}};

    unsigned int seed = -1;
    cout << "Enter seed value (or press Enter to use default): ";
    string input;
    getline(cin, input);

    cout << endl
         << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Problem Instance\t| Algorithm\t| Seed Value\t| Best Solution\t| Known Optimum\t| Runtime (Seconds)\t|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

    for (int k = 0; k < problemInstances.size(); k++)
    {

        // Get the start time of the program
        clock_t start = clock();
        // srand(time(0)); // Set seed for random number generation
        // cout << "Seed Value: " << time(0) << endl;

        if (!input.empty())
            seed = stoi(input);
        else
            seed = get<2>(problemInstances[k]);

        srand(seed);

        string filename = get<0>(problemInstances[k]);
        double known_optimum = get<1>(problemInstances[k]);

        ifstream file(filename);
        int num_items, knapsack_capacity;
        file >> num_items >> knapsack_capacity;

        vector<Item> items(num_items);
        for (int i = 0; i < num_items; ++i)
        {
            file >> items[i].value >> items[i].weight;
            // cout << items[i].value << " " << items[i].weight << endl;
        }
        file.close();

        // for (int i = 0; i < num_items; ++i)
        // {
        //     cout << items[i].value << " " << items[i].weight << endl;
        // }

        // int population_size = num_items;
        int population_size = 100;
        int generations = 1000;

        vector<vector<double>> population = initialize_population(population_size, num_items), selected_parents, newGeneration, mutated_newGeneration;
        vector<double> best_solution, fitness_scores;

        int currentGeneration = 0;
        // GA
        for (int generation = 0; generation < generations; ++generation)
        {

            fitness_scores = evaluate_fitness(population, items, knapsack_capacity);

            // for (int i = 0; i < fitness_scores.size(); ++i)
            // {
            //     cout << "Chromosome " << i << ": " << fitness_scores[i] << endl;
            // }

            selected_parents = selection(population, fitness_scores);

            newGeneration = crossover(selected_parents);

            mutated_newGeneration = mutate(newGeneration);

            population = mutated_newGeneration;

            best_solution = select_best_solution(population, items, knapsack_capacity);

            if (evaluate_fitness({best_solution}, items, knapsack_capacity)[0] == known_optimum)
            {
                // cout << "Generation: " << generation << "\n";
                break;
            }
        }

        clock_t end = clock();

        // This is done purely for formatting to make it look nice
        if (filename == "f5_l-d_kp_15_375")
            cout << "| " << filename << "\t| GA\t\t| " << seed << "\t| " << evaluate_fitness({best_solution}, items, knapsack_capacity)[0] << "\t| " << known_optimum << "\t| " << (double)(end - start) / CLOCKS_PER_SEC << "\t\t| " << endl;
        else
            cout << "| " << filename << "\t| GA\t\t| " << seed << "\t| " << evaluate_fitness({best_solution}, items, knapsack_capacity)[0] << "\t\t| " << known_optimum << "\t\t| " << (double)(end - start) / CLOCKS_PER_SEC << "\t\t| " << endl;

        start = clock();

        population = initialize_population(population_size, num_items), selected_parents, newGeneration, mutated_newGeneration;

        // GA + Local search
        for (int generation = 0; generation < generations; ++generation)
        {
            applyHillClimb(population, items, knapsack_capacity);

            fitness_scores = evaluate_fitness(population, items, knapsack_capacity);

            selected_parents = selection(population, fitness_scores);

            newGeneration = crossover(selected_parents);

            mutated_newGeneration = mutate(newGeneration);

            population = mutated_newGeneration;

            best_solution = select_best_solution(population, items, knapsack_capacity);

            if (evaluate_fitness({best_solution}, items, knapsack_capacity)[0] == known_optimum)
            {
                break;
            }
        }

        end = clock();

        // This is done purely for formatting to make it look nice
        if (filename == "f5_l-d_kp_15_375")
            cout << "| " << filename << "\t| GA + LS\t| " << seed << "\t| " << evaluate_fitness({best_solution}, items, knapsack_capacity)[0] << "\t| " << known_optimum << "\t| " << (double)(end - start) / CLOCKS_PER_SEC << "\t\t| " << endl;
        else
            cout << "| " << filename << "\t| GA + LS\t| " << seed << "\t| " << evaluate_fitness({best_solution}, items, knapsack_capacity)[0] << "\t\t| " << known_optimum << "\t\t| " << (double)(end - start) / CLOCKS_PER_SEC << "\t\t| " << endl;

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    }

    return 0;
}
