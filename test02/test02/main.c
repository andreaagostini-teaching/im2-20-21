//
//  main.c
//  test02
//
//  Created by andreaagostini on 23/11/2020.
//  Copyright © 2020 Andrea Agostini. All rights reserved.
//

#include <stdio.h> // standard input-output header
#include <math.h>

int main(int argc, const char * argv[]) { // definizione di funzione
    // insert code here...
    
    // Python: weakly, dynamically typed
    // C: strongly, statically typed
    
    int i; // da qui in avanti posso usare una variabile i di tipo intero, probabilmente a 32 bit
    long l; // probabilmente un intero a 64 bit
    float x; // idem ma float, probabilmente a 32 bit
    double d; // float probabilmente a 64 bit
    
    // nomi di variabili:
    // - non iniziare con underscore
    // - iniziare con una lettera minuscola
    // - nomi lunghi: datalength / data_length / dataLength
    // - i nomi sono case sensitive
    // - mai utilizzare tutte maiuscole
    
    i = 2;
    x = 3.14;
    d = 1.2345;
    l = 1234567890987654321;
    
    i = 2 + 3;
    x = i * 2.5;
    
    i = x; // perdita di precisione!!!
    
    printf("x vale %f\n", x); // %f: format specifier per valore float
                              // %d: intero decimale
                              // %lf: double
                              // %ld: long
    
    printf("i vale %d, d vale %lf e l vale %ld\n", i, d, l);
    
    d = sqrt(x);
    
    printf("la radice di x vale %lf\n", d);
    
    printf("la radice di d vale %lf\n", sqrt(d));
    
    
    
    double fondamentale;
    
    printf("Quale fondamentale vuoi? ");
    
    scanf("%lf", &fondamentale); // se passo una variabile a scanf, devo introdurla con &
    
    printf("La sua ottava è %lf\n", 2 * fondamentale);
    
    
    
    
    
    
    if (i == 2) { // operatore di uguaglianza è ==
        printf("due\n");
    }
    // è equivalente a
    if (i == 2)  // operatore di uguaglianza è ==
        printf("due\n");
    
    
    if (i == 3) { // operatore di uguaglianza è ==
        printf("tre\n");
        printf("oh yeah\n");
    }
    // NON EQUIVALENTE A
    if (i == 3) // operatore di uguaglianza è ==
        printf("tre\n");
    printf("oh yeah\n"); // L'INDENTAZIONE NON E` SINTATTICA! questa riga viene eseguita comunque
                         // non è soggetta alla condizione
    
    
    

    
    if (fondamentale == 440 || fondamentale == 220) { // OR logico ||          AND logico &&
        printf("ma è un la!!!\n");
    } else {
        if (fondamentale == 261.5 || fondamentale == 523) {
            printf("è un do...\n");
        } else {
            printf("eh no\n");
        }
    }
    /////// EQUIVALE A
    if (fondamentale == 440 || fondamentale == 220) { // OR logico ||          AND logico &&
        printf("ma è un la!!!\n");
    } else
        if (fondamentale == 261.5 || fondamentale == 523) {
            printf("è un do...\n");
        } else {
            printf("eh no\n");
        }
    /////// EQUIVALE A
    if (fondamentale == 440 || fondamentale == 220) { // OR logico ||          AND logico &&
        printf("ma è un la!!!\n");
    } else if (fondamentale == 261.5 || fondamentale == 523) {
        printf("è un do...\n");
    } else {
        printf("eh no\n");
    }
    
    
    
    
    if (fondamentale == 440 || fondamentale == 220) { // OR logico ||          AND logico &&
        printf("ma è un la!!!\n");
    } else {
        if (fondamentale == 261.5 || fondamentale == 523) {
            printf("è un do...\n");
        } else if (fondamentale == 330) {
            printf("è un mi\n");
        } else
            printf("boh\n");
    }
    
    if (fondamentale == 440 || fondamentale == 220) { // OR logico ||          AND logico &&
        printf("ma è un la!!!\n");
    } else if (fondamentale == 261.5 || fondamentale == 523) {
        printf("è un do...\n");
    } else if (fondamentale == 330) {
        printf("è un mi\n");
    } else if (fondamentale < 20) {
        printf("davvero?\n");
    } else
        printf("boh\n");
    
    
    
    printf("Hello, World!\n");
    return 0;
}





/*
 
 COMPILAZIONE:
 src01.c contiene main che chiama writemidi() E una dichiarazione di writemidi() -> src01.o
 src02.c -> src02.o
 funzioni_midi.c contiene writemidi() -> funzioni_midi.o
 funzioni_gestione_dati.c ...
 
 LINK:
 src01.o, src02.o, ... -> myapp
 
 
 if a > 0:
    bla
    bla
    bla
 else:
    bla
    bla
    bla
 
 print('ciao')
 
 
 
 
 */
