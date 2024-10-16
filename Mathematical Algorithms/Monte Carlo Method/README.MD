# Monte Carlo Method
The **Monte Carlo Method** is a statistical technique that allows for the estimation of numerical results through random sampling. It is particularly useful in scenarios where deterministic solutions are difficult or impossible to derive. By using randomness and repeated sampling, the Monte Carlo method can approximate complex mathematical problems, making it valuable in various fields such as physics, finance, and engineering.

This project demonstrates the use of the **Monte Carlo Method** to estimate the value of Pi using random sampling. The Monte Carlo Method is a computational algorithm that relies on repeated random sampling to obtain numerical results. In this case, we estimate Pi by simulating points inside a unit square and checking how many fall within a quarter circle inscribed inside that square.

## How It Works

The basic idea is to:
1. Generate random points in a 2D plane within the unit square (1x1).
2. Count how many of those points fall inside the quarter circle of radius 1.
3. Use the ratio of points inside the circle to the total points to approximate the value of Pi.

### Formula
The ratio of the area of the quarter circle to the area of the square is Pi/4. Hence, Pi can be estimated by:

$Pi ≈ 4 × (Number \ of \ points \ inside \ the \ quarter \ circle) / (Total \ number \ of \ points)$


## Code Structure

- **main()**: Initializes the simulation and calls the `estimatePi()` function.
- **estimatePi()**: Performs the Monte Carlo simulation by generating random points and calculating the ratio to estimate Pi.

## Example Output:
Estimated value of Pi: 3.141592
The accuracy improves with a higher number of points.

## Time Complexity
- **Time Complexity**: O(n), where `n` is the number of random points generated.
- **Space Complexity**: O(1), as the algorithm only uses a few variables regardless of input size.