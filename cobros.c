# include <stdio.h>

int main()
{
    int dia, mes, ano, hora_inicio, min_inicio, hora_fin, min_final, total_min, total_horas;
    float total_pago = 0.0;

    printf("Ingrese la fecha ingresando con slash cada digito :) (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    printf("Ingrese la hora de entrada (hh:mm): ");
    scanf("%d:%d", &hora_inicio, &min_inicio);
    
    printf("Ingrese la hora de salida (hh:mm): ");
    scanf("%d:%d", &hora_fin, &min_final);

    total_min = (hora_fin * 60 + min_final) - (hora_inicio * 60 + min_inicio);

    if (total_min <= 10)
    {
        total_pago = 0;
    }
    else if (total_min <= 25)
    {
        total_pago = 3;
    }
    else
    {
        total_horas = total_min / 60;
        int minutos_restantes = total_min % 60;

        total_pago = 10;
        if (total_horas > 1)
        {
            total_pago += (total_horas - 1) * 5;
        }
        
        if (minutos_restantes > 0)
        {
            total_pago += 0;
        }
    }
    
    if (dia % 7 == 0)
    {
        total_pago *= 0.95;
    }

    printf("Fecha: %02d/%02d/%04d | Hora Inicio: %02d:%02d | Hora Fin: %02d:%02d | Total a pagar: $ %.2f\n", dia, mes, ano, hora_inicio, min_inicio, hora_fin, min_final, total_pago);
    
    return 0;
}