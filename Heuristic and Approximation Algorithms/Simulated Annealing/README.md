# Simulated Annealing Algorithm

## About
Simulated Annealing is a probabilistic optimization algorithm that attempts to find a near-optimal solution by iteratively exploring neighboring solutions. It mimics the annealing process in metallurgy.

### Algorithm Overview:
1. Initialize with a random solution and a high temperature.
2. At each iteration, generate a neighboring solution.
3. If the new solution is better, accept it.
4. If the new solution is worse, accept it with a probability that decreases with the temperature.
5. Gradually cool down the system (reduce temperature) and repeat.
6. Terminate after a certain number of iterations or when the system cools.

### C Code
The implementation is straightforward and follows the steps described above. See the `simulated_annealing.c` file for the code.
