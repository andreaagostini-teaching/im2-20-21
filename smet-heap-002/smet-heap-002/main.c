//
//  main.c
//  smet-heap-002
//
//  Created by andreaagostini on 13/09/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* prendiarray(void);


int* prendiarray_BAD(void)
{
    int arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    printf("dentro: \n");
    for (int i = 0; i < 10; i++) {
        printf(" %d\n", arr[i]);
    }
    return arr;
}


int* prendiarray(void)
{
    int *arr = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    printf("dentro: \n");
    for (int i = 0; i < 10; i++) {
        printf(" %d\n", arr[i]);
    }
    return arr;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int *arr = prendiarray();
    printf("fuori: \n");
    for (int i = 0; i < 10; i++) {
        printf(" %d\n", arr[i]);
    }
    free(arr);
    return 0;
}
