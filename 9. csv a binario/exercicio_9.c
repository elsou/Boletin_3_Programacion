/*
 * Boletín 3
 * Exercicio 9: Pasar de .csv a .dat
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include <stdlib.h>
#include "weather.h"

//A estrutura dvec (Dynamic Vector) garda o tamaño do propio vector dinámico para facilitar o seu manexo
typedef struct dvec{
  WeatherData *vector;
  int size;
} dvec;

//Declaración de funcións
dvec csv_to_WeatherData(FILE *file_r);
void WeatherData_to_binary(dvec data, FILE *file_w);
void skipLine(FILE *file_r);

//----------------------------------------------------------//

int main()
{
    //Ábrese o ficheiro .csv para lectura
    char *datos = "weatherdata-420-72.csv";
    FILE *fpr = fopen(datos, "r");
    if (fpr == NULL){
        printf("Erro: O arquivo %s non foi aberto", datos);
        return 1;
    }
    
    //Os datos almacénanse nun vector dinámico de estruturas tipo WeatherData
    dvec weatherdata1;
    weatherdata1 = csv_to_WeatherData(fpr);
    fclose(fpr);
    
    //Ábrese o ficheiro binario en modo de escritura
    char *datos_bin = "weatherdata-420-72.dat";
    FILE *bin = fopen(datos_bin,"wb+");
    if(bin == NULL){
        printf("Erro: O arquivo %s non foi aberto", datos_bin);
        return 1;
    }
    
    //Gárdase a información de weatherdata1 no arquivo binario
    WeatherData_to_binary(weatherdata1, bin);

    fclose(bin);


    return 0;
}

//Devolve un punteiro a un array dinámico de WeatherData cos datos do ficheiro csv (file_r)
dvec csv_to_WeatherData(FILE *file_r){
    dvec data;
    data.vector = (WeatherData *) malloc(sizeof(WeatherData));
    data.size = 1;
    printf("\nPasando de .csv a WeatherData... ");

    skipLine(file_r);
    while((fscanf(file_r, "\"%d/%d/%d\",\"%f\",\"%f\",\"%d\",\"%f\",\"%f\",\"%f\",\"%f\",\"%f\",\"%f\",\n", &data.vector[data.size-1].date.month, &data.vector[data.size-1].date.day, &data.vector[data.size-1].date.year, &data.vector[data.size-1].longitude, &data.vector[data.size-1].latitude, &data.vector[data.size-1].elevation, &data.vector[data.size-1].max_temp, &data.vector[data.size-1].min_temp, &data.vector[data.size-1].precipitation, &data.vector[data.size-1].wind, &data.vector[data.size-1].rel_humidity, &data.vector[data.size-1].solar)) != EOF){
        data.size++;
        data.vector = realloc(data.vector, sizeof(WeatherData) * data.size);
    }
    printf("[completado]");
    return data;
}

//Escribe os datos do array proporcionado nun ficheiro binario .dat
void WeatherData_to_binary(dvec data, FILE *file_w){
    printf("\nPasando de WeatherData a .dat... ");
    for(int i = 0; i < data.size; i++){
        fwrite(&data.vector[i].date, sizeof(Date), 1, file_w);
        fwrite(&data.vector[i].longitude, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].latitude, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].elevation, sizeof(int), 1, file_w);
        fwrite(&data.vector[i].max_temp, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].min_temp, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].precipitation, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].wind, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].rel_humidity, sizeof(float), 1, file_w);
        fwrite(&data.vector[i].solar, sizeof(float), 1, file_w);
    }
    printf("[completado]\n");
}

//Move o punto de lectura á seguinte liña do ficheiro .csv
void skipLine(FILE *file_r){
    char c;
    do { c = fgetc(file_r); } while (c != '\n');
}
