
/*  Boletín 3
 * Exercicio 5: Enteiros a vector
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include "dvectors.h"

//Declaración de funcións
dvec file_to_vector(FILE *file);

int calcular_max(dvec dvector);
int calcular_min(dvec dvector);
float calcular_media(dvec dvector);

//----------------------------------------------------------//

int main()
{
    //Abre o ficheiro .txt en modo de lectura
    char *filename = "enteiros.txt";
    FILE *fp = fopen(filename, "rt");
    if (fp == NULL){
        printf("Erro: o arquivo %s non foi aberto", filename);
        return 1;
    }
    
    //Pasa a información do arquivo a un vector dinámico
    printf("\nLendo enteiros de \"%s\"... ", datos);
    dvec dvector1;
    dvec dvector1 = new_dvec();
    dvector1 = file_to_vector(fp);
    printf("[completado]\n");
    fclose(fp);
    
    //Devolve os valores indicados
    printf("\nPara o vector ");
    print_vector(dvector1);
    printf(":\n");
    printf("Maximo: %d\n", calcular_max(dvector1));
    printf("Minimo: %d\n", calcular_min(dvector1));
    printf("Media: %f\n", calcular_media(dvector1));


    return 0;
}

//Devolve un punteiro a un vector no que garda os enteiros contidos no arquivo .txt
dvec file_to_vector(FILE *file){
    dvec temp = new_dvec();
    while(fscanf(file, "%d,", &temp.vector[temp.size-1]) != EOF)
        temp = increase_size(temp, 1);
    temp.size--;
    return temp;
}

//Devolve a maior enteiro do vector proporcionado
int calcular_max(dvec dvector){
    int max = dvector.vector[0];
    for(int i = 1; i < dvector.size; i++){
        if(dvector.vector[i] > max)  max = dvector.vector[i];
    }
    return max;
}

//Devolve a menor enteiro do vector proporcionado
int calcular_min(dvec dvector){
    int min = dvector.vector[0];
    for(int i = 1; i < dvector.size; i++){
        if(dvector.vector[i] < min)  min = dvector.vector[i];
    }
    return min;
}

//Devolve a media entre todos os enteiros do vector proporcionado
float calcular_media(dvec dvector){
    float media = dvector.vector[0];
    for(int i = 1; i < dvector.size; i++){
        media += dvector.vector[i];
    }   media /= (dvector.size*1.0);
    return media;
}
