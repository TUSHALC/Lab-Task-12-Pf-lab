#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    int i,j;
    int **matrix;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    matrix = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = i * j;
        }
    }
    matrix[0][0] = 7;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

