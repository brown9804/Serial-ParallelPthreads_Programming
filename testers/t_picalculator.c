// ##--------------------------------pi calculator - comparation file------------------------------------
// ## Copyright (C) 2020 by 
// ## Belinda Brown Ramírez 
// ## timna.brown@ucr.ac.cr
// ##	Pi Calculator - COMPARATION
// ##-----------------------------------------------------------------------------

// ##########   IMPORTING  PACKAGES ##########
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "../lib/piparallel.c"
#include "../lib/piserial.c"

// ########## DEFINITIONS OF NECESSARY FUNCTIONS ##########
// Characteristics
#define AMOUNT_THREADS 8
#define ITER 100

// Comparing serial result versus parallel result
int t_picalculator()
{
    // ########## VARIABLES ##########
    double pi_serial_result = 0.0;
    double pi_parallel_result = 0.0;
    int n0 = 0;
    int n1 = 0;

    // CALLING SERIAL
    pi_serial_result = serial_calculation();
    ////////////////////////////
    pi_parallel_result = piparallel_calculator();

    // CALLING PARALLEL
    pthread_t threads[AMOUNT_THREADS];

    while (n0 < AMOUNT_THREADS){
        pthread_create(&threads[n0], NULL, (void *)piparallel_calculator, &threads[n0]);
        n0++;
    }


    while (n1 < AMOUNT_THREADS) {
        pthread_join(threads[n1], NULL);
        n1++;
    }

    printf("\nPI result using PARALLEL calculation:                  %f", pi_parallel_result);

    ////////////////////

    // COMPARE
    double err = pi_serial_result / pi_parallel_result;
    printf("\nERROR RATE:                %f %c", (err-1), 37);

    if ((pi_serial_result == pi_parallel_result) || (err <= 1.1))
    {
            return 0;
    }

    else {
        return 7;
    }
    ////////////////////////////
}
