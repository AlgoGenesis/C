# Chinese Remainder Theorem (CRT)
## Description
The **Chinese Remainder Theorem** is a theorem in number theory that provides a way to solve systems of simultaneous congruences with different moduli. Specifically, if you have multiple equations of the form:

x≡​a<sub>1</sub>( mod m<sub>1</sub>)<br>
x≡​a<sub>2</sub>( mod m<sub>2</sub>)<br>
 .<br>
 .<br>
 .<br>
x≡​a<sub>k</sub>( mod m<sub>k</sub>)<br><br>
where m<sub>1</sub>,m<sub>2</sub>...,mod m<sub>k</sub> re pairwise coprime integers, then there exists a unique solution x modulo M, where 𝑀 is the product of all the moduli:<br>
  M = m<sub>1</sub> . m<sub>2</sub>...mod m<sub>k</sub>
  ## Example
  **Problem:** Solve the following system of congruences:<br>
x≡​2(mod 3)<br>
x≡​3(mod 5)<br>
## Step 1: Identify the Moduli and Remainders
From the equations, we can identify:<br>
Moduli (num):[3,5]<br>
Remainders (rem):[2,3]
## Step 2: Calculate the Product of Moduli
Calculate the product of all the moduli:
M=3⋅5=15
## Step 3: Calculate Partial Products
For each modulus, calculate the partial product M<sub>i:
- M<sub>1</sub>= M/3 = 15/3 = 5
- M<sub>2</sub> = M/5 = 15/5 = 3
## Step 4: Calculate Modular Inverses
Next, for each M<sub>i</sub> find the modular inverse M<sub>i</sub><sup>-1</sup> such that:<br>
 M<sub>i</sub>. M<sub>i</sub><sup>-1</sup> ≡ 1(mod num<sub>i)
### Finding Inverses:
### 1. For M<sub>1</sub> = 5 mod 3
- We need 5 . x ≡ 1(mod 3)
- 5 mod 3 = 2. So, we solve 2x ≡ 1(mod 3).
- Testing values:
   - x=2 gives 2 . 2 mod 3 = 4 mod 3 = 1
- Thus,M<sub>1</sub><sup>-1</sup> = 2
### 2. For M<sub>2</sub> = 3 mod 5  
- We need 3 . y ≡ 1(mod 5)
- Testing values:
   - y=2 gives 3 . 2 mod 5 = 6 mod 5 = 1
- Thus,M<sub>2</sub><sup>-1</sup> = 2
## Step 5: Calculate the Result
Now, use the formula to calculate the solution x:<br>
      x = (rem<sub>1</sub> . M<sub>1</sub> . M<sub>1</sub><sup>-1</sup> + rem<sub>2</sub> . M<sub>2</sub> .  M<sub>2</sub><sup>-1</sup>) mod M <br>
      Substituting the values:<br>
      x = (2 .5 .2 + 3 . 3 . 2) mod 15<br>
      x = (20 +18) mod 15<br>
      x = 38 mod 15<br>
      x = 8

## Pseudocode
```bash
function gcd(a, b):
    while b ≠ 0:
        temp = b
        b = a % b
        a = temp
    return a

function extendedGCD(a, b):
    if b = 0:
        return (1, 0, a)
    
    (x1, y1, gcd) = extendedGCD(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return (x, y, gcd)

function modInverse(a, m):
    (x, y, g) = extendedGCD(a, m)
    if g ≠ 1:
        return -1
    return (x % m + m) % m

function chineseRemainder(num[], rem[], k):
    prod = 1
    for i from 0 to k-1:
        prod *= num[i]

    result = 0
    for i from 0 to k-1:
        pp = prod / num[i]
        inv = modInverse(pp, num[i])
        result += rem[i] * inv * pp

    return result % prod

function main:
    print "Enter the number of equations:"
    k = input()

    num[k] = new array
    rem[k] = new array

    print "Enter the moduli:"
    for i from 0 to k-1:
        num[i] = input()

    print "Enter the remainders:"
    for i from 0 to k-1:
        rem[i] = input()

    for i from 0 to k-1:
        for j from i+1 to k-1:
            if gcd(num[i], num[j]) ≠ 1:
                print "The moduli must be pairwise coprime."
                return

    prod = 0
    result = chineseRemainder(num, rem, k)
    print "The solution is x ≡", result, "(mod", prod, ")"
```
## Explanation of the Pseudocode
### GCD Function:
Implements the Euclidean algorithm to compute the greatest common divisor of two numbers.
### Extended GCD Function:
Uses recursion to find integers x and y such that ax + by = gcd(a,b).It also returns the GCD.
### Modular Inverse Function:
Calculates the modular inverse of a modulo m using the extended GCD. If the inverse doesn't exist (GCD is not 1), it returns -1.
### Chinese Remainder Function:
- Computes the product of all moduli and initializes a result variable.
- For each equation, it calculates the partial product, finds the modular inverse, and accumulates the result.
### Main Function:
- Takes user input for the number of equations, the moduli, and the remainders.
- Checks if the moduli are pairwise coprime using the GCD function.
- Calls the Chinese Remainder function and prints the final solution.

## Time Complexity
- **GCD Calculation:** O(log(min(a,b)))
- **Extended GCD Calculation:** Similar complexity as the GCD function.
- **Modular Inverse Calculation:** O(log(min(a,m))) due to the extended GCD.
- **Chinese Remainder Calculation:**
    - The main loop runs k times.
    - Inside this loop, it computes the modular inverse and GCD for each modulus, so:
    - Overall complexity: O(k⋅log(m)) where m is the maximum value in the num array.
## Space Complexity
- The space complexity is primarily influenced by the input arrays and auxiliary variables.
- **Space Complexity:** O(k) for the arrays holding moduli and remainders, plus a constant space for auxiliary variables.

## Input and Output
![image](https://github.com/user-attachments/assets/cdc6611a-e7d0-47bf-90e0-242fd5a0e6b9)
