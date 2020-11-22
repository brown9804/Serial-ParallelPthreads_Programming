#ifndef PISERIAL
#define PISERIAL

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
#include <iostream>
#include <math.h>

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
#define ITER 100
#define CIRCUFERENCE 900

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
int i = 0;
double radio = 0.0;
double pi_result = 0.0;
unsigned double pi_sum = 0.0;
unsigned double pi_average = 0.0;

// ########## DEFINITION ##########
double serial_calculation(){

    for (i = 0; i <= ITER; i++){
        // Getting random radio
        radio = (double)rand() / CIRCUFERENCE;
        pi_result = CIRCUFERENCE / (2 * radio);
        pi_sum = pi_sum + pi_result;
    }

    // AVEGAGE...
    pi_average = pi_sum/ITER;
    printf("PI result using SERIAL calculation:                  ", pi_average);

    return pi_average;
}

#endif