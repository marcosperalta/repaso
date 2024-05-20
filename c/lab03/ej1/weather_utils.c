#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"

typedef unsigned int uint;

void i_array_dump(int array[]) {
    printf("La temperatura máxima de cada año es [ ");
    for (uint year = 0; year < YEARS; year++) {
        printf("%d ", array[year]);
    }
    printf("]\n");
}

int min_record_temperature(WeatherTable a) {
    // asigno la temperatura min del día 1
    int result = a[0][0][0]._min_temp;

    for (uint year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (uint day = 0u; day < DAYS; ++day) {
                if (result < a[year][month][day]._min_temp) {
                    result = a[year][month][day]._min_temp;
                }
            }
        }
    }
    printf("\nLa temperatura mínima registrada es de: %d\n\n", result);
    return result;
}

// funcion interna, que retorna la temp máx un año dado
static int max_record_temperature(WeatherTable a, int year) {
    // asigno la temperatura max del día 1 del año dado
    int result = a[year][0][0]._max_temp;

    for (month_t month = january; month <= december; ++month) {
        for (uint day = 0u; day < DAYS; ++day) {
            if (result < a[year][month][day]._max_temp) {
                result = a[year][month][day]._max_temp;
            }
        }
    }
    //printf("\nLa temperatura máxima registrada el año %u es: %d\n", year+FST_YEAR, result);
    return result;
}


void max_temperature_in_year(WeatherTable a, int output[YEARS]) {
    for (uint year = 0u; year < YEARS; year++) {
        output[year] = max_record_temperature(a, year);
    }
}

const char* get_month_name(month_t month) {
    static const char *month_names[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    // Verificar que el valor de month esté en el rango válido
    if (month >= january && month <= december) {
        return month_names[month];
    } else {
        return "Invalid month";
    }
}

void max_monthly_rainfall(WeatherTable a, month_t output[YEARS]) {    
    uint result;
    month_t month_result;
    //uint j_year, j_month, j_day;
   
    for (uint year = 0u; year < YEARS; ++year) {
        month_result = january;
        result = a[year][0][0]._rainfall;
        for (month_t month = january; month <= december; ++month) {
            
   
            for (uint day = 0u; day < DAYS; ++day) {
   
                if (result < a[year][month][day]._rainfall) {
                    result = a[year][month][day]._rainfall;
                    month_result = month;
                    // j_year = year;
                    // j_month = month;
                    // j_day = day;
                }
            }
        }
        output[year] = month_result;
        //printf("\nEl día es: (%u/%u/%u)\n", j_year+FST_YEAR, j_month+1, j_day+1);
        printf("\n El mes que más llovió en el año %u es %s ", year+FST_YEAR, get_month_name(month_result));
    }
}
