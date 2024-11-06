#include <stdio.h>

#define MAX 100

void readSparseMatrix(int sparse[MAX][3], int *n) {
    int i, j, rows, cols, nonZero = 0;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);
    
    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int val;
            scanf("%d", &val);
            if (val != 0) {
                sparse[nonZero][0] = i;
                sparse[nonZero][1] = j;
                sparse[nonZero][2] = val;
                nonZero++;
            }
        }
    }
    sparse[nonZero][0] = rows;
    sparse[nonZero][1] = cols;
    sparse[nonZero][2] = nonZero;
    *n = nonZero;
}

void printTriplet(int sparse[MAX][3], int n) {
    int i;
    printf("Row Column Value\n");
    for (i = 0; i < n; i++) {
        printf("%d   %d     %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void simpleTranspose(int sparse[MAX][3], int transpose[MAX][3], int n) {
    int i;
    transpose[n][0] = sparse[n][1];
    transpose[n][1] = sparse[n][0];
    transpose[n][2] = sparse[n][2];
    
    int k = 0;
    for (i = 0; i < sparse[n][1]; i++) {
        for (int j = 0; j < n; j++) {
            if (sparse[j][1] == i) {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}

void fastTranspose(int sparse[MAX][3], int transpose[MAX][3], int n) {
    int rowTerms[MAX], startingPos[MAX], i;

    for (i = 0; i < sparse[n][1]; i++) {
        rowTerms[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        rowTerms[sparse[i][1]]++;
    }

    startingPos[0] = 0;
    for (i = 1; i < sparse[n][1]; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    transpose[n][0] = sparse[n][1];
    transpose[n][1] = sparse[n][0];
    transpose[n][2] = sparse[n][2];
    
    for (i = 0; i < n; i++) {
        int j = startingPos[sparse[i][1]]++;
        transpose[j][0] = sparse[i][1];
        transpose[j][1] = sparse[i][0];
        transpose[j][2] = sparse[i][2];
    }
}

int main() {
    int sparse[MAX][3], transpose[MAX][3], n;

    readSparseMatrix(sparse, &n);

    printf("Sparse matrix in triplet form:\n");
    printTriplet(sparse, n);

    simpleTranspose(sparse, transpose, n);
    printf("\nSimple Transpose in triplet form:\n");
    printTriplet(transpose, n);

    fastTranspose(sparse, transpose, n);
    printf("\nFast Transpose in triplet form:\n");
    printTriplet(transpose, n);

    return 0;
}