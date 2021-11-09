#ifndef WEATHER3_WEATHER_H
#define WEATHER3_WEATHER_H

typedef struct Date{
    int day;
    int month;
    int year;
} Date;


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

//Imprime os datos tipo WeatherData
void print_weatherdata(WeatherData wdata){
    printf("\n{\n   Date (mm/dd/yyyy): %02d/%02d/%04d\n   Longitude: %f\n   Latitude: %f", wdata.date.month, wdata.date.day, wdata.date.year, wdata.longitude, wdata.latitude);
    printf("\n   Elevation: %d\n   Max. temperature: %f\n   Min. temperature: %f", wdata.elevation, wdata.max_temp, wdata.min_temp);
    printf("\n   Precipitation: %f\n   Wind: %f\n   Relative humidity: %f\n   Solar: %f\n}\n", wdata.precipitation, wdata.wind, wdata.rel_humidity, wdata.solar);
}

#endif //WEATHER3_WEATHER_H
