//dvectors.h

#include <stdlib.h>

//A estrutura dvec (Dynamic Vector) garda o tamaño do propio vector dinámico para facilitar o seu manexo
typedef struct dvec {
  WeatherData *vector;
  int size;
} dvec;

//Inicializa un vector dinámico
dvec new_dvec() {
    dvec temp = {(WeatherData*) malloc(sizeof(WeatherData)), 1};
    return temp;
}

//Aumenta o tamaño do vector dinámico en n unidades
dvec increase_size(dvec dvector, int n) {
    dvec temp = new_dvec();
    temp.size = dvector.size + n;
    temp.vector = realloc(dvector.vector, sizeof(WeatherData)*(temp.size));
    return temp;
}
