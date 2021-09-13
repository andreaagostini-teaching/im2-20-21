//
//  main.c
//  smet-003-heap
//
//  Created by andreaagostini on 13/09/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

const int DIM_ARRAY = 100000000;

void riempiarray(int arr[])
// oppure (peggio) (int *arr)
{
    for (int i = 0; i < DIM_ARRAY; i++) {
        arr[i] = i*i;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int *arr;
    printf("%p\n", arr);
    arr = malloc(DIM_ARRAY * sizeof(int));;
    printf("%p\n", arr);

    printf("Hello, World!\n");
    return 0;
}


/*
 
  ...
  ...
  f2
  f1
  main
 */


