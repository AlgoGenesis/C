<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1><strong>Binary Exponentiation</strong></h1>

<h2><strong>Overview</strong></h2>

<p>Binary exponentiation, also known as exponentiation by squaring, is an efficient algorithm for computing large powers of a number. This method significantly reduces the number of multiplications required, especially for large exponents, by utilizing the properties of exponentiation.</p>

<h2><strong>Mathematical Background</strong></h2>

<p>The key idea behind binary exponentiation is to express the exponent as a sum of powers of 2. For any integer <i>n</i>, we can write:</p>

<p>
    <i>n = a<sub>0</sub> ⋅ 2<sup>0</sup> + a<sub>1</sub> ⋅ 2<sup>1</sup> + a<sub>2</sub> ⋅ 2<sup>2</sup> + ... + a<sub>k</sub> ⋅ 2<sup>k</sup></i>
</p>

<p>Where <i>a<sub>i</sub></i> is either 0 or 1. This representation allows us to compute <i>x<sup>n</sup></i> efficiently by squaring:</p>

<ol>
    <li>If <i>n</i> is even:
        <p>
            <span style="font-size: 1.5em;">x</span><sup>n</sup> = <span style="font-size: 1.5em;">(</span><span style="font-size: 1.5em;">x</span><sup>n/2</sup><span style="font-size: 1.5em;">)</span><sup>2</sup>
        </p>
    </li>
    <li>If <i>n</i> is odd:
        <p>
            <span style="font-size: 1.5em;">x</span><sup>n</sup> = <span style="font-size: 1.5em;">x</span> ⋅ <span style="font-size: 1.5em;">x</span><sup>n-1</sup>
        </p>
    </li>
</ol>

<p>By repeatedly halving the exponent, we can reduce the number of multiplications.</p>

<h2><strong>ALGORITHM</strong></h2>

<pre>
<code>
FUNCTION binary_exponentiation(base, exponent)
    result ← 1                // Step 1: Initialize result to 1
    current_product ← base     // Step 2: Initialize current_product to base

    WHILE exponent &gt; 0 DO      // Step 3: Loop until exponent is greater than 0
        IF exponent MOD 2 = 1 THEN  // Step 4: Check if exponent is odd
            result ← result * current_product  // Step 5: Multiply result by current_product
        
        current_product ← current_product * current_product  // Step 6: Square current_product
        exponent ← exponent DIV 2          // Step 7: Halve the exponent using integer division

    END WHILE

    RETURN result  // Step 8: Return the final result
END FUNCTION
</code>
</pre>

<h2><strong>Explanation of the Algorithm</strong></h2>

<h3>Initialization:</h3>
<ul>
    <li>Set <strong>result</strong> to 1 (the identity for multiplication).</li>
    <li>Initialize <strong>current_product</strong> to <strong>base</strong>.</li>
</ul>

<h3>Loop:</h3>
<p>While <strong>exponent</strong> is greater than 0:</p>
<ul>
    <li>If <strong>exponent</strong> is odd, multiply <strong>result</strong> by <strong>current_product</strong>.</li>
    <li>Square <strong>current_product</strong>.</li>
    <li>Halve the <strong>exponent</strong> using integer division.</li>
</ul>

<h3>Return:</h3>
<p>Once the loop finishes, return <strong>result</strong>.</p>

<h2><strong>Time Complexity</strong></h2>

<p>The time complexity of binary exponentiation is <b>O(log n)</b>, where <b>n</b> is the exponent. This is due to the halving of the exponent at each step.</p>

<h2><strong>Conclusion</strong></h2>

<p>Binary exponentiation is a powerful technique for computing large powers efficiently. It is widely used in algorithms involving modular arithmetic, such as in cryptography, where computations with large integers are common.</p>

</body>
</html>
