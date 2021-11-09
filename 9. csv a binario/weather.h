//weather.h

//A estutura Date permite un fácil manexo de datas
typedef struct Date{
    int day;
    int month;
    int year;
} Date;

//A estutura Date permite almacenar os datos metereolóxicos con comodidade
typedef struct WeatherData{
    Date date;
    float longitude;
    float latitude;
    int elevation;
    float max_temp;
    float min_temp;
    float precipitation;
    float wind;
    float rel_humidity;
    float solar;
} WeatherData;
