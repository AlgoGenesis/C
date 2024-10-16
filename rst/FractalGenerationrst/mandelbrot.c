#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Function to compute the Mandelbrot set
void generateMandelbrot(double minReal, double maxReal, double minImaginary, double maxImaginary)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            double real = minReal + (x / (double)WIDTH) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (double)HEIGHT) * (maxImaginary - minImaginary);
            double complex z = 0;
            double complex c = real + imaginary * I;
            int iter;

            for (iter = 0; iter < MAX_ITER; iter++)
            {
                z = z * z + c;
                if (cabs(z) > 2)
                    break;
            }

            // Output the pixel value based on the number of iterations
            if (iter < MAX_ITER)
            {
                printf("%c", (iter % 256));
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    double minReal = -2.0;
    double maxReal = 1.0;
    double minImaginary = -1.5;
    double maxImaginary = 1.5;

    generateMandelbrot(minReal, maxReal, minImaginary, maxImaginary);
    return 0;
}
