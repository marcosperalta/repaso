#ifndef WHEATHER_UTILS_H
#define WHEATHER_UTILS_H

#include <stdio.h>

#include "array_helpers.h"
#include "weather.h"

void i_array_dump(int array[]);

int min_record_temperature(WeatherTable a);

void max_temperature_in_year(WeatherTable a, int output[YEARS]);

void max_monthly_rainfall(WeatherTable a, month_t output[YEARS]);



#endif // WHEATHER_UTILS_H
