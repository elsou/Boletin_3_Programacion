//dvectors.h

#include <stdlib.h>

//A estrutura dvec contén o vector e o seu tamaño para facilitar o seu manexo
typedef struct dvec{
    int *vector;
    int size;
} dvec;

//Inicializa un vector dinámico
dvec new_dvec(){
    dvec temp = {(int*) malloc(sizeof(int)), 1};
    return temp;
}

//Aumenta o tamaño do vector dinámico en n unidades
dvec increase_size(dvec dvector, int n){
    dvec temp = new_dvec();
    temp.size = dvector.size + n;
    temp.vector = realloc(dvector.vector, sizeof(int)*(temp.size));
    return temp;
}

//Imprime un vector de enteiros
void print_vector(dvec dvector){
    printf("(%i", dvector.vector[0]);
    for(int i = 1; i < dvector.size; i++){
        printf(", %i", dvector.vector[i]);
    }
    printf(")");
}
