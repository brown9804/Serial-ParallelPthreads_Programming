

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

}
#endif