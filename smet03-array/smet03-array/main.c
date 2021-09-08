//
//  main.c
//  smet03-array
//
//  Created by andreaagostini on 23/12/2020.
//  Copyright © 2020 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABSIZE 10000

const int k_TABSIZE = 10000;

int main(int argc, const char * argv[]) {
    
    int a[100]; // elementi da 0 a 99
    
    srand((unsigned int) time(NULL));
    //srand(101);
    
    
    int i;
    for (i = 0; i < 100; i++) {
        a[i] = rand() % 100; // restituisce valori tra 0 e RAND_MAX
    }

    for (i = 0; i < 100; i++) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
