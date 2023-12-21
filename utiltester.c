#include<stdio.h>
#include<math.h>
#include "util.h"



int main(){

 printf("\nTest cases for function degreesToRadians(); \n");

printf("\n1st : After Converting %.2lf degrees into radians we get : %.2lf",80.00,degreesToRadians(80));
printf("\n2nd : After Converting %.2lf degrees into radians we get : %.2lf",90.00,degreesToRadians(90));
printf("\n3rd : After Converting %.2lf degrees into radians we get : %.2lf",100.00,degreesToRadians(100));


 printf("\nTest cases for function getAirDistance(); \n");

 printf("\n1st : AIR DISTANCE : %.2lf",getAirDistance( 41.9 , 40.8  , -87.6 , -96.7 ));
 printf("\n2ndt : AIR DISTANCE between San Francisco and Los Angeles : %.2lf",getAirDistance( 37.7749 , 34.0522  , -122.4194 , -118.2437 ));
  printf("\n3rdt : AIR DISTANCE between Lahore and Islamabad: %.2lf",getAirDistance( 33.6844 , 31.5497  , 73.0479 , 74.3436 ));
