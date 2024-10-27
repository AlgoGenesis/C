# Battery Usage Optimization for Robots in a Grid

## Description
This program optimizes battery usage for a robot navigating a grid. The robot starts at the top-left corner and aims to reach the bottom-right corner while avoiding obstacles. The user can define the grid size and layout through input.

## Features
- Dynamic grid size input (up to a defined maximum).
- Input for grid values where:
  - `0` represents free space.
  - `1` represents obstacles.
- Outputs the path taken by the robot, including each step.

## Requirements
- C compiler (e.g., GCC)
- Standard C library

## Compilation and Execution
1. **Clone the repository** (if using a version control system) or download the source code file `optimize_battery_with_input.c`.
2. Open your terminal and navigate to the directory containing the source code.
3. Compile the program using:
   ```bash
   gcc optimize_battery_with_input.c -o optimize_battery_with_input

Run the executable:
bash
Copy code
./optimize_battery_with_input
Input Format
Grid Size: Enter the grid size (integer value).
Grid Values: Enter the grid values row by row, where:
0 indicates free space.
1 indicates an obstacle.
Example Input
java
Copy code
Enter grid size (max 10): 5
Enter grid values (0 for free, 1 for obstacle):
0 0 0 0 1
0 1 0 0 1
0 1 0 1 1
0 0 0 0 0
1 1 1 1 0
Output
The program will display the grid and the steps taken by the robot to reach the destination. If a valid path is found, it will show each move.

Example Output
java
Copy code
Grid:
0 0 0 0 1 
0 1 0 0 1 
0 1 0 1 1 
0 0 0 0 0 
1 1 1 1 0 
Starting optimization from (0, 0):
Moving to (0, 1)
Moving to (0, 2)
Moving to (0, 3)
Moving to (1, 3)
Moving to (2, 3)
Moving to (3, 3)
Moving to (4, 3)
Moving to (4, 4)
Reached destination at (4, 4)
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Thanks to the open-source community for their invaluable contributions.
css
Copy code

### Usage
- Copy the above content and save it as `README.md` in your project directory.
- This Markdown file provides a clear overview of your program, including its features, requirements, inp