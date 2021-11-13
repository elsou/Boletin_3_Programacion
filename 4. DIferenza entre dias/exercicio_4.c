
/*
 * Boletín 3
 * Exercicio 4: Diferenza entre dúas datas
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>
#include "dias.h"

//Declaración de funcións
Date ler();
void mostrar (Date d, char formato);
int calcular_distancia(Date d1, Date d2);

int vez = 1;
char form;

int main()
{
    //O formato desexado gárdase na variable tipo char "f"
    printf("\nEste programa calcula a distancia entre duas datas.\n");
    printf("-En que formato prefire manexar as datas?\n (Para dd/mm/aaaa introduza 1)\n (Para mm/dd/aaaa introduza 2)\n");
    scanf("%c", &form);

    //O usuario introduce dúas datas, que se intercambian para adaptarse á orde cronolóxica e facilitar os cálculos
    Date dia1 = ler();
    Date dia2 = ler();
    if(dia1.year*10000 + dia1.month*100 + dia1.day > dia2.year*10000 + dia2.month*100 + dia2.day)
        trocar(&dia2, &dia1);

    //Calcúlase e imprímese a diferenza de días entre as dúas datas introducidas
    int distancia = calcular_distancia(dia1, dia2);
    printf("A distancia entre o dia ");
    mostrar(dia1, form);
    printf(" e o dia ");
    mostrar(dia2, form);
    printf(" e de %d dias\n", distancia);

    return 1;
}

//Calcula os días entre dúas datas
int calcular_distancia (Date d1, Date d2) {
    int distancia;
    //No mesmo ano réstanse os días que levan de ano
    //En distintos anos, súmanse os días no último ano, os que faltan para completar o primeiro ano, e os días dos anos intermedios
    if(d1.year == d2.year)  distancia = days_so_far(d2) - days_so_far(d1);
    else                    distancia = days_so_far(d2) + days_to_come(d1) + days_in_years(d1.year, d2.year);
    return distancia;
}

//Imprime unha data segundo o formato elexido
void mostrar(Date d, char formato) {
    if(formato == '1')  printf("%02d/%02d/%04d", d.day, d.month, d.year);
    else                printf("%02d/%02d/%04d", d.month, d.day, d.year);
}

//Crea unha estrutura Date a partir do input, asegurándose de que a data é válida
Date ler() {
    Date temp = {1, 1, 1};
    do{
        //Isto imprímese se houbo algún dato incorrecto na anterior volta
        if(data_invalida(temp).day)         printf("\nVolva intentalo (dia non valido)\n");
        else if(data_invalida(temp).month)  printf("\nVolva intentalo (mes non valido)\n");
        else if(data_invalida(temp).year)   printf("\nVolva intentalo (ano non valido):\n");
        else{

            //Pide a data no formato elexido polo usuario
            printf("Escriba a %da data en formato ", vez);
            if(form == '1')  printf("dd/mm/aaaa:\n");
            else             printf("mm/dd/aaaa:\n");
            vez ++;
        }

        //Le a data no formato elexido polo usuario
        if(form == '1')  scanf("%d/%d/%d", &temp.day, &temp.month, &temp.year);
        else             scanf("%d/%d/%d", &temp.month, &temp.day, &temp.year);

    }while(data_invalida(temp).day || data_invalida(temp).month || data_invalida(temp).year);
    return temp;
}
