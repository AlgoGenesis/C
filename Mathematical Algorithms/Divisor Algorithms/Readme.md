<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Divisor Algorithms in C</h1>

<p>This repository contains a C program that calculates both the number of divisors and the sum of divisors of a given integer using properties of prime factorization.</p>

<h2>Overview</h2>

<p>The program consists of two main functions:</p>
<ul>
    <li><strong>Count Divisors</strong>: Calculates the total number of divisors of a given integer.</li>
    <li><strong>Sum Divisors</strong>: Computes the sum of all divisors of the integer.</li>
</ul>

<h2>Mathematical Background</h2>

<h3>Number of Divisors</h3>
<p>The number of divisors <em>d(n)</em> of a positive integer <em>n</em> can be determined using its prime factorization. If <em>n</em> can be expressed as:</p>
<pre>
n = p<sub>1</sub><sup>e<sub>1</sub></sup> × p<sub>2</sub><sup>e<sub>2</sub></sup> × ... × p<sub>k</sub><sup>e<sub>k</sub></sup>
</pre>
<p>where <em>p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>k</sub></em> are distinct prime factors and <em>e<sub>1</sub>, e<sub>2</sub>, ..., e<sub>k</sub></em> are their respective exponents, the total number of divisors is given by:</p>
<pre>
d(n) = (e<sub>1</sub> + 1)(e<sub>2</sub> + 1)...(e<sub>k</sub> + 1)
</pre>

<h3>Sum of Divisors</h3>
<p>The sum of divisors <em>σ(n)</em> can also be derived from the prime factorization. The formula for the sum of divisors is:</p>
<pre>
σ(n) = (1 + p<sub>1</sub> + p<sub>1</sub><sup>2</sup> + ... + p<sub>1</sub><sup>e<sub>1</sub></sup>)(1 + p<sub>2</sub> + p<sub>2</sub><sup>2</sup> + ... + p<sub>2</sub><sup>e<sub>2</sub></sup>)...(1 + p<sub>k</sub> + p<sub>k</sub><sup>2</sup> + ... + p<sub>k</sub><sup>e<sub>k</sub></sup>)
</pre>

<h2>Logic</h2>
<p>The algorithm follows these logical steps:</p>
<ol>
    <li><strong>Prime Factorization</strong>: Iterate through potential factors starting from <em>2</em>. For each factor, check if it divides <em>n</em> and count how many times it does (the exponent). Update the divisor count and sum of divisors accordingly.</li>
    <li><strong>Final Adjustment</strong>: If after processing all factors, <em>n > 1</em>, then <em>n</em> itself is a prime number and should be included in both the divisor count and the sum.</li>
</ol>

<h2>Pseudocode</h2>

<h3>Count Divisors</h3>
<pre>
function count_divisors(n):
    count = 1
    for i from 2 to √n:
        exponent = 0
        while n is divisible by i:
            n = n / i
            exponent += 1
        if exponent > 0:
            count *= (exponent + 1)
    if n > 1:
        count *= 2
    return count
</pre>

<h3>Explanation</h3>
<ul>
    <li><strong>count = 1</strong>: Initialize the count of divisors to 1. This accounts for the empty divisor.</li>
    <li><strong>for i from 2 to √n</strong>: Loop through all integers from 2 up to the square root of <code>n</code> to find prime factors.</li>
    <li><strong>while n is divisible by i</strong>: For each prime factor <code>i</code>, check how many times it divides <code>n</code> and count those divisions (exponent).</li>
    <li><strong>count *= (exponent + 1)</strong>: Update the total count of divisors using the formula for the number of divisors.</li>
    <li><strong>if n > 1</strong>: If after processing, <code>n</code> is still greater than 1, it is a prime number and contributes an additional divisor.</li>
</ul>

<h3>Sum Divisors</h3>
<pre>
function sum_divisors(n):
    sum = 1
    for i from 2 to √n:
        exponent = 0
        term_sum = 1
        while n is divisible by i:
            n = n / i
            exponent += 1
            term_sum += i^exponent
        if exponent > 0:
            sum *= term_sum
    if n > 1:
        sum *= (1 + n)
    return sum
</pre>

<h3>Explanation</h3>
<ul>
    <li><strong>sum = 1</strong>: Initialize the sum of divisors to 1.</li>
    <li><strong>for i from 2 to √n</strong>: Loop through potential prime factors.</li>
    <li><strong>while n is divisible by i</strong>: Similar to counting, check how many times <code>i</code> divides <code>n</code> and calculate the sum of its powers.</li>
    <li><strong>sum *= term_sum</strong>: Update the total sum of divisors using the derived formula.</li>
    <li><strong>if n > 1</strong>: If <code>n</code> is still greater than 1 after processing, it is a prime number and contributes to the sum.</li>
</ul>


<h2>Example</h2>
<div class="example">
    <strong>Let's consider n = 12:</strong>
    <ul>
        <li>Prime factorization: 12 = 2<sup>2</sup> × 3<sup>1</sup></li>
        <li><strong>Counting Divisors:</strong>
            <ul>
                <li>For i = 2: 
                    <ul>
                        <li>2 divides 12: exponent = 2 (12 / 2 = 6, 6 / 2 = 3)</li>
                    </ul>
                </li>
                <li>For i = 3:
                    <ul>
                        <li>3 divides 3: exponent = 1 (3 / 3 = 1)</li>
                    </ul>
                </li>
                <li>Final count of divisors = (2 + 1)(1 + 1) = 3 × 2 = 6.</li>
            </ul>
        </li>
        <li><strong>Summing Divisors:</strong>
            <ul>
                <li>For i = 2: 
                    <ul>
                        <li>term_sum = 1 + 2 + 4 = 7</li>
                    </ul>
                </li>
                <li>For i = 3:
                    <ul>
                        <li>term_sum = 1 + 3 = 4</li>
                    </ul>
                </li>
                <li>Final sum of divisors = 7 × 4 = 28.</li>
            </ul>
        </li>
    </ul>
</div>


<h2>Overall Time Complexity</h2>
<p>Both functions, <code>count_divisors</code> and <code>sum_divisors</code>, exhibit a similar time complexity:</p>
<pre>
O(√n * log n)
</pre>
<p>This efficiency makes these algorithms suitable for calculating the number and sum of divisors for reasonably large integers.</p>

<h2>Conclusion</h2>
<p>The program efficiently computes the number and sum of divisors for any positive integer by leveraging properties of prime factorization. Feel free to contribute or ask questions regarding the implementation!</p>

</body>
</html>