#ifndef WHEATHER_UTILS_H
#define WHEATHER_UTILS_H

#include <stdio.h>

#include "array_helpers.h"
#include "weather.h"


int min_record_temperature(WeatherTable a);

void max_temperature_in_year(WeatherTable a, int *output[YEARS]);

void max_monthly_rainfall(WeatherTable a, int *output[YEARS][MONTHS]);



#endif // WHEATHER_UTILS_H