#include <stdio.h>

/*Autor: Angel Pacheco*/
/*Seccion:3*/
int main()
{
    int nota, sumas = 0, max = -1, min = 8, contador = 0;
    float promedio, suma_desviacion, desviacion_estandar;

    printf("programa para ingresar notas entre 0 y 7.\n");
    printf("Para terminar y calcular ingresa 0.\n");

    while (1)
    {
        printf("ingrese nota:");
        scanf("%d", &nota);

        if (nota == 0)
        {
            break;
        }

        if (nota < 0 || nota > 7)
        {
            printf("Error, la nota debe estar entre 0 y 7.\n");
            continue;
        }
        
        printf("Nota agregada: %d\n", nota);
        sumas += nota; 
        contador++;
        if (nota > max) {
            max = nota; // cambia la nota alta :)
        }
        if (nota < min) 
        {
            min = nota; // cambia la nota baja
        }
    }
    
    if (contador > 0)
    {
        promedio = (float) sumas / contador;

        desviacion_estandar = 0.0;

        printf("\nRESULTADOS:\n");
        printf("Cantidad de notas ingresadas: %d\n", contador);
        printf("Promedio: %.2f\n", promedio);
        printf("Nota maxima: %d\n", max);
        printf("Nota minima: %d\n", min);
        printf("desviacionestandar (aproximada): %.2f\n", desviacion_estandar);
    }
    
    else 
    {
        printf("No se ingresaron notas validas.\n");
    }

    return 0;
}
