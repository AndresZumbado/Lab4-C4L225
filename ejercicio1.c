#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 4

/* La funcion unidimensionalizar toma un puntero doble de una matriz y devuelve un puntero 
 hacia un arreglo unidimensional con los valores de la matriz  */

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

/* La funcion bubble_sort toma un puntero hacia un arreglo unidimensional y utiliza 
el algoritmo bubble_sort para ordenarlo de menor a mayor*/

void bubble_sort(int * ptr_array) {
    int swap;
    int finalizar=1;        //Finalizar se usa despues para terminar el while
    while(1){
        finalizar = 1;
        for(int i = 0; i < (FILAS * COLUMNAS -1); i++) {
            if (*(ptr_array + i) > *(ptr_array + i+1)){
                swap = *(ptr_array + i);
                *(ptr_array + i) = *(ptr_array + i+1);
                *(ptr_array + i+1) = swap;
                finalizar = 0;      //Si se hizo un swap, el arreglo no esta ordenado y for se repite
            };
        };
        if (finalizar == 1){        //Si no se hizo swap, arreglo ordenado, finaliza el while
            break;
            };
    };
};

int main() {
    //Se define la matriz con la que se trabaja
    int matriz[3][4] = 
    {
    {1,6,8,7},
    {1,3,5,9},
    {2,0,5,0}
    };

    //Imprimir matriz a trabajar
    printf("A continuacion la matriz con la que se trabajara:\n");
    for(int i = 0; i < FILAS; i++) {
        printf("{");
        for(int j = 0; j < COLUMNAS; j++) {
            printf("%d,", matriz[i][j]);
        };
        printf("}\n");
    };


    //Se busca convertir la matriz en un puntero doble de malloc
    //Primero se debe reservar el espacio en memorio
    int **ptr_matriz = (int **) malloc(FILAS * sizeof(int*));
    
    if (ptr_matriz == NULL){        //Verificar que no sea NULL
	    printf("Error de memoria");
        return 1;
    };
    for(int i = 0; i < FILAS; i++) {
	    *(ptr_matriz + i) = (int *)malloc(COLUMNAS * sizeof(int));
	    if (*(ptr_matriz + i) == NULL){     //Verificacion
            printf("Error de memoria");
    	    return 2;   
	    };
    };

    //Rellenar el malloc con los datos de matriz
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            *(*(ptr_matriz + i) + j) = matriz[i][j];
	    };
    };

    //Unidimensionalizacion, ordenado del arreglo e impresion en pantall
    int *ptr_array = unidimensionalizar(ptr_matriz);
    bubble_sort(ptr_array);
    printf("Finalmente el arreglo unidimensional ordenado:\n");
    printf("{");
    for(int i = 0; i < FILAS * COLUMNAS; i++) {
        printf("%d, ", *(ptr_array + i));
    };
    printf("}");
    //Liberar memoria
    for(int i = 0; i < FILAS; i++) {
	    free(*(ptr_matriz + i));
        *(ptr_matriz + i) = NULL;
    };
    free(ptr_matriz);
    free(ptr_array);
    ptr_matriz = NULL;
    ptr_array = NULL;
}

