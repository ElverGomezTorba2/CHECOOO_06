/*Autores: Bastian Olivera -- Angel Pacheco
  Docentes: Hugo Araya -- Luis Ponce
  Seccion : numero 3*/
#include <stdio.h>
#include <string.h>

/* Prototipos de Funciones */
void inicializa_alfabeto(char *alfabeto);
void lee_original(char *mensaje, int *N);
void graba_mensaje(char *mensaje_codificado, int N);
void codificar(char *mensaje_original, char *mensaje_codificado, char *alfabeto, int N);
void primera_etapa(char *mensaje_original, char *mensaje_intermedio, char *alfabeto, int N);
void segunda_etapa(char *mensaje_intermedio, char *mensaje_codificado, char *alfabeto, int N);

/* Función Principal */
int main() {
    char original[100];
    char alfabeto[48];
    char codificado[100];
    int clave_n;

    inicializa_alfabeto(alfabeto);
    lee_original(original, &clave_n);
    codificar(original, codificado, alfabeto, clave_n);
    graba_mensaje(codificado, clave_n);

    return 0;
}

/* Inicializa el vector del alfabeto con los caracteres definidos */
void inicializa_alfabeto(char *alfabeto) {
    strcpy(alfabeto, "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!,.:;?-+*#/");
}

/* Busca la posición de un carácter en el alfabeto */
int buscar_posicion_en_alfabeto(char caracter, char *alfabeto) {
    int i;
    for (i = 0; i < strlen(alfabeto); i++) {
        if (alfabeto[i] == caracter) {
            return i;
        }
    }
    return -1;
}

/* Obtiene el carácter en una posición específica del alfabeto */
char buscar_caracter_por_posicion(int posicion, char *alfabeto) {
    int tamano = strlen(alfabeto);
    while (posicion < 0) {
        posicion += tamano;
    }
    return alfabeto[posicion % tamano];
}

/* Lee el mensaje original y la clave N desde "original.txt" */
void lee_original(char *mensaje, int *N) {
    FILE *archivo;
    char linea[100];
    int i = 0;
    int encontrado = 0;
    
    archivo = fopen("original.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir 'original.txt'\n");
        return;
    }

    if (fgets(linea, sizeof(linea), archivo) == NULL) {
        printf("Error: Archivo vacío o no se pudo leer\n");
        fclose(archivo);
        return;
    }

    /* Eliminar salto de línea si existe */
    linea[strcspn(linea, "\n")] = '\0';
    
    /* Convertir la parte numérica antes del # */
    *N = 0;
    while (linea[i] != '\0' && linea[i] != '#') {
        if (linea[i] >= '0' && linea[i] <= '9') {
            *N = *N * 10 + (linea[i] - '0');
            i++;
        } else {
            printf("Error: La clave debe ser numérica\n");
            fclose(archivo);
            return;
        }
    }

    if (linea[i] != '#') {
        printf("Error: Formato incorrecto. Debe ser N#mensaje\n");
        fclose(archivo);
        return;
    }

    strcpy(mensaje, &linea[i+1]);  /* Copiar el mensaje después del # */
    fclose(archivo);
}

/* Graba el mensaje codificado en "codificado.txt" con el formato N#mensaje */
void graba_mensaje(char *mensaje_codificado, int N) {
    FILE *archivo = fopen("codificado.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear 'codificado.txt'\n");
        return;
    }
    fprintf(archivo, "%d#%s", N, mensaje_codificado);
    fclose(archivo);
}

/* Función principal de codificación */
void codificar(char *mensaje_original, char *mensaje_codificado, char *alfabeto, int N) {
    char intermedio[100];
    
    primera_etapa(mensaje_original, intermedio, alfabeto, N);
    segunda_etapa(intermedio, mensaje_codificado, alfabeto, N);
}

/* Primera etapa: Suma N a la posición de cada carácter */
void primera_etapa(char *mensaje_original, char *mensaje_intermedio, char *alfabeto, int N) {
    int i, pos, nueva_pos;
    int tamano_alfabeto = strlen(alfabeto);
    
    for (i = 0; mensaje_original[i] != '\0'; i++) {
        pos = buscar_posicion_en_alfabeto(mensaje_original[i], alfabeto);
        if (pos != -1) {
            nueva_pos = (pos + N) % tamano_alfabeto;
            mensaje_intermedio[i] = buscar_caracter_por_posicion(nueva_pos, alfabeto);
        } else {
            mensaje_intermedio[i] = mensaje_original[i];
        }
    }
    mensaje_intermedio[i] = '\0';
}

/* Segunda etapa: Resta N a caracteres en posiciones múltiplo de 4 */
void segunda_etapa(char *mensaje_intermedio, char *mensaje_codificado, char *alfabeto, int N) {
    int i, pos, nueva_pos;
    int tamano_alfabeto = strlen(alfabeto);
    
    strcpy(mensaje_codificado, mensaje_intermedio);
    
    for (i = 0; mensaje_codificado[i] != '\0'; i++) {
        pos = buscar_posicion_en_alfabeto(mensaje_codificado[i], alfabeto);
        if (pos != -1 && (pos % 4 == 0 || pos == 0)) {  /* Múltiplo de 4 o posición 0 */
            nueva_pos = (pos - N) % tamano_alfabeto;
            mensaje_codificado[i] = buscar_caracter_por_posicion(nueva_pos, alfabeto);
        }
    }
}