The Karatsuba algorithm is a fast multiplication algorithm. It was discovered by Anatoly Karatsuba in 1960 and published in 1962.[1][2][3] It is a divide-and-conquer algorithm that reduces the multiplication of two n-digit numbers to three multiplications of n/2-digit numbers and, by repeating this reduction, to at most 
n
log
2
⁡
3
≈
n
1.58
{\displaystyle n^{\log _{2}3}\approx n^{1.58}} single-digit multiplications. It is therefore asymptotically faster than the traditional algorithm, which performs 
n
2
{\displaystyle n^{2}} single-digit products.
Time Complexity: Time complexity of the above solution is O(nlog23) = O(n1.59).
