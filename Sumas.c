#include <stdio.h>

int main()
{
    int numero = 0, contador = 0, sumas = 0;
    float promedio;

    printf("Programa para calcular promedio de numeros .\n");
    printf("Para finalizar el calculo, ingresa el siguiente comando: -999 .\n");
    
    while (1)
    {
        printf("Ingrese numero: \n");
        scanf("%d", &numero);

        if (numero == -999)
        {
            break;
        }

        printf("numero agregado: %d\n", numero);
        sumas += numero;
        contador ++;
        
        if (contador > 0)
        {
            promedio = (float) sumas / contador;

            printf("\nRESULTADOS:\n");
            printf("Promedio: %.2f\n", promedio);
        }
        else
        {
            printf("no se ingresaron notas validas.\n");
        }
        
    }
    
    return 0;
}