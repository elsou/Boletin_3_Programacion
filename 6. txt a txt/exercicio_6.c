/*  Boletín 3
 * Exercicio 6: -txt a .txt
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include <stdlib.h>
#include "dvectors.h"

//Declaración de funcións
dvec file_to_vector(FILE *file);

int calcular_max(dvec dvector);
int calcular_min(dvec dvector);
float calcular_media(dvec dvector);


//----------------------------------------------------------//

int main(){
    //Abre o arquivo .txt en modo lectura
    char *datos = "datos.txt";
    FILE *fpr = fopen(datos, "rt");
    if (fpr == NULL){
        printf("Erro: o arquivo %s non foi aberto", datos);
        return 1;
    }
    
    //Pasa os datos do arquivo .txt a un vector dinámico
    printf("\nLendo enteiros de \"%s\"... ", datos);
    dvec dvector1;
    dvector1 = file_to_vector(fpr);
    printf("[completado]");

    fclose(fpr);
    
    //Abre outro arquivo .txt en modo escritura
    char *resultados = "datos_ordenados.txt";
    FILE *fpw = fopen(resultados, "wt");
    if(fpw == NULL){
        printf("Error: could not open file %s", resultados);
        return 1;
    }
    
    //Garda os datos indicados (máximo, mínimo, media) no arquivo .txt
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
    dvec dvector = new_vec();
    dvector.size = 0;
    do{
        dvector = increase_size(dvector, 1);
    }while(fscanf(file, "%d,", &dvector.vector[dvector.size-1]) != EOF);
    dvector.size--;
    return dvector;
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

