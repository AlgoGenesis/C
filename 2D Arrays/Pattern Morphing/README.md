# Pattern Morphing in C

This C program demonstrates a simple pattern morphing algorithm that transforms one character pattern into another on a 5x5 grid. The morphing process involves changing one cell at a time, with each step printed to visualize the transition.

## Overview

Pattern morphing is a technique used to smoothly transition from one pattern to another, often applied in animation or graphical transformations. In this example, we have two predefined patterns, and the program gradually morphs the first pattern (`pattern1`) into the second pattern (`pattern2`).

## Program Features

* **Grid Visualization**: Displays a 5x5 character grid for the initial and target patterns.
* **Morphing Animation**: Transforms `pattern1` into `pattern2` one cell at a time, with each transformation step printed and numbered.
* **Customizable Patterns**: Modify the `pattern1` and `pattern2` arrays to create different morphing animations.

## Patterns

The default patterns are as follows:

**Pattern 1**:
```
X X X
 X X 
X X X
 X X 
X X X
```

**Pattern 2**:
```
 O O O 
O O O O
O O O O
O O O O
 O O O 
```

The program will morph `pattern1` into `pattern2`, one cell at a time, displaying each intermediate step.

## Prerequisites

* GCC compiler (or any C compiler)

## Compilation and Execution

1. **Compile** the program with GCC:
```bash
gcc pattern_morph.c -o pattern_morph
```

2. **Run** the compiled executable:
```bash
./pattern_morph
```

## Code Explanation

The program contains the following main parts:

1. `displayGrid` Function:
   * Takes a 5x5 character grid and displays it on the console along with the step number.

2. `morphPattern` Function:
   * Handles the morphing process. It iteratively changes each mismatched cell in `current` to match `pattern2` until both patterns are identical.
   * Prints each step of the morphing process with a delay between updates to create an animated effect.

3. **Main Function**:
   * Defines the initial and target patterns (`pattern1` and `pattern2`).
   * Calls the `morphPattern` function to execute the pattern morphing.

## Example Output

```
Pattern Morphing from Pattern1 to Pattern2:

Step 1:
X X X
 X X 
X X X
 X X 
X X X

Step 2:
O X X
 X X 
X X X
 X X 
X X X

...

Final Step:
 O O O 
O O O O
O O O O
O O O O
 O O O 
```

The program will progressively print each transformation step from `pattern1` to `pattern2`.

## Customization

* Modify the `ROWS` and `COLS` constants to change the grid size.
* Edit the `pattern1` and `pattern2` arrays to explore different morphing patterns.
* Adjust the `DELAY` value to change the speed of the animation.

