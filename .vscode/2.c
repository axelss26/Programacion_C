#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;
    char texto[256];

    while (1) {
        printf("\nmenu de seleccion:\n");
        printf("1. ingresar texto\n");
        printf("2. crear un archivo binario\n");
        printf("3. crear un archivo .txt\n");
        printf("4. salir\n");
        
        printf("seleccione una opcion 1-4: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                printf("ingrese el texto que desea guardar: ");
                fgets(texto, sizeof(texto), stdin);
                printf("texto guardado.\n");
                break;

            case 2: {
                FILE *archivo_bin;
                archivo_bin = fopen("archivo.bin", "wb");
                if (archivo_bin == NULL) {
                    printf("Error al crear el archivo\n");
                    break;
                }
                fwrite(texto, sizeof(char), sizeof(texto), archivo_bin);
                fclose(archivo_bin);
                printf("archivo binario creado\n");
                break;
            }

            case 3: {
                FILE *archivo_txt;
                archivo_txt = fopen("archivo.txt", "w");
                if (archivo_txt == NULL) {
                    printf("error al crear el archivo .txt.\n");
                    break;
                }
                fprintf(archivo_txt, "%s", texto);
                fclose(archivo_txt);
                printf("archivo .txt creado\n");
                break;
            }

            case 4:
                printf("saliendo del programa\n");
                exit(0);

            default:
                printf("opcion no valida\n");
        }
    }

}
