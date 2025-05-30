# include <stdio.h>

/*Autor: Angel Pacheco Rebolledo*/
/*Seccion: numero 3*/
/*29 de mayo de 2025*/

int main()
{
    int rut = 0;
    int multiplicador = 2, suma = 0;
    char digito_ver, resultado;

    printf("Ingrese numero de tipo RUT, Ej: 1123123 .\n");
    scanf ("%d", &rut);

    printf("Ingrese su digito verificador, Ej: 3 o K .\n");
    scanf(" %c", &digito_ver);

    while (rut > 0)
    {
        int digito = rut % 10;              /*obtiene el ultimo digito y despues*/
        suma += digito * multiplicador;    /*suma lo que es el resultado de la*/
        rut = rut / 10;                             /*multiplicacion*/
        multiplicador ++;
        if (multiplicador > 7)
        {
            multiplicador = 2;
        }
        
    }

    int resto = suma % 11;        /*calcula el*/
    if (resto == 1)           /*digito verificador*/
    {
        resultado = 'K';
    }
    else if (resto == 0)
    {
        resultado = '0';
    }
    else
    {
        resultado = (11 - resto) + '0';
    }

    if (resultado == digito_ver)
    {
        printf("El RUT es correcto :) .\n");
    }
    else
    {
        printf("El RUT o digito verificador estan malos :(, intente nuevamente ;) .\n");
    }

    return 0;
}