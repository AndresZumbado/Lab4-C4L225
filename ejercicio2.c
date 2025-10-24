#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Debe incluir nombre de archivo, palabra a sustituiy remplazo\n");
        return 1;
    };

    FILE *archivo = fopen(argv[1], "r");
    FILE *escrito = fopen("miarchivo.txt", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", argv[1]);
        return 2;
    };

    if (escrito == NULL) {
        printf("No se pudo crear el archivo de salida\n");
        fclose(archivo);
        return 3;
    };

    char carac;
    char *palabra = (char*)malloc( sizeof(char) );
    if (palabra == NULL) {
        return 4;
    };
    int len = 0;
    while( (carac = fgetc(archivo)) != EOF) {
        if( isalpha(carac) ) {
            palabra = realloc(palabra, (len+1) * sizeof(char));
            if(palabra == NULL){
                printf("Error de memoria");
                return 5;
            };
            *(palabra + len) = carac;
            len++;
        } else {
            int igual = 1;
            if(len != strlen(argv[2]) ) {
                igual = 0;
            } else {
                for(int i = 0; i < len; i++) {
                    if(*(palabra+i) != argv[2][i]){
                        igual = 0;
                    };
                };
            }
            if(igual == 1){
                palabra = realloc(palabra, strlen(argv[3]) * sizeof(char));
                for(int i = 0; i < strlen(argv[3]); i++) {
                    *(palabra + i) = argv[3][i];
                };
                len = strlen(argv[3]);
            };
        
        for(int i = 0; i < len; i++){
            fprintf(escrito, "%c", *(palabra + i) );
        };
        fprintf(escrito, "%c", carac );
        len = 0;
        };
    };
    for(int i = 0; i < len; i++){
            fprintf(escrito, "%c", *(palabra + i));
        };
    
    fclose(archivo);
    fclose(escrito);
    free(palabra);
    palabra = NULL;
    return 0;
}

