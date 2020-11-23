// ##--------------------------------pi parallel file------------------------------------
// ##
// ## Copyright (C) 2020 by 
// ## Belinda Brown Ramírez 
// ## timna.brown@ucr.ac.cr
// ##	Pi Parallel
// ##
// ##-----------------------------------------------------------------------------

// ##########   IMPORTING  PACKAGES ##########
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
#define AMOUNT_THREADS 8
#define ITER 100

// ########## PARALLEL CALCULATION ##########
// Using a mutex - MUTual EXclusion
// Mutex is a way for explicit synchronization,

// ########## DEFINITION ##########
// Leibniz formula for pi calculation
// xn+1 = xn + (-1)^n / 2n+1     , x0 = 1


double piparallel_calculator(){
    // ########## VARIABLES ##########
    double pi_thread_result = 0.0;
    double pi_average = 0.0;
    double power1 = 0.0;
    double den = 0.0;
    double serie = 0.0;

    // ########## OP ##########
    pthread_mutex_t mutex; // MUTual EXclusion
    int n = 0;
    int iter_pthreads = ITER * AMOUNT_THREADS;

    while (n < iter_pthreads)
    {
        power1 = pow(-1, n);
        den = 2*n+1;
        serie =  power1 / den;
        pi_thread_result = pi_thread_result +  4* serie;
        pi_average += pi_thread_result;
        // FOR TESTS
        //printf("\nPI Calculation #%d \nResult using PARALLEL calculation:                  %f", n, pi_thread_result);
        n++;
    }

    pthread_mutex_lock(&mutex);
    pi_average = pi_average/iter_pthreads;
    pthread_mutex_unlock(&mutex);

    return pi_average;
}


