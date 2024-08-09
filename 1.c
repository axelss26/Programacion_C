#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tipoArchivo;
    char nombreArchivoSinExtension[50];
    char contenidoTexto[256];
    
    printf("Seleccione el tipo de archivo a crear:\n");
    printf("1. Archivo de texto (.txt)\n");
    printf("2. Archivo binario (.bin)\n");
    printf("Opción: ");
    scanf("%d", &tipoArchivo);
    
    printf("Introduce el nombre del archivo (sin extensión): ");
    scanf("%s", nombreArchivoSinExtension);
    
    if (tipoArchivo == 1) {
        strcat(nombreArchivoSinExtension, ".txt");
        printf("Introduce una cadena de texto: ");
        getchar(); 
        fgets(contenidoTexto, sizeof(contenidoTexto), stdin);
        FILE *archivoTexto = fopen(nombreArchivoSinExtension, "w");
        fputs(contenidoTexto, archivoTexto);
        fclose(archivoTexto);
        printf("Cadena guardada en %s\n", nombreArchivoSinExtension);
    } else if (tipoArchivo == 2) {
        strcat(nombreArchivoSinExtension, ".bin");
        printf("Introduce una cadena: ");
        getchar(); 
        fgets(contenidoTexto, sizeof(contenidoTexto), stdin);
        FILE *archivoBinario = fopen(nombreArchivoSinExtension, "wb");
        fwrite(contenidoTexto, sizeof(char), strlen(contenidoTexto) + 1, archivoBinario);
        fclose(archivoBinario);
        printf("Cadena guardada en %s\n", nombreArchivoSinExtension);
    } else {
        printf("Opción no válida.\n");
    }
    
    return 0;
}
