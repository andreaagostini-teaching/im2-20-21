//
//  main.c
//  smet002
//
//  Created by andreaagostini on 23/12/2020.
//  Copyright © 2020 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {

    /*
    double a, b;
    
    
    // a = 1: eseguito prima dell'inizio del ciclo
    // a <= 1000000: valutato prima di ogni iterazione
    // a *= 2: eseguito dopo ogni iterazione
    for (a = 1, b = 1;
         a <= 1000000 && b <= 1000000000;
         a *= 2, b *= 3) {
        
        printf("e %lf e %lf\n", a, b);

    }
    printf("fine\n");
    
    */
    double f;
    int i;
    for (f = 1.5, i = 1; fabs(f - 1) > 0.02; i++) {
        printf("%lf\n", f);
        f *= 1.5;
        if (f >= 2.)
            f /= 2.;
    }
    
    f = 1.5;
    while (fabs(f - 1) > 0.02) { // ripete il ciclo finché la condizione rimane vera
        printf("%lf\n", f);
        f *= 1.5;
        if (f >= 2.)
            f /= 2.;
    }
    
    
    
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }
    
    
    int n = -1;
    int sum = 0;
    while (n != 0) {
        scanf("%d", &n);
        sum += n;
    }
    printf("sum vale %d\n", sum);
    
    
    sum = 0;
    do {
        scanf("%d", &n);
        sum += n;
    } while (n != 0);
    printf("sum vale %d\n", sum);

    
    
    return 0;
}
