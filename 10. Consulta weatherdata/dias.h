//dias.h

int meses[13] = {31,28,31,30,31,30,31,31,30,31,30,31};

//Comproba se un ano é bisesto ou non
int bisesto(int ano) {
    if(((ano%4 == 0) & (ano%100 != 0)) || (ano%400 == 0)) return 1;
    else  return 0;
}

//Conta os días que van dende o comezo do ano para unha data dada
int days_in_year(Date d) {
    int resultado = 0;
    
    if(bisesto(d.year))  meses[1]++;
    for(int i = 0; i < d.month-1; i++){
        resultado = resultado + meses[i];
    resultado = resultado + d.day;
        
    return resultado;
}

//Conta os días que van dende o 01/01/2000
int days_since_2000(Date d) {
    int days = days_in_year(d);
    
    for(int i = 2000; i  < d.year; i++){
        if(bisesto(i))  days += 366;
        else            days += 365;
    }
    
    return days;
}

//Comproba se algún dos elementos da data son incorrectos, devolvendo un 1 se o son
Date data_invalida(Date data){
    Date incorrecta;
    incorrecta.month = data.month < 0 || data.month > 12;
    incorrecta.day = !incorrecta.month && (((data.day > meses[data.month-1]) || (data.day < 1)) && !(bisesto(data.year) && (data.day == 29)));
    incorrecta.year = data.year < 2000 || data.year > 2010;
    return incorrecta;
}

//Crea unha estrutura Date a partir do input, asegurándose de que a data é válida
Date get_date(){
    Date temp = {.day = 2, .month = 1, .year = 2000};
    do{
        if(data_invalida(temp).day || data_invalida(temp).month || data_invalida(temp).year){
            //Isto imprímese se houbo algún dato incorrecto na anterior volta
            printf("\nVolva intentalo");
            if(data_invalida(temp).day) printf(" (dia non valido)");
            if(data_invalida(temp).month) printf(" (mes non valido)"); 
            if(data_invalida(temp).year) printf(" (ano non valido)");
            printf(":\n");
        }else{
            //Isto imprímese a primeira vez que se pregunta a data
            printf("Escriba a data en formato dd/mm/aaaa (entre o ano 2000 e o 2010):\n"); 
        }

        scanf("%d/%d/%d", &temp.day, &temp.month, &temp.year);
        //Este bucle convirte input (string con formato "dd/mm/aaaa" a un vector de int (data)
    }while(data_invalida(temp).day || data_invalida(temp).month || data_invalida(temp).year);
    
    return temp;
}
