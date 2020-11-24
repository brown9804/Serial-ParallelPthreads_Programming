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
#include "../testers/t_picalculator.c"
#include "../testers/t_vecmatrix_mult.c"

///////////////////////////////

int main(){

    printf("\n***********************************************************************\n");
    printf("		PI CALCULATOR	");
    printf("\n***********************************************************************\n");

    int picalculator_status = t_picalculator(); 

    if (picalculator_status == 0)
    {
        printf("\n-----------------------------------------------\n");
        printf("PI CALCULATOR --- Status ------->  Serial & Paralel are:\nSAME results");
        printf("\n-----------------------------------------------\n");

        printf("\n\n\n      .' '.               __               ");
        printf("\n .        .   .          (__}'         ");
        printf("\n .         .         . -{{_(|8)         ");
        printf("\n' .  . ' ' .  . '        (__}'             \n");
        // return EXIT_SUCCESS;
    }
    else
    {
        printf("\n-----------------------------------------------\n");
        printf("PI CALCULATOR --- Status ------->  Serial & Paralel are:\nNOT the same results");
        printf("\n-----------------------------------------------\n");
       
       
        printf("\n\n\n      .' '.               __               ");
        printf("\n .        .   .          (__}'         ");
        printf("\n .         .         . -{{_(|8)         ");
        printf("\n' .  . ' ' .  . '        (__}'             \n");
        printf("\nIs going to be a  EXIT_FAILURE\n\n\n");
        // exit(EXIT_FAILURE);
    }

    printf("\n***********************************************************************\n");
    printf("		MATRIX & VECTORS (*) CALCULATOR	");
    printf("\n***********************************************************************\n");

    int vecmatrix_status = t_vecmatrix_status();

    if (vecmatrix_status == 0)
    {
        printf("\n-----------------------------------------------\n");
        printf("\nMATRIX & VECTORS (*) CALCULATOR --- Status -------> \nSerial & Paralel are:\nSAME results\n");
        printf("\n-----------------------------------------------\n");
        // return EXIT_SUCCESS;
    }
    else
    {
        printf("\n-----------------------------------------------\n");
        printf("\nMATRIX & VECTORS (*) CALCULATOR --- Status ------->  \nSerial & Paralel are:\nNOT the same results\n");
        printf("\n-----------------------------------------------\n");
        printf("\nIs going to be a  EXIT_FAILURE\n");
        // exit(EXIT_FAILURE);
    }
}

