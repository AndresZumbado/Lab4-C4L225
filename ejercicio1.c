#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 4

int *unidimensionalizar(int **matriz) {
    int *array = (int*)malloc (FILAS * COLUMNAS  * sizeof(int));
    int cont = 0;
    for(int i = 0; i < FILAS; i++) {
	for(int j = 0; j < COLUMNAS; j++) {
	    *(array + cont) = *(*(matriz + i) + j);
	    cont++;
	};
    };
    return array;
};


int main() {

    int matriz[3][4] = 
    {
    {1,6,8,7},
    {1,3,5,9},
    {2,0,5,0}
    };

    int **ptr_matriz = (int **) malloc(FILAS * sizeof(int*));
    
    if (ptr_matriz == NULL){
	return 1;
    };

    for(int i = 0; i < FILAS; i++) {
	*(ptr_matriz + i) = (int *)malloc(COLUMNAS * sizeof(int));
	if (*(ptr_matriz + i) == NULL){
	    return 2;
	};
    };

    
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            *(*(ptr_matriz + i) + j) = matriz[i][j];
	};
    };
    int *ptr_array = unidimensionalizar(ptr_matriz);
    for(int i = 0; i < FILAS * COLUMNAS; i++) {
	printf(" %d ", *(ptr_array + i));
    };
    
    for(int i = 0; i < FILAS; i++) {
	free(*(ptr_matriz + i));
    };
    free(ptr_matriz);
    free(ptr_array);
    
}


