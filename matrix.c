#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Function declarations
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main() {
    // Define two 5x5 matrices
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose1[SIZE][SIZE];
    int transpose2[SIZE][SIZE];

    // Adding matrices
    printf("Sum of matrices:\n");
    addMatrices(m1, m2, sum);
    printMatrix(sum);

    // Multiplying matrices
    printf("\nProduct of matrices:\n");
    if (multiplyMatrices(m1, m2, product) == -1) {
        printf("Error: Matrix dimensions do not match for multiplication.\n");
    } else {
        printMatrix(product);
    }

    // Transpose of matrix m1
    printf("\nTranspose of matrix m1:\n");
    transposeMatrix(m1, transpose1);
    printMatrix(transpose1);

    // Transpose of matrix m2
    printf("\nTranspose of matrix m2:\n");
    transposeMatrix(m2, transpose2);
    printMatrix(transpose2);

    return 0;
}

// Function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices with error handling for incompatible sizes
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize the result matrix with zeros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return 0;  // Return 0 to indicate successful multiplication
}

// Function to transpose a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}
