#include <stdio.h>

// Function to add two integers
int add(int a, int b) { return a + b; }

// Function to subtract two integers
int sub(int a, int b) { return a - b; }

// Function to multiply two integers
int mul(int a, int b) { return a * b; }

// Function to divide two integers (returning integer quotient)
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0; // Return 0 if division by zero
    } else {
        return a / b;
    }
}

// Function to compute the remainder of integer division
int mod(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0; // Return 0 if division by zero
    } else {
        return a % b;
    }
}
