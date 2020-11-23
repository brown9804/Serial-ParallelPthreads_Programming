
// ##--------------------------------pi serial file------------------------------------
// ##
// ## Copyright (C) 2020 by 
// ## Belinda Brown Ramírez 
// ## timna.brown@ucr.ac.cr
// ##	Pi SERIAL
// ##
// ##-----------------------------------------------------------------------------

// ##########   IMPORTING  PACKAGES ##########
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
#define ITER 100

// ########## SERIAL CALCULATION ##########
// USING CIRCLE METHOD
// According with Archimedes pi is between 223/71  and 22/7
// so pi = [3.14084507, 3.142857143]
// Using the circule method
// pi = circuference of circule / diameter
// Where:
// 1. Circuference of circule = pi * d
// 2. Diameter  = 2*radio
// It is going to be done for ITER times

// ########## VARIABLES ##########
int n = 0;
double radio = 0.0;
double pi_result = 0.0;
double pi_sum = 0.0;
double pi_average = 0.0;

// ########## DEFINITION ##########
// Leibniz formula for pi calculation
// xn+1 = xn + (-1)^n / 2n+1     , x0 = 1
double serial_calculation(){

    while (n < ITER){
        double power1 = pow(-1, n);
        double den = 2 * n + 1;
        double serie = power1 / den;
        pi_result = pi_result + 4 * serie;
        n++;

        pi_sum = pi_sum + pi_result;
    }

    // AVEGAGE...
    pi_average = pi_sum/n;
    printf("\nPI result using SERIAL calculation:                    %f\n", pi_average);

    return pi_average;
}
