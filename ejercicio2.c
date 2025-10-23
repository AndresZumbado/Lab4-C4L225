#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){
    FILE * archivo = fopen('arg + 1', "r");
    FILE * escrito = fopen("miarchivo.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo\n");
        return 1;
    }
    char carac;
    *palabra = (char*)malloc( sizeof(char) );
    if (palabra == NULL){return 2};
    int len = 0
    *escribir = (char*)malloc( sizeof(char) );
    while(carac == fgetc(archivo) != EOF) {
        if( isalpha(carac) ) {
            realloc(palabra, (len+1) * sizeof(char))
            *(palabra + len) = carac
            len++
        }; 
        else {
            for(int i = 0; i < len) {
                igual = 1
                if(*(palabra+i) != arg[1][i]){
                    igual = 0
                };
            };
            if(igual = 1){
                realloc(palabra, strlen(argv[1]) * sizeof(char) );
                for(int i = 0; i < strlen(argv[1]); i++) {
                    *(palabra + i) = argv[1][i];
                len = strlen(argv[1]);
                };
            };
        for(int i = 0; i < len; i++){
            fprintf(escrito, "%c", *(palabra + i))
        };
        len = 0
        realloc(palabra, sizeof(char) )
        };
    };
    for(int i = 0; i < len; i++){
            fprintf(escrito, "%c", *(palabra + i))
        };
    
    fclose(archivo)
    fclose(escrito)
    free(palabra);
    palabra = NULL;
}

