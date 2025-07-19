/*Autores : Bastian Olivera -- Angel Pacheco
  Docentes: Hugo Araya -- Luis Ponce
  Seccion : numero 3*/
#include <stdio.h>
#include <string.h>

/* Prototipos de Funciones */
void inicializa_alfabeto(char *);
int lee_codificado(char *, int *);
void graba_decodificado(char *, int );
void decodificar(char *, char *, char *, int);
void primera_etapa_decodificar(char *, char *, char *, int );
void segunda_etapa_decodificar(char *, char *, char *, int );
int buscar_posicion_en_alfabeto(char, char *);
char buscar_caracter_por_posicion(int, char *);

/* Función Principal */
int main() {
    char codificado[100];
    char decodificado[100];
    char alfabeto[100];
    int clave_n;

    inicializa_alfabeto(alfabeto);
    
    if (!lee_codificado(codificado, &clave_n)) {
        printf("Error al leer el archivo codificado\n");
        return 1;
    }

    decodificar(codificado, decodificado, alfabeto, clave_n);
    graba_decodificado(decodificado, clave_n);

    return 0;
}

/* Inicializa el alfabeto exactamente igual que en el codificador */
void inicializa_alfabeto(char *alfabeto) {
    strcpy(alfabeto, "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!,.:;?-+*#/");
}

/* Lee el archivo codificado con el mismo formato que usó el codificador */
int lee_codificado(char *mensaje, int *N) {
    FILE *archivo;
    char linea[100];
    int i = 0;
    
    archivo = fopen("codificado.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir 'codificado.txt'\n");
        return 0;
    }

    if (fgets(linea, sizeof(linea), archivo) == NULL) {
        printf("Error: Archivo vacío o no se pudo leer\n");
        fclose(archivo);
        return 0;
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
            return 0;
        }
    }

    if (linea[i] != '#') {
        printf("Error: Formato incorrecto. Debe ser N#mensaje\n");
        fclose(archivo);
        return 0;
    }

    strcpy(mensaje, &linea[i+1]);  /* Copiar el mensaje después del # */
    fclose(archivo);
    return 1;
}

/* Graba el mensaje decodificado con el mismo formato que el original */
void graba_decodificado(char *mensaje_decodificado, int N) {
    FILE *archivo = fopen("decodificado.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear 'decodificado.txt'\n");
        return;
    }
    fprintf(archivo, "%d#%s", N, mensaje_decodificado);
    fclose(archivo);
}

/* Función principal de decodificación (proceso inverso al codificador) */
void decodificar(char *mensaje_codificado, char *mensaje_decodificado, char *alfabeto, int N) {
    char intermedio[100];
    
    /* PRIMERO deshacemos la SEGUNDA etapa de codificación */
    segunda_etapa_decodificar(mensaje_codificado, intermedio, alfabeto, N);
    
    /* LUEGO deshacemos la PRIMERA etapa de codificación */
    primera_etapa_decodificar(intermedio, mensaje_decodificado, alfabeto, N);
}

/* Deshace la PRIMERA etapa de codificación (suma N a todos los caracteres) */
void primera_etapa_decodificar(char *mensaje_intermedio, char *mensaje_decodificado, char *alfabeto, int N) {
    int i, pos, nueva_pos;
    int tamano_alfabeto = strlen(alfabeto);
    
    for (i = 0; mensaje_intermedio[i] != '\0'; i++) {
        pos = buscar_posicion_en_alfabeto(mensaje_intermedio[i], alfabeto);
        if (pos != -1) {
            /* En codificación se SUMÓ N, ahora RESTAMOS N */
            nueva_pos = pos - N;
            /* Manejo del arreglo circular */
            while (nueva_pos < 0) nueva_pos += tamano_alfabeto;
            nueva_pos = nueva_pos % tamano_alfabeto;
            mensaje_decodificado[i] = buscar_caracter_por_posicion(nueva_pos, alfabeto);
        } else {
            mensaje_decodificado[i] = mensaje_intermedio[i];
        }
    }
    mensaje_decodificado[i] = '\0';
}

/* Deshace la SEGUNDA etapa de codificación (resta N a múltiplos de 4) */
void segunda_etapa_decodificar(char *mensaje_codificado, char *mensaje_intermedio, char *alfabeto, int N) {
    int i, pos, nueva_pos;
    int tamano_alfabeto = strlen(alfabeto);
    
    strcpy(mensaje_intermedio, mensaje_codificado);
    
    for (i = 0; mensaje_intermedio[i] != '\0'; i++) {
        pos = buscar_posicion_en_alfabeto(mensaje_intermedio[i], alfabeto);
        if (pos != -1 && (pos % 4 == 0)) {  /* Solo múltiplos de 4 (posición 0 incluida) */
            /* En codificación se RESTÓ N, ahora SUMAMOS N */
            nueva_pos = pos + N;
            /* Manejo del arreglo circular */
            while (nueva_pos < 0) nueva_pos += tamano_alfabeto;
            nueva_pos = nueva_pos % tamano_alfabeto;
            mensaje_intermedio[i] = buscar_caracter_por_posicion(nueva_pos, alfabeto);
        }
    }
}

/* Función idéntica a la del codificador para buscar posiciones */
int buscar_posicion_en_alfabeto(char caracter, char *alfabeto) {
    int i;
    for (i = 0; i < strlen(alfabeto); i++) {
        if (alfabeto[i] == caracter) {
            return i;
        }
    }
    return -1;
}

/* Función idéntica a la del codificador para obtener caracteres */
char buscar_caracter_por_posicion(int posicion, char *alfabeto) {
    int tamano = strlen(alfabeto);
    while (posicion < 0) {
        posicion += tamano;
    }
    return alfabeto[posicion % tamano];
}