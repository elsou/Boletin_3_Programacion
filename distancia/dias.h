//dias.h

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

int meses[13] = {31,28,31,30,31,30,31,31,30,31,30,31};

//Comproba se un ano é bisesto ou non
int bisesto(int ano){
    if(((ano%4 == 0) & (ano%100 != 0)) || (ano%400 == 0)){
        return 1;
    }else{
        return 0;
    }
}

//Comproba se algún dos elementos da data son incorrectos, devolvendo un 1 se o son
Date data_invalida(Date data){
    Date incorrecta; //As condicións para que cada elemento sexa correcto:
    incorrecta.month = data.month < 0 || data.month > 12;
    incorrecta.day = !incorrecta.month && (((data.day > meses[data.month-1]) || (data.day < 1)) && !(bisesto(data.year) && (data.day == 29)));
    incorrecta.year = data.year == 0;
    return incorrecta;
}

//Calcula os días que van dende o comezo do ano para unha data dada
int days_so_far(Date d){
    int resultado = 0;
    meses[1] += bisesto(d.year);
    for(int i = 0; i < d.month-1; i++){
        resultado = resultado + meses[i];
    }
    resultado = resultado + d.day;
    meses[1] -= bisesto(d.year);
    return resultado;
}

//Calcula os días que van dende a data dada e o final do ano
int days_to_come(Date d){
    int resultado = 365 + bisesto(d.year);
    resultado -= days_so_far(d);
    return resultado;
}

//Devolve o número de anos bisestos entre dúas datas
int days_in_years(int y1, int y2){
    int days = 0;
    for(int i = (y1 + 1); i < y2 ; i++){
        days += 365;
        if(bisesto(i)) days += 1;
    }
    return days;
}

#endif //DISTANCIA_DIAS_H
