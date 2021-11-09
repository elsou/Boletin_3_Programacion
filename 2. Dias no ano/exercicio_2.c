
/*
 * Boletín 3
 * Exercicio 2: Calcular días do ano
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>

//A estrutura tipo Date permite manexar datas con facilidade
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

//Declaración de funcións
int bisesto(int ano);
int num_dias(Date data);
Date data_invalida(Date data);
Date ler_data();

//Número de días de cada mes
int meses[13] = {31,28,31,30,31,30,31,31,30,31,30,31};

//---------------------------------------------------------//

int main()
{
    //O usuario introduce unha data
    Date data1;
    data1 = ler_data();
    
    //Imprímese o número de días que van de ano
    printf("Levas %d dias no ano %d", num_dias(data1), data1.year);
    return 1;
}

//Devolve 1 se o ano introducido é bisesto, un 0 se non o é
int bisesto(int ano) {
    if(((ano%4 == 0) & (ano%100 != 0)) || (ano%400 == 0)) return 1;
    else return 0;
}

//Calcula o número de días que pasaron desde o comezo do ano e unha data dada
int num_dias(Date data) {
    int resultado = 0;
    
    //Se o ano é bisesto, súmase un día a febreiro
    if(bisesto(data.year)) meses[1]++;
    //Cóntanse os dias dende o comezo do ano ata o comezo do mes
    for(int i = 0; i < data.month-1; i++) resultado += meses[i];
    //Súmanse os días dende o comezo do mes
    resultado = resultado + data.day;
    
    return resultado;
}

//Crea un dato tipo Date a partir da input do usuario
Date ler_data() {
    Date data = {.day = 1, .month = 1, .year = 1};
    do{
        if(data_invalida(data).day || data_invalida(data).month || data_invalida(data).year){
            //Isto imprímese se houbo algún dato incorrecto na anterior volta
            printf("\nVolva intentalo");
            if(data_invalida(data).day)   printf(" (dia non valido)");
            if(data_invalida(data).month) printf(" (mes non valido)"); 
            if(data_invalida(data).year)  printf(" (ano non valido)");
            printf(":\n");
        }else{
            //Isto imprímese a primeira vez que se pregunta a data
            printf("Escriba a data en formato dd/mm/aaaa:\n"); 
        }
        scanf("%d/%d/%d", &data.day, &data.month, &data.year);
    }while(data_invalida(data).day || data_invalida(data).month || data_invalida(data).year); 
    //Este bucle repítese ata que os datos sexan válidos
    
    return data;
}

//Devolve unha estrutura Date cun 1 se algún dos parámetros é incorrecto
Date data_invalida(Date data) {
    Date incorrecta;
    //Fixa incorrecta.mes a 1 se é menor que 1 ou maior que 12
    incorrecta.month = data.month < 0 || data.month > 12;
    //Fixa incorrecta.dia a 1 se, a pesar de estar ben o mes, o día é menor que 1 ou maior que o último día dese mes
    incorrecta.day = !incorrecta.month && (((data.day > meses[data.month-1]) || (data.day < 1)) && !(bisesto(data.year) && (data.day == 29)));
    //Fixa incorrecta.ano a 1 se o ano é o 0 (non existe)
    incorrecta.year = data.year == 0;
    return incorrecta;
}
