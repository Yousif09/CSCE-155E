/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-12-5
 *
 * Tester file for the searching/sorting of an airport database
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "airport.h"

 int main(int argc, char **argv) {



    int n = 6;
    Airport airports[] =
{
    {"JFK", "International", "John F Kennedy International Airport", 40.64, -73.78, 13, "New York", "US"},
    {"LAX", "International", "Los Angeles International Airport", 33.94, -118.41, 38, "Los Angeles", "US"},
    {"ORD", "International", "O'Hare International Airport", 41.97, -87.91, 204, "Chicago", "US"},
    {"DFW", "International", "Dallas/Fort Worth International Airport", 32.8998, -97.0403, 185, "Dallas", "US"},
    {"DEN", "International", "Denver International Airport", 39.8561, -104.6737, 1655, "Denver", "US"},
    {"ATL", "International", "Hartsfield–Jackson Atlanta International Airport", 33.6407, -84.4277, 313, "Atlanta", "US"}
};
    generateReports(airports, n);


    return 0;
 }