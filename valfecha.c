#include <stdio.h>

/*Autor: Angel Pacheco*/
/*Seccion: 3*/
/*Fecha: 25 de mayo de 2025*/
int main()
{
   int dia = 0, mes = 0, ano = 0;

   printf("Programa para validar fechas :) ");
   printf("Para terminar este programa ingresa 0");
   printf("Ingrese dia: ");
    scanf("%d", &dia);
    printf("Ingrese mes: ");
    scanf("%d", &mes);

    printf("Ingrese ano: ");
    scanf("%d", &ano);

    if (dia == 0)
    {
        break;
    }

    if (mes == 0)
    {
        break;
    }
        
    if (ano == 0)
    {
        break;
    }

    while (1)
    {
        

        
        if (mes < 1 || mes > 12)
        {
            printf("error, el mes debe estar entre 1 y 12 .\n");
            continue;
        }

        if (ano < 2025 || ano > 2030)
        {
            printf("error, el ano debe estar entre 2025 y 2030 .\n");
            continue;
        }

        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 9 || mes == 11)
        {
            if (dia < 1 || dia > 31)
            {
                printf ("error, el dia debe estar entre 1 y 31 .\n");
                continue;
            }
        }
        else
        {
            if (mes == 4 || mes == 6 || mes == 8 || mes == 10 || mes == 12)
            {
                if (dia < 1 || dia > 30)
                {
                    printf("error, el dia debe estar entre 1 y 30");
                    break;
                }
                
            }
            

            if (mes == 2)
            {
                if (dia < 1 || dia > 29)
                {
                    printf("error, el numero tiene que ser entre 1 y 29.\n");
                    break;
                }
            }
        }
        
        printf("%d/%d/%d", dia, mes, ano);
        break;
    }

    
    
    return 0;

}
