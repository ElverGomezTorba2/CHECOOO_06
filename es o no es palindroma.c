#include <stdio.h>

int es_palindromo(int palabra[]);

int main()
{
    int palabra[21];
    printf("Ingrese una palabra: ");
    scanf("%d", &palabra);

    if (es_palindromo(palabra) == 1)
    {
        printf("La palabra es palindroma :) ");
    }
    else
    {
        printf("La palabra no es palindroma :( ");
    }
    return 0;
}

int es_palindromo(int palabra[])
{
    int i = 0, tamanio;
    while (palabra[i] != '\0')
    {
        tamanio = i;
        i++;
    }
    
    i = 0;
    while (i <= tamanio /2)
    {
        if (palabra[i] == palabra[tamanio - i])
        {
            i++;
            continue;
        }
        return 0;
    }
    return 1;
}
