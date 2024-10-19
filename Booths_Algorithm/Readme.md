 ## Booth's Algorithm

## Description
A multiplication algorithm called Booth's algorithm is used to multiply two signed binary values. This algorithm is frequently used in computer maths, which was developed by Andrew Donald Booth in 1951.

The technique increases processing efficiency by reducing the amount of addition operations needed for multiplication. It accomplishes this by performing a number of shifts and adds, which are easily accomplished by straightforward hardware circuits.

In this article, we'll go through Booth's method and show you how to use the C programming language to execute it.


### Algorithm Overview
Set the Multiplicand and Multiplier binary bits as M and Q, respectively.
Initially, we set the AC and Qn + 1 registers value to 0.
SC represents the number of Multiplier bits (Q), and it is a sequence counter that is continuously decremented till equal to the number of bits (n) or reached to 0.
A Qn represents the last bit of the Q, and the Qn+1 shows the incremented bit of Qn by 1.
On each cycle of the booth algorithm, Qn and Qn + 1 bits will be checked on the following parameters as follows:
When two bits Qn and Qn + 1 are 00 or 11, we simply perform the arithmetic shift right operation (ashr) to the partial product AC. And the bits of Qn and Qn + 1 is incremented by 1 bit.
If the bits of Qn and Qn + 1 is shows to 01, the multiplicand bits (M) will be added to the AC (Accumulator register). After that, we perform the right shift operation to the AC and QR bits by 1.
If the bits of Qn and Qn + 1 is shows to 10, the multiplicand bits (M) will be subtracted from the AC (Accumulator register). After that, we perform the right shift operation to the AC and QR bits by 1.
The operation continuously works till we reached n - 1 bit in the booth algorithm.
Results of the Multiplication binary bits will be stored in the AC and QR registers.


### Time Complexity
Time Complexity: O(n)

 Auxiliary Space: O(1)