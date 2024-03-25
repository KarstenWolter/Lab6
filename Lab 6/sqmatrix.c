#include <stdio.h>

#define MAX_SIZE 10

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int *size) {
    FILE *file = fopen("matrix_input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fscanf(file, "%d", size);
    for (int i = 0; i < *size; ++i) {
        for (int j = 0; j < *size; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int row, column, newValue;
    printf("Enter the row, column, and new value (separated by spaces): ");
    scanf("%d %d %d", &row, &column, &newValue);
    
    if (row >= 0 && row < size && column >= 0 && column < size) {
        matrix[row][column] = newValue;
    } else {
        printf("Invalid row or column.\n");
    }
}

void getMaxValue(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int max = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    printf("Max value: %d\n", max);
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int temp;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], size;

    readMatrixFromFile(matrix1, &size);
    readMatrixFromFile(matrix2, &size);

    // Make sure matrix2 is different from matrix1
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix2[i][j] == matrix1[i][j]) {
                matrix2[i][j] += 1; // Increment to make it different
            }
        }
    }

    printf("Matrix 1:\n");
    printMatrix(matrix1, size);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, size);

    printf("\nAddition Result:\n");
    addMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    printf("\nSubtraction Result:\n");
    subtractMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    printf("\nMultiplication Result:\n");
    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    printf("\nUpdate Element in Matrix 1:\n");
    updateElement(matrix1, size);
    printMatrix(matrix1, size);

    printf("\nMax Value in Matrix 1:\n");
    getMaxValue(matrix1, size);

    printf("\nTranspose of Matrix 1:\n");
    transposeMatrix(matrix1, size);
    printMatrix(matrix1, size);

    return 0;
}
