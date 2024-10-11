#include <stdio.h>

typedef struct {
    unsigned long long a, b;
    unsigned long long c, d;
} Mat;


//function for matrix multiplication
Mat mat_mult(Mat m1, Mat m2) {
    Mat res;
    res.a = m1.a * m2.a + m1.b * m2.c;
    res.b = m1.a * m2.b + m1.b * m2.d;
    res.c = m1.c * m2.a + m1.d * m2.c;
    res.d = m1.c * m2.b + m1.d * m2.d;
    return res;
}

Mat mat_pow(Mat m, int p) {
    if (p == 1) {
        return m;
    }
    if (p % 2 == 0) {
        Mat half = mat_pow(m, p / 2);
        return mat_mult(half, half);
    } else {
        return mat_mult(m, mat_pow(m, p - 1));
    }
}

unsigned long long fib_mat(int n) {
    if (n <= 1) {
        return n;
    }
    Mat F = {1, 1, 1, 0}; //The matrix
    Mat res = mat_pow(F, n - 1);
    return res.a; 
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    unsigned long long fib2 = fib_mat(n);
    printf("Required term of the Fibonacci series: %llu\n", fib2);

    return 0;
}
