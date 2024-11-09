// Euclid’s Algorithm when % and / operations are costly



// Euclid’s algorithm is used to find GCD of two numbers. 
// There are mainly two versions of algorithm. 


// Version 1 (Using subtraction) 

int gcd(int a, int b) // Recursive function to return gcd of a and b
{
    if (a == b)  
       return a;
  
    return (a > b)? gcd(a-b, b): gcd(a, b-a);
}


// Version 2 (Using modulo operator) 

int gcd(int a, int b)  // Function to return gcd of a and b
{
    if (a == 0) 
       return b;
     
    return gcd(b%a, a);
}


// Version 1 can take linear time to find the GCD, consider the situation when one of the given numbers is much bigger than the other. 
// Version 2 is obviously more efficient as there are less recursive calls and takes logarithmic time.
// Consider a situation where modulo operator is not allowed, can we optimize version 1 to work faster?
// Below are some important observations. The idea is to use bitwise operators. 
//We can find x/2 using x>>1. We can check whether x is odd or even using x&1.
// gcd(a, b) = 2*gcd(a/2, b/2) if both a and b are even. 
// gcd(a, b) = gcd(a/2, b) if a is even and b is odd. 
// gcd(a, b) = gcd(a, b/2) if a is odd and b is even.



// Implementation

int gcd(int a, int b)
{
    // Base cases
    if (b == 0 || a == b) return a;
    if (a == 0) return b;
 
    // If both a and b are even, divide both a
    // and b by 2.  And multiply the result with 2
    if ( (a & 1) == 0 && (b & 1) == 0 )
       return gcd(a>>1, b>>1) << 1;
 
    // If a is even and b is odd, divide a by 2
    if ( (a & 1) == 0 && (b & 1) != 0 )
       return gcd(a>>1, b);
 
    // If a is odd and b is even, divide b by 2
    if ( (a & 1) != 0 && (b & 1) == 0 )
       return gcd(a, b>>1);
 
    // If both are odd, then apply normal subtraction 
    // algorithm.  Note that odd-odd case always 
    // converts odd-even case after one recursion
    return (a > b)? gcd(a-b, b): gcd(a, b-a);
}

// Time Complexity  : O(log(max(a, b)))
// Space Complexity : O(1)