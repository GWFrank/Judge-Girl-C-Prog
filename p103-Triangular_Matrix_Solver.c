#include <stdio.h>
#include <stdlib.h>


int main(){
    int rank;
    scanf("%d", &rank);
    
    double **matrix = malloc(rank * sizeof(double *));

    for (int i=0; i<rank; i++) {
        matrix[i] = malloc((rank+1) * sizeof(double));
        for (int j=0; j<rank; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    for (int i=0; i<rank; i++) {
        scanf("%lf", &matrix[i][rank]);
    }

    double *sol = malloc(rank * sizeof(double));
    for (int i=rank-1; i>=0; i--) {
        double y = matrix[i][rank];
        for (int j=0; j<rank; j++) {
            if (i != j) y -= matrix[i][j]*sol[j];
        }
        sol[i] = y/matrix[i][i];
        // free(matrix[i]);
    }

    for (int i=0; i<rank; i++) {
        printf("%f\n", sol[i]);
    }

    return 0;
}