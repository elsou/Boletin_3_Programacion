/*
 * Boletín 3
 * Exercicio 1: GCD
 * Autor: Daniel Souto Pazó
 */

#include <stdio.h>
#include <math.h>

int gcd(int a, int b);

int main(){
    //O usuario introduce dous enteiros
    int a,b;
    printf("\nIntroduza dous enteiros para saber o seu maximo comun divisor:\n");
    scanf("%d %d",&a,&b);

    //Imprímese o seu máximo común divisor
    int resultado = gcd(a,b);
    printf("GCD(%d,%d) = %i\n", a, b, resultado);

    return 1;
}

//Utiliza o algoritmo de Euclides e devolve o máximo común divisor dos dous valores introducidos
int gcd(int a, int b){
    int resultado, temp;
    while(a && b != 0){
        if(abs(b) > abs(a)){
            temp = a;
            a = b;
            b = temp;
        }
        a = a % b;
    }
    resultado = abs(a + b);
    return resultado;
}