/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-12-5
 *
 * Implementations with searching/sorting of an airport database
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

void generateReports(Airport *airports, int n) {

  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);


  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  printAirports(airports, n);

  printf("\nAirports By Type: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  printAirports(airports, n);

  printf("\nAirports By Name: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  printAirports(airports, n);

  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  printAirports(airports, n);

  printf("\nAirports By Country/City: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  printAirports(airports, n);

  printf("\nAirports By Latitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  printAirports(airports, n);

  printf("\nAirports By Longitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printAirports(airports, n);

  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAirports(airports, n);


  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAirport(&airports[0]);

  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAirport(&airports[n-1]);

  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printAirport(&airports[n/2]);

  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  for(int i=0; i<n; i++) {
    if(strcmp(airports[i].city,"New York") == 0 && strcmp(airports[i].countryAbbrv, "US") == 0) {
      printAirport(&airports[i]);
    }
  }
  printf("No New York airport found!\n");


  int largeAirport = 0;
  printf("\nLarge airport: \n");
  printf("==============================\n");
  for(int i=0; i<n; i++) {
    if(strcmp(airports[i].type,"large_airport") == 0) {
      printAirport(&airports[i]);
      largeAirport++;
    }
  }
  if(largeAirport == 0) {
    printf("No large airport found!\n");
  }



  return;
}

char* airportToString(const Airport* a) {
  char temp[1000];
  //this formatting is required but the code may need to be adapted
  // to your definiion of your Airport structure.
  sprintf(temp, "%-8s %-15s %-20s %.2f %.2f %d %-10s %-2s", a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);
  char* result = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
  strcpy(result, temp);
  return result;
}

void printAirports(Airport *airports, int n) {

  for(int i=0; i<n; i++) {
    char *s = airportToString(&airports[i]);
    printf("%s\n", s);
    free(s);
  }

  return;
}


Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {

    if(gpsId == NULL || type == NULL || name == NULL ||
       city == NULL || countryAbbrv == NULL || elevationFeet < 0) {
        return NULL;
       }
    if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return NULL;
    }

    Airport *a = (Airport *) malloc( sizeof(Airport));
    a->gpsId = (char *) malloc( sizeof(char) * strlen(gpsId) + 1);
    strcpy(a->gpsId, gpsId);
    a->type = (char *) malloc( sizeof(char) * strlen(type) + 1);
    strcpy(a->type, type);
    a->name = (char *) malloc( sizeof(char) * strlen(name) + 1);
    strcpy(a->name, name);
    a->latitude = latitude;
    a->longitude = longitude;
    a->elevationFeet = elevationFeet;
    a->city = (char *) malloc( sizeof(char) * strlen(city) + 1);
    strcpy(a->city, city);
    a->countryAbbrv = (char *) malloc( sizeof(char) * strlen(countryAbbrv) + 1);
    strcpy(a->countryAbbrv, countryAbbrv);

    return a;

}


void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {

    if(gpsId == NULL || type == NULL || name == NULL ||
       city == NULL || countryAbbrv == NULL || elevationFeet < 0) {
        return;
       }
    if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return;
    }


        airport->gpsId = (char *) malloc( sizeof(char) * strlen(gpsId) + 1);
        strcpy(airport->gpsId, gpsId);
        airport->type = (char *) malloc( sizeof(char) * strlen(type) + 1);
        strcpy(airport->type, type);
        airport->name = (char *) malloc( sizeof(char) * strlen(name) + 1);
        strcpy(airport->name, name);
        airport->latitude = latitude;
        airport->longitude = longitude;
        airport->elevationFeet = elevationFeet;
        airport->city = (char *) malloc( sizeof(char) * strlen(city) + 1);
        strcpy(airport->city, city);
        airport->countryAbbrv = (char *) malloc( sizeof(char) * strlen(countryAbbrv) + 1);
        strcpy(airport->countryAbbrv, countryAbbrv);

}


int cmpByGPSId(const void* a, const void* b) {
    const Airport *x = (const Airport *) a;
    const Airport *y = (const Airport *) b;

    return strcmp(x->gpsId, y->gpsId);

}

int cmpByType(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return strcmp(x->type, y->type);

}

int cmpByName(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return strcmp(x->name, y->name);

}


int cmpByNameDesc(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  return strcmp(y->name, x->name); // reversin logic from above

}


int cmpByCountryCity(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  int r = strcmp(x->countryAbbrv, y->countryAbbrv);
  if(r == 0) {
    return strcmp(x->city, y->city);
  } else {
    return r;
  }

}


int cmpByLatitude(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  if(x->latitude > y->latitude) {
    return -1;
  } else if(x->latitude < y->latitude) {
    return 1;
  } else {
    return 0;
  }

}

int cmpByLongitude(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  if(x->longitude < y->longitude) {
    return -1;
  } else if(x->longitude > y->longitude) {
    return 1;
  } else {
    return 0;
  }

}


  // helper function to compute air distance:
    double airDistance(double latA, double longA, double latB, double longB) {

        double radLatA = (latA / 180) * M_PI;
        double radLongA = (longA / 180) * M_PI;
        double radLatB  = (latB / 180) * M_PI;
        double radLongB = (longB / 180) * M_PI;

        double diff = radLongB - radLongA;


        double airDist = acos(sin(radLatA) * (sin(radLatB)) + cos(radLatA) * cos(radLatB) * cos(diff)) * 6371;
        return airDist;
    }




int cmpByLincolnDistance(const void* a, const void* b) {
  const Airport *x = (const Airport *) a;
  const Airport *y = (const Airport *) b;

  double firstLocation = airDistance(x->latitude, x->longitude, 40.846176, -96.75471);
  double secondLocation = airDistance(y->latitude, y->longitude, 40.846176, -96.75471);
  if(firstLocation < secondLocation) {
    return -1;
  } else if(firstLocation > secondLocation) {
    return 1;
  } else {
    return 0;
  }

}


    // Helper function to print one airport
    void printAirport(const Airport *a) {
        printf("%s  "  "%s  "  "%s  " "%f  " "%f  " "%d  " "%s  " "%s  \n", a->gpsId, a->type, a->name, a->latitude,
               a->longitude, a->elevationFeet, a->city, a->countryAbbrv);
    }



