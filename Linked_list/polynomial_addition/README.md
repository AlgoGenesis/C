### Polynomial Addition Program                    
This is a C program that performs polynomial addition using linked lists. The program allows the user to input two polynomials, adds them, and displays the result in standard polynomial form.

---
### Features
Input two polynomials from the user.                   
Add polynomials by combining like terms.                   
Display polynomials in a readable format (e.g., 3x^2 + 2x + 1).                       

---
### Functions Used
```createNode(int coeff, int exp):``` Creates a new node representing a term in the polynomial.                          
```insertTerm(struct Node** head, int coeff, int exp):``` Adds a term to the polynomial linked list.                      
```displayPolynomial(struct Node* head):``` Displays the polynomial in a user-friendly format.                                
```addPolynomials(struct Node* poly1, struct Node* poly2):``` Adds two polynomials and returns the resulting polynomial.                       

---
### Sample Input and Output:
Enter the number of terms for the first polynomial: 3                         
Enter coefficient and exponent for term 1: 3 2                     
Enter coefficient and exponent for term 2: 2 1                  
Enter coefficient and exponent for term 3: 1 0                       

Enter the number of terms for the second polynomial: 2                    
Enter coefficient and exponent for term 1: 4 2                  
Enter coefficient and exponent for term 2: 3 0                         

First Polynomial: 3x^2 + 2x + 1               
Second Polynomial: 4x^2 + 3            
Sum of Polynomials: 7x^2 + 2x + 4              
