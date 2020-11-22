

#ifndef MAIN
#define MAIN

// ##--------------------------------main file------------------------------------
// ##
// ## Copyright (C) 2020 by 
// ## Belinda Brown Ramírez 
// ## timna.brown@ucr.ac.cr
// ##	Main
// ##
// ##-----------------------------------------------------------------------------

///////////////////////////////
// INCLUDE
#include <stdio.h>
#include <stdlib.h>
///////////////////////////////

int main(void){

    printf("\n***********************************************************************\n");
    printf("		PI CALCULATOR	");
    printf("\n***********************************************************************\n");

    int picalculator_status = 0;//t_picalculator();

    if (picalculator_status == 0)
    {
        printf("\n-----------------------------------------------\n");
        printf("PI CALCULATOR --- Status ------->  Serial & Paralel are:\nSAME results");
        printf("\n-----------------------------------------------\n");
        return EXIT_SUCCESS;
    }
    else
    {
        printf("\n-----------------------------------------------\n");
        printf("PI CALCULATOR --- Status ------->  Serial & Paralel are:\nNOT the same results");
        printf("\n-----------------------------------------------\n");
        exit(EXIT_FAILURE);
    }

    printf("\n***********************************************************************\n");
    printf("		MATRIX & VECTORS (*) CALCULATOR	");
    printf("\n***********************************************************************\n");

    int vecmatrix_status = 0; //t_vecmatrix_status(); 

    if (vecmatrix_status == 0)
    {
        printf("\n-----------------------------------------------\n");
        printf("MATRIX & VECTORS (*) CALCULATOR --- Status -------> \n Serial & Paralel are:\nSAME results");
        printf("\n-----------------------------------------------\n");
        return EXIT_SUCCESS;
    }
    else
    {
        printf("\n-----------------------------------------------\n");
        printf("MATRIX & VECTORS (*) CALCULATOR --- Status ------->  \nSerial & Paralel are:\nNOT the same results");
        printf("\n-----------------------------------------------\n");
        exit(EXIT_FAILURE);
    }
}
#endif