
/*
 * Boletín 3
 * Exercicio 3: Bubble sort
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include "dvectors.h"

//Declaración de funcións
void ordenar(dvec dvector);
dvec input_to_vector();
void trocar(int *a, int *b);

//-------------------------------------------------------//

int main()
{
    //O usuario introduce unha serie de enteiros que se almacenan nun vector dinámico
    printf("\nEste programa ordena de menor a maior os elementos dun vector mediante o metodo da burbulla.\n");
    printf("\nEscriba os seus elementos (enteiros) separados por comas:\n");
    dvec dvector1 = input_to_vector();
    printf("Vector introducido: ");
    print_vector(dvector1);
    printf("\n");

    //Os datos ordénanse de menor a maior polo algoritmo da burbulla (Bubble Sort)
    ordenar(dvector1);

    //Imprímese o resultado
    printf("\n\nVector ordenado:");
    print_vector(dvector1);

    return 1;
}

//Utiliza o método da burbulla para ordenar o vector proporcionado
void ordenar(dvec dvector) {
    int done = 0;
    int v = 0;
    while(!done){
        v++;
        done = 1;
        for(int i = 1; i < dvector.size; i++){
            if(dvector.vector[i-1] > dvector.vector[i]){
                trocar(&dvector.vector[i], &dvector.vector[i-1]);
                done = 0;
            }
        }
        if(!done) {
            printf("\nVolta %i: ", v);
            print_vector(dvector);
        }
    }
}

//Devolve un vector de enteiros a partir da input dada polo usuario
dvec input_to_vector() {
    dvec dvector = new_dvec();
    scanf(",");
    scanf("%d", &dvector.vector[0]);
    while(scanf(",%d", &dvector.vector[dvector.size]) != 0) {
        dvector = increase_size(dvector, 1);
    }
    return dvector;
}

//Intercambia a posición de memoria almacenada en cada un dos punteiros
void trocar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
