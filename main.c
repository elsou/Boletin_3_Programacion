/*
 * Boletín 3
 * Exercicio 3: Bubble sort
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include <stdlib.h>
#include "dvectors.h"

//A estrutura dvec (Dynamic Vector) garda o tamaño do propio vector dinámico para facilitar o seu manexo


void ordenar(dvec dvector);
dvec input_to_vector();
void print_vector(dvec dvector);

//-------------------------------------------------------//

int main(){

    dvec dvector1 = new_dvec();

    printf("\nEscriba os seus elementos separados por comas:\n");

    dvector1 = input_to_vector();

    printf("Vector introducido: ");
    print_vector(dvector1);
    printf("\n");

    ordenar(dvector1);

    printf("\n\nVector ordenado:");
    print_vector(dvector1);

    return 1;
}

//Utiliza o método da burbulla para ordenar o vector proporcionado
void ordenar(dvec dvector){
    int done = 0, anterior, temp;
    int v = 1;
    while(!done){
        anterior = dvector.vector[0];
        done = 1;
        for(int i = 0; i < dvector.size; i++){
            if(anterior > dvector.vector[i]){
                temp = dvector.vector[i-1];
                dvector.vector[i-1] = dvector.vector[i];
                dvector.vector[i] = temp;
                done = 0;
            }
            anterior = dvector.vector[i];
        }
        if(!done){
            printf("\nVolta %i: ", v);
            print_vector(dvector);
        }
        v++;
    }
}

//Devolve un vector de enteiros a partir da input dada polo usuario
dvec input_to_vector(){
    dvec dvector;
    scanf("%d", &dvector.vector[0]);
    while(scanf(",%d", &dvector.vector[dvector.size]) != 0){
        dvector = increase_size(dvector, 1);
    }
    return dvector;
}


