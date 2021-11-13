
/*
 * Boletín 3
 * Exercicio 1: GCD
 * Autor: Daniel Souto Pazó
 */

#include <stdio.h>
#include <math.h>

//Declaración das funcións
int gcd(int a, int b);
void trocar(int *a, int *b);

int main()
{
    //O usuario introduce dous enteiros
    int a,b;
    printf("\nIntroduza dous enteiros separados por espazos para saber o seu maximo comun divisor:\n");
    scanf("%d %d",&a,&b);

    //Imprímese o seu máximo común divisor
    int resultado = gcd(a,b);
    printf("GCD(%d,%d) = %i\n", a, b, resultado);

    return 1;
}

//Utiliza o algoritmo de Euclides e devolve o máximo común divisor dos dous valores introducidos
int gcd(int a, int b) {
    int resultado;
    while(a && b != 0){
        if(abs(b) > abs(a))
            trocar(&a,&b);
        a = a % b;
    }
    resultado = abs(a + b);
    return resultado;
}

//Intercambia a posición de memoria almacenada en cada un dos punteiros
void trocar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
