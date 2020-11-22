#ifndef PIPARALLEL
#define PIPARALLEL

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
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
#define AMOUNT_THREADS 2
#define ITER 100
#define THREAD (ITER/AMOUNT_THREADS)

// ########## PARALLEL CALCULATION ##########
// Using a mutex - MUTual EXclusion
// Mutex is a way for explicit synchronization,

// ########## VARIABLES ##########
int first_thread_iter = (int)thread_num * THREAD;
int last_thread_iter = first_thread_iter + THREAD;
double pi_thread_result = 0.0;
double pi_result = 0.0;
pthread_mutex_t mutex; // MUTual EXclusion

// ########## DEFINITION ##########
// Leibniz formula for pi calculation
// xn+1 = xn + (-1)^n / 2n+1     , x0 = 1
void *piparallel_calculator(void *thread_num)
{
    for (int n = first_thread_iter; n < last_thread_iter; n++){
        power1 = pow(-1, n);
        den = 2*n+1;
        serie = power1 / den;

        pi_thread_result = pi_thread_result +  4 * serie;
    }

    pthread_mutex_lock(&mutex);
    pi_result = pi_result  + pi_thread_result;
    pthread_mutex_unlock(&mutex);

    printf("PI result using PARALLEL calculation:                  ", pi_result);
}

#endif