//weather.h

typedef struct Date {
    int day;
    int month;
    int year;
} Date;


typedef struct WeatherData {
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
