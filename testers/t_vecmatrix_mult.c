// ##--------------------------------t_vecmatrix_mult - comparation file------------------------------------
// ## Copyright (C) 2020 by
// ## Belinda Brown Ramírez
// ## timna.brown@ucr.ac.cr
// ##	Vector and Matrix Multiplication - COMPARATION
// ##-----------------------------------------------------------------------------

// ##########   IMPORTING  PACKAGES ##########
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "../lib/vecmatrix_parallel.c"
#include "../lib/vecmatrix_serial.c"

// ########## DEFINITIONS OF NECESSARY FUNCTIONS ##########
// Characteristics
#define T_AMOUNT_THREADS 1

// Comparing serial result versus parallel result
int t_vecmatrix_status()
{
    // ########## VARIABLES ##########
    int n0 = 0; 
    int n1 = 0;
    int assert = 0;
    int miss = 0;
    clock_t start;
    ///////// INPUT 
    int rand_values = round(rand()%start);
    if (abs(rand_values) < 100)
    {
        rand_values = rand_values;
    }
    else
    {
        rand_values = round(rand_values / 2819);
    }
    /////////////////////


    // CALLING SERIAL
    int ver_serial = vecmatrix_serial(rand_values);
    // printf("\nVerifying VALUE SERIAL:               %d", ver_serial);
    ////////////////////////////

    // CALLING PARALLEL
    // int ver_parallel = vecmatrix_parallel(rand_values);
    // printf("\nVerifying VALUE PARALLEL:             %d", ver_parallel);

    pthread_t threads[T_AMOUNT_THREADS];

    while (n0 < T_AMOUNT_THREADS){
        pthread_create(&threads[n0], NULL, (void *)vecmatrix_parallel, &threads[n0]);
        n0++;
    }

    while (n1 < T_AMOUNT_THREADS) {
        pthread_join(threads[n1], NULL);
        n1++;
    }

    // // COMPARE
    // float err_byelement = ver_serial / ver_parallel;
    // printf("\nERROR              %f", err_byelement);
    // printf("\nERROR RATE ON THE POSITION:                %f %c", (err_byelement - 1), 37);
    // if (err_byelement <= 1.1)
    // {
    //     assert++;
    // }
    // else
    // {
    //     miss++;
    // }
    // ////////////////
    // printf("\nTotal of asserts:            %d", assert);
    // printf("\nTotal of misses:             %d", miss);

    return 0;

}
