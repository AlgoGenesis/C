# Viterbi Algorithm (Hidden Markov Model)

This C program demonstrates the implementation of the Viterbi algorithm for finding the most probable sequence of hidden states in a Hidden Markov Model (HMM), given a sequence of observed events. The algorithm operates efficiently with a time complexity of O(T * N^2), where T is the length of the observation sequence and N is the number of states in the HMM.

The Viterbi algorithm is a classical algorithm used in various fields such as natural language processing, bioinformatics, and speech recognition. It works by utilizing dynamic programming to compute the most likely sequence of hidden states that results in the observed sequence.

## Key Operations:
- **Initialization:** Sets the initial probabilities for the states based on the starting distribution and the first observation.
- **Recursion:** Iteratively computes the maximum probabilities of reaching each state at each time step based on previous states and their transition probabilities.
- **Backtracking:** Traces back the most probable path of hidden states once the probabilities have been computed for the entire observation sequence.

## Sample Input and Output
Consider a scenario where there are 3 states and a sequence of 5 observations. The program will calculate the most probable sequence of hidden states based on the given probabilities.

**Sample Observations:**  
`O = [0, 1, 2, 1, 0]`

**Sample Probabilities:**  
- Start probabilities: `P(start) = [0.6, 0.3, 0.1]`
- Transition probabilities:  
P(trans) = { {0.7, 0.2, 0.1}, {0.3, 0.5, 0.2}, {0.3, 0.3, 0.4} }
- Emission probabilities:  
P(emit) = { {0.5, 0.4, 0.1, 0.2, 0.3}, {0.1, 0.3, 0.6, 0.2, 0.5}, {0.2, 0.2, 0.2, 0.5, 0.3} }

**Program Output:**

This output indicates the most probable sequence of hidden states for the provided observations.

Most probable path of states: 0 1 2 1 0

## Example:
1. **Define the Hidden Markov Model:**
   - **States:** Three hidden states represented as {0, 1, 2}.
   - **Observations:** A sequence of observed events.

2. **Algorithm Execution:**
   - The algorithm initializes probabilities based on the first observation, then iteratively calculates the most probable paths through the states for each observation using dynamic programming.
   - After processing the entire observation sequence, it reports the most likely path of hidden states.

## Time Complexity:
- **Initialization:** The initialization takes **O(N)** time, where **N** is the number of states.
- **Recursion:** For each observation, the algorithm updates the probabilities for all states, resulting in a time complexity of **O(N^2)** for each observation.
- **Overall Complexity:** The algorithm runs in **O(T * N^2)**, making it suitable for moderate lengths of observation sequences and state spaces.

## Key Features:
- **Dynamic Programming:** The Viterbi algorithm uses dynamic programming to optimize the search for the most probable hidden states.
- **Adaptability:** The algorithm can be adapted to various problems involving sequential data and probabilistic modeling.

## Applications:
- **Natural Language Processing:** Used in part-of-speech tagging and speech recognition.
- **Bioinformatics:** For gene prediction and sequence alignment.
- **Finance:** In modeling and predicting market trends based on time-series data.
