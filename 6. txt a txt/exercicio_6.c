/*  Boletín 3
 * Exercicio 5: Enteiros to vector
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dvec{
    int *vector;
    int size;
} dvec;

//Declaración de funcións
dvec file_to_vector(FILE *file);
dvec increase_size(dvec dvector);

int calcular_max(dvec dvector);
int calcular_min(dvec dvector);
float calcular_media(dvec dvector);


//----------------------------------------------------------//

int main(){
    char *datos = "datos.txt";
    FILE *fpr = fopen(datos, "rt");
    if (fpr == NULL){
        printf("Erro: o arquivo %s non foi aberto", datos);
        return 1;
    }

    printf("\nLendo enteiros de \"%s\"... ", datos);
    dvec dvector1;
    dvector1 = file_to_vector(fpr);
    printf("[completado]");

    fclose(fpr);

    char *resultados = "datos_ordenados.txt";
    FILE *fpw = fopen(resultados, "w+");
    if(fpw == NULL){
        printf("Error: could not open file %s", resultados);
        return 1;
    }

    printf("\nGardando resultados en \"%s\"... ", resultados);
    fprintf(fpw,"Maximo: %d\n", calcular_max(dvector1));
    fprintf(fpw,"Minimo: %d\n", calcular_min(dvector1));
    fprintf(fpw,"Media: %f\n", calcular_media(dvector1));
    printf("[completado]\n");

    fclose(fpr);

    return 0;
}

//Devolve un punteiro a un vector no que garda os enteiros contidos no arquivo .txt
dvec file_to_vector(FILE *file){
    dvec dvector;
    dvector.size = 0;
    dvector.vector= (int*) malloc(sizeof(int));
    do{
        dvector = increase_size(dvector);
    }while(fscanf(file, "%d,", &dvector.vector[dvector.size-1]) != EOF);
    dvector.size--;
    return dvector;
}

//Devolve un punteiro a unha copia do vector dado e con un elemento máis
dvec increase_size(dvec dvector){
    dvec temp = dvector;
    temp.size++;
    temp.vector = realloc(temp.vector, sizeof(int)*temp.size);
    return temp;
}

//Devolve a maior enteiro do vector proporcionado
int calcular_max(dvec dvector){
    int max = dvector.vector[0];
    for(int i = 1; i < dvector.size; i++){
        if(dvector.vector[i] > max){
            max = dvector.vector[i];
        }
    }
    return max;
}

//Devolve a menor enteiro do vector proporcionado
int calcular_min(dvec dvector){
    int min = dvector.vector[0];
    for(int i = 1; i < dvector.size; i++){
        if(dvector.vector[i] < min){
            min = dvector.vector[i];
        }
    }
    return min;
}

//Devolve a media entre todos os enteiros do vector proporcionado
float calcular_media(dvec dvector){
    float media = dvector.vector[0];
    for(int i = 1; i < dvector.size; i++){
        media = media*(i/(i + 1.0))+(dvector.vector[i]/(i + 1.0));
    }
    return media;
}

