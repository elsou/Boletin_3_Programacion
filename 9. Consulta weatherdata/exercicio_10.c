
/*
 * Boletín 3
 * Exercicio 10: Ler arquivo binario
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include "weather.h"
#include "dias.h"


//Declaración de funcións
WeatherData consulta_por_data(FILE* file, Date d);
float consulta_precip_media(FILE* file, Date d1, Date d2);

int main()
{
    //Abre o ficheiro .dat en modo lectura binaria
    char *datos_bin = "weatherdata-420-72.dat";
    FILE *bin = fopen(datos_bin,"rb");
    if(bin == NULL){
        printf("Erro: O arquivo %s non foi aberto", datos_bin);
        return 1;
    }

    //Este bucle repítese ata que o usuario decide finalizar as consultas.
    int r;
    do{
        printf("\n-Se desexa consultar os datos metereoloxicos dun dia concreto, pulse 1.\n");
        printf("-Se desexa calcular as precipitacions medias entre duas datas, pulse 2.\n");
        printf("-Se desexa finalizar o programa, pulse 3.\n");
        scanf("%d", &r);
        getchar();

        if(r != 3){
            Date data1, data2;
            data1 = get_date();

            if(r == 2){
                data2 = get_date();
                //Ordenar as datas por orde cronolóxica axuda a simplificar os cálculos
                if(data1.year*10000 + data1.month*100 + data1.day > data2.year*10000 + data2.month*100 + data2.day)
                    trocar_datas(&data1, &data2);
                printf("\nA precipitacion media entre o %d/%d/%d e o %d/%d/%d foi de %f l/m^2\n",
                       data1.day, data1.month, data1.year,
                       data2.day, data2.month, data2.year,
                       consulta_precip_media(bin, data1, data2));
            }else if(r == 1){
                print_weatherdata(consulta_por_data(bin, data1));
            }else
                printf("Input non valida.\n");
        }
    }while(r != 3);

    fclose(bin);
    return 0;
}

//Devolve a variable tipo WeatherData correspondente a unha data
WeatherData consulta_por_data(FILE* file, Date d) {
    int days = days_since_2000(d);
    WeatherData data;
    fseek(file, sizeof(WeatherData)*(days-1), SEEK_SET);
    fread(&data, sizeof(WeatherData), 1, file);
    return data;
}

//Devolve a media dos valores de precipitation para cada día entre dúas datas dadas
float consulta_precip_media(FILE* file, Date d1, Date d2) {
    WeatherData data;
    int inicio = days_since_2000(d1);
    int final = days_since_2000(d2) - inicio + 1;
    float media = 0;

    fseek(file, sizeof(WeatherData)*(inicio - 1), SEEK_SET);
    for(int i = 0; i < final; i++){
        fread(&data, sizeof(WeatherData), 1, file);
        media += data.precipitation;
    }media = media/final;

    return media;
}


