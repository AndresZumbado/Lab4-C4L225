#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// La funcion main recibe desde la linea de comandos: nombre de archi - palabra a sustituir - palabra remplazo
int main(int argc, char *argv[]) {
    //Revisar que se hayan introducido los tres requisitos
    if (argc < 4) {
        printf("Debe incluir nombre de archivo, palabra a sustituiy remplazo\n");
        return 1;
    };
    
    //Abrir ambos archivos, escrito es el archivo de salida y archivo el original
    FILE *archivo = fopen(argv[1], "r");
    FILE *escrito = fopen("miarchivo.txt", "w");

    //Revisar que se hayan abierto y o creado los archivos
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", argv[1]);
        return 2;
    };
    if (escrito == NULL) {
        printf("No se pudo crear el archivo de salida\n");
        fclose(archivo);
        return 3;
    };
    
    //Se trabaja caracter por caracter, char contiene el caracter actual del archivo
    //Palabra es un arreglo que contendra la palabra que eventualmente se escribe en escrito
    char carac;
    char *palabra = (char*)malloc( sizeof(char) );
    if (palabra == NULL) {      // Revisar que se haya alocado en memoria
        return 4;
    };

    int len = 0;        //len es una variable que mantiene el tamaño de la palabra actual
    while( (carac = fgetc(archivo)) != EOF) {
        if( isalpha(carac) ) {          //Para encontrar el fin de una palabra se busca que carac no sea una letra
            palabra = realloc(palabra, (len+1) * sizeof(char));     //Se define el tamaño de la palabra para que almacene 
            if(palabra == NULL){                                    //cada caracter correspondiente
                printf("Error de memoria");
                return 5;
            };
            *(palabra + len) = carac;
            len++;
        } else {
            int igual = 1;      //La variable igual nos dice si la palabra es igual a la palabra a remplazar
            if(len != strlen(argv[2]) ) {       //Si el tamaño es distinto no pueden ser iguales
                igual = 0;
            } else {
                for(int i = 0; i < len; i++) {
                    if(*(palabra+i) != argv[2][i]){     //Revisar si son iguales caracter por caracter
                        igual = 0;
                    };
                };
            }
            if(igual == 1){
                palabra = realloc(palabra, strlen(argv[3]) * sizeof(char)); //Si es igual palabra se sustituye por el remplazo
                for(int i = 0; i < strlen(argv[3]); i++) {
                    *(palabra + i) = argv[3][i];
                };
                len = strlen(argv[3]);
            };
        
        for(int i = 0; i < len; i++){
            fprintf(escrito, "%c", *(palabra + i) );        //Se imprime la palabra independientemente de si se cambio o no
        };
        fprintf(escrito, "%c", carac ); //El caracter actual no es letra y no esta en palabra, se debe imprimir
        len = 0;    //Reiniciar palabra
        };
    };
    //Si el ultimo caracter es una letra se debe descargar el contenido de palabra
    for(int i = 0; i < len; i++){
            fprintf(escrito, "%c", *(palabra + i));
        };
    //Cerrar archivos
    fclose(archivo);
    fclose(escrito);
    //Liberar palabra
    free(palabra);
    palabra = NULL;
    return 0;
}

