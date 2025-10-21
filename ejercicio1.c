#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 4

int *unidimensionalizar(int **matriz) {
    int array = (int*)malloc (FILAS * COLUMNAS  * sizeof(int));
    int cont = 0;
    for(int i = 0; i < FILAS; i++) {
	for(int j = 0; j < COLUMNAS; j++) {
	    *(array + cont) = *(*(matriz + j) + i);
	    cont = cont++;
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

    int *ptr_matriz = (int **) malloc(FILAS * int);
    
    for(int i = 0; i < FILAS; i++) {
	ptr_matriz + i = (int *)malloc(COLUMNAS * int);
    };
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            *(*(ptr_matriz + j) + i) = matriz[i][j];

    int ptr_array = unidimensionalizar(ptr_matriz);
    for(int i = 0; i < FILAS * COLUMNAS; i++) {
	printf(" %d ", *(ptr_array + i));
    };
}

