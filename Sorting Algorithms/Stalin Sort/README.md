Stalin Sort Algorithm in C
Overview
Stalin Sort is a humorous and non-standard sorting algorithm that sorts numbers by "purging" any elements that are out of order. This means it keeps only those elements that are in non-decreasing order relative to the previously kept element. The result is a sorted sequence of numbers, though some of the original elements may be "purged" or ignored.

How It Works
Start with the first number as the initial element in the sorted sequence.
For each subsequent number:
If the current number is greater than or equal to the last kept number, add it to the sorted sequence.
If the number is smaller, ignore it.
Continue this process until all elements have been evaluated, producing a sorted sequence that only includes numbers in non-decreasing order.
Features
Simple algorithm that illustrates selection criteria by "purging" out-of-order elements.
Creates a sorted sequence but may omit certain numbers.
Best suited for educational or humorous purposes, as it lacks practical efficiency for general sorting.

Limitations
Stalin Sort is a humorous algorithm that only retains elements that maintain a non-decreasing sequence; thus, it does not perform a full sort.
It is not suitable for general sorting tasks or large datasets, as it only provides a partial, order-preserving result.