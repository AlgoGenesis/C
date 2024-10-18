# Gale-Shapley Algorithm (Stable Marriage Problem)

## Overview

The **Gale-Shapley Algorithm**, also known as the **Deferred Acceptance Algorithm**, is a solution to the Stable Marriage Problem. This problem involves finding a stable matching between two equally sized sets of elements (e.g., men and women), where each member of both sets has a ranked preference list for the members of the opposite set. A matching is stable if there are no two members who would prefer each other over their current partners.

This implementation provides a simple console application that allows users to input preferences for a specified number of men and women and then computes stable pairings using the Gale-Shapley Algorithm.

## Features

- **Stable Matchings**: Ensures that the resulting pairs are stable, meaning no two people would prefer each other over their current partners.
- **Interactive Input**: Users can enter their preference lists for both men and women via the console.
- **Clear Output**: Displays the final engagements clearly in the console.

## Prerequisites

- A C compiler (e.g., GCC) installed on your system.
- Basic knowledge of how to compile and run C programs.

### Input Format

1. The program first prompts for the number of men/women (both sets must be of equal size).
2. Next, it asks for the preferences of the men:
   - For each man, enter his preference list as space-separated integers corresponding to the indices of the women.
3. The program then asks for the preferences of the women:
   - Similarly, for each woman, enter her preference list as space-separated integers corresponding to the indices of the men.

### Example Input

```plaintext
Enter the number of men/women: 4
Enter preferences of men (0 to 3):
Man 0: 0 1 2 3
Man 1: 1 0 3 2
Man 2: 2 3 0 1
Man 3: 3 2 1 0
Enter preferences of women (0 to 3):
Woman 0: 0 1 2 3
Woman 1: 1 0 3 2
Woman 2: 2 3 0 1
Woman 3: 3 2 1 0
```

### Example Output

```plaintext
Engagements:
Man 0 is engaged to Woman 0
Man 1 is engaged to Woman 1
Man 2 is engaged to Woman 2
Man 3 is engaged to Woman 3
```

## Algorithm Explanation

The Gale-Shapley Algorithm follows these steps:

1. **Initialization**: 
   - Each man is initially free and proposes to the highest-ranked woman on his preference list that he hasn't yet proposed to.
   - Each woman is also initially free.

2. **Proposal Process**:
   - A free man proposes to a woman. If the woman is free, they become engaged.
   - If the woman is already engaged, she compares her current engagement with the new proposal. If she prefers the new man, she switches her engagement to the new man, making her previous partner free.

3. **Iteration**:
   - This process repeats until there are no free men left to propose. At this point, the algorithm guarantees a stable matching.

4. **Output**:
   - Finally, the program prints out the engagements between men and women.

## Complexity

- **Time Complexity**: The algorithm runs in \(O(n^2)\) time, where \(n\) is the number of men or women, since each man can propose to all women in the worst case.
- **Space Complexity**: The space complexity is \(O(n)\) for storing preference lists and engagements.

## Limitations

- The algorithm assumes that all men and women rank every member of the opposite set, and that there are no ties in preferences. 
- If the number of men and women is not equal, the algorithm will not work correctly.

