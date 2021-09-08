//
//  main.c
//  smet_23dic2020-01
//
//  Created by andreaagostini on 23/12/2020.
//  Copyright © 2020 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...

    int a = 1;
    int b = 2;
    
    
    // && -> AND
    // || -> OR
    
    double aa = cos(0) + sin(1);
    
    // ! -> NOT
    // ^ -> XOR
    
    
    // l'operatore OR valuta il secondo termine solo se il primo termine è falso
    if (a == 1 || b == 2) { // b == 2 non viene valutato
        printf("blabla\n");
    }
    
    // l'operatore AND valuta il secondo termine solo se il primo termine è vero
    if (a == 10 && b == 2) { // b == 2 non viene valutato
        printf("blabla\n");
    }
    
    printf("1 - a vale %d\n", a);
    printf("2 - guarda: %d\n", a = 123);
    printf("3 - a vale %d\n", a);
    
    
    if (b == 2 || (a = 1234) == 1234) {
        printf("4 - a vale %d\n", a);
    }

    a = b = 5;
    
    
    double f = 440.;
    printf("f vale %lf\n", f);
    f *= 2; // equivalente a f = f * 2;
    printf("f vale %lf\n", f);
    f = f * 2;
    printf("f vale %lf\n", f);
    f = f * 2;
    printf("f vale %lf\n", f);

    int v1, v2;
    
    v1 = 1;
    v2 = 0;
    
    int nuovo;
    printf("vero o falso? ");
    scanf("%d", &nuovo);
    v1 = v1 && nuovo;
    v2 = v2 || nuovo;
    
    printf("vero o falso? ");
    scanf("%d", &nuovo);
    v1 = v1 && nuovo;
    v2 = v2 || nuovo;
    
    printf("vero o falso? ");
    scanf("%d", &nuovo);
    v1 = v1 && nuovo;
    v2 = v2 || nuovo;
    
    if (v1) {
        printf("tutti veri\n");
    } else if (!v2) {
        printf("tutti falsi\n");
    } else {
        printf("un po' e un po'\n");
    }
    
    
    // += -= *= /= %=
    
    
    
    a += 1;
    b -= 1;
    
    ++a; // equivalente ad a += 1 e ad a = a + 1: operatore preincremento
    --a; // equivalente ad a -= 1 e ad a = a - 1: operatore predecremento
    a = 1;
    printf("5 - %d\n", ++a); // stampa 2 <<<<----
    printf("6 - %d\n", a); // stampa 2

    a++; // operatore postincremento
    a--; // operatore postdecremento
    
    a = 1;
    printf("7 - %d\n", a++); // stampa 1 <<<<----
    printf("8 - %d\n", a); // stampa 2
    
}








