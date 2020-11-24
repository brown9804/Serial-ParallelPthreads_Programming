// ##-------------------------------- vecmatrix_parallel file------------------------------------
// ## Copyright (C) 2020 by
// ## Belinda Brown Ramírez
// ## timna.brown@ucr.ac.cr
// ##	Multiplication of vectors and matrices - Parallel
// ##-----------------------------------------------------------------------------

// ##########   IMPORTING  PACKAGES ##########
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
clock_t start;

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
#define PARALLEL_AMOUNT_THREADS 8
#define ITER_PARALLEL_MATRIX 1

// ########## DEFINITION ##########
//1. Create random matriz and random vector
//2. nx1 X nxn, where n in range of [3, 8]
int vecmatrix_parallel(int rand_values)
{
    // ########## VARIABLES ##########
    int i = 0;
    int j = 0;
    int x = 0;

    start = clock(); // begin time mark

    // Random dimension [3, 8]
    // example int x =(rand() % 10)+10; from 10 - 20
    int x3 = rand_values % 3; // 0 - 3
    int x8 = rand_values % 8; // 0 - 8
    if ((abs(x8 - x3) != 0) && (abs(x8 - x3) < 100))
    {
        x = abs(x8 - x3);
    }
    else if (abs(x8 - x3) == 0)
    {
        x = 3;
    }
    else
    {
        x = 2;
    }

    // printf("\nDimension:               %d\n", x);

    ///////////////////////
    int matrix[x][x];
    int vector[x][1];
    int matrix_result[x][x]; // mxn X nxm =  mxm

    int sum_results_par = 0;

    ///////////////////////

    // Matrix created
    for (i = 0; i < x; i++) // row
    {
        for (j = 0; j < x; j++) // column
        {
            int value = rand() % start;
            matrix[i][j] = value;
            // printf("matrix[%d][%d] = %d \n", i, j, matrix[i][j]);
        }
    }

    // printf("\n***************************\n");
    // printf("		MATRIX	");
    // printf("\n***************************\n");

    // for (i = 0; i < x; i++) // row
    // {
    //     for (j = 0; j < x; j++) // column
    //     {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // ////////////////////////////////
    // printf("\n\n\n\n");
    // ////////////////////////////////

    // Vector created
    for (i = 0; i < x; i++) // row
    {
        for (j = 0; j < 1; j++) // column
        {
            int value = rand() % start;
            if (abs(value) < 100)
            {
                value = value;
            }
            else if (abs(value) == 0)
            {
                value = 28;
            }
            else
            {
                value = round(value / 62819);
            }
            vector[i][j] = value;
            // printf("vector[%d][%d] = %d \n", i, j, vector[i][j]);
        }
    }

    // printf("\n***************************\n");
    // printf("		Vector 	");
    // printf("\n***************************\n");

    // for (i = 0; i < x; i++) // row
    // {
    //     for (j = 0; j < 1; j++) // column
    //     {
    //         printf("%d ", vector[i][j]);
    //     }
    //     printf("\n");
    // }

    ////////////////////////////////
    //////////// PTHREADS
    ////////////////////////////////
    ////////////////////////////////////
    /////// PARALLEL
    /////// MULTIPLICATION OF MATRIX
    ///////////////////////////////////
    // ########## OP ##########
    pthread_mutex_t mutex; // MUTual EXclusion
    int iter_pthreads = ITER_PARALLEL_MATRIX * PARALLEL_AMOUNT_THREADS;

    for (int num_pthreads = 0; num_pthreads < iter_pthreads; num_pthreads++) // while -> iter_pthreads
    {
        for (int a = 0; a < 1; a++) // columns vector
        {
            for (int i = 0; i < x; i++) // rows matrix
            {
                int sum = 0;
                for (int j = 0; j < x; j++) // column matrix
                {
                    // multiply and sum
                    sum += matrix[i][j] * vector[j][a];
                }
                matrix_result[i][a] = sum;
            }
        }

        // //////////////////
        // ////////////FOR TESTS PTHREADS
        // //////////////////

        // printf("\n*----------------------\n");
        // printf("\nParallel Matrix #%d:\n", num_pthreads);
        // printf("\n*----------------------\n");

        for (int i = 0; i < x; i++) // row vector
        {
            for (int j = 0; j < x; j++) // column vector
            {
                // printf("%d ", matrix_result[i][j]);
                sum_results_par += matrix_result[i][j];
            }
            // printf("\n");
        }
    }

    pthread_mutex_lock(&mutex);
    sum_results_par = sum_results_par / iter_pthreads;
    pthread_mutex_unlock(&mutex);

    return sum_results_par;
}
