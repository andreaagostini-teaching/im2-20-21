//
//  main.c
//  smet2021-pointers-002
//
//  Created by andreaagostini on 13/09/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <math.h>

//#define ARR_DIM 1000

const int ARR_DIM = 10000000;

// stack allocation, usata fin qui
// heap allocation

double ipotenusa(const double cat1, const double cat2);

double ipotenusa(const double cat1, const double cat2)
{
    double i = sqrt(cat1*cat1 + cat2*cat2);
    return i;
}

/*
 
 
 stack: struttura LIFO
  (last in, first out)
 
 main(): parametri, variabili
 
 stack allocation (quella che si fa dichiarando una variabile)
 heap allocation
 
 */


void riempiarray(int n, int arr[])
// oppure (peggio) (int *arr)
{
    for (int i = 0; i < ARR_DIM; i++) {
        arr[i] = i;
    }
}

int calcolasomma(const int arr[])
{
    int sum = 0;
    for (int i = 0; i < ARR_DIM; i++) {
        sum += arr[i];
    }
    return sum;
}



int main(int argc, const char * argv[]) {
    // insert code here...

    int arr[ARR_DIM];
    //ARR_DIM = 20;
    riempiarray(10, arr);
    for (int i = 0; i < ARR_DIM; i++)
        printf("%d\n", arr[i]);
    
    
    
    return 0;
}
