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
#define PARALLEL_PTHREADS 8
// Comparing serial result versus parallel result
int t_vecmatrix_status()
{
    // ########## VARIABLES ##########
    int n0 = 0;
    int n1 = 0;
    int assert = 0;
    int miss = 0;
    int ver_serial = 0;
    void *ver_parallel;
    clock_t start;

    double err_byelement = 0.0;

    ///////// INPUT
    int rand_values = round(rand() % start);
    if (abs(rand_values) < 100)
    {
        rand_values = rand_values;
    }
    else
    {
        rand_values = round(rand_values / 62819);
    }
    /////////////////////

    // CALLING SERIAL
    ver_serial = vecmatrix_serial(rand_values);
    // printf("\nVerifying VALUE SERIAL:               %d", ver_serial);
    ////////////////////////////

    // CALLING PARALLEL
    pthread_t threads[T_AMOUNT_THREADS];

    while (n0 < T_AMOUNT_THREADS)
    {
        pthread_create(&threads[n0], NULL, (void *)vecmatrix_parallel, &threads[n0]);
        n0++;
    }

    while (n1 < T_AMOUNT_THREADS)
    {
        pthread_join(threads[n1], &ver_parallel);
        n1++;
    }

    //////////////////////////////////////////
    // COMPARE
    if ((int)ver_parallel != 0){
        err_byelement = ver_serial / (int)ver_parallel; // castingmake
    }
    else{
        err_byelement = 0.0000;
    }

    printf("\nERROR RATE:                %lf %c", (err_byelement / 100), 37);

    /// ALLOW 5% of error
    if (((err_byelement / 100) == 5.0) || ((err_byelement / 100) <= 5.0))
    {
        assert = 1;
        miss = 0;
    }
    else
    {
        miss = 1;
        assert = 0;
    }
    ////////////////

    if (miss == 0)
    {
        printf("\nEqual Status:             ACTIVE      ");
        printf("\nNOT equal Status:            -        ");
        return 0;
    }
    else
    {
        printf("\nEqual Status:                -        ");
        printf("\nNOT equal Status:          ACTIVE        ");
        return 8;
    }
}