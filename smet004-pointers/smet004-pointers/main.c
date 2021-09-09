//
//  main.c
//  smet004-pointers
//
//  Created by andreaagostini on 09/09/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// dichiarazione o prototipo
int doppio(int n); // dichiarazione: c'è il punto e virgola!
int fattoriale(int n);

void saluti(int n); // funzione senza valore di ritorno

void dueVolteISaluti(void); // funzione senza valore di ritorno e senza argomenti

void incrementa(int *p);

void incrementaQ(int *a, int *b);
void incrementaQgiusto(int *a, int b);

int incrementaCorretto(int a, int b);

int main(int argc, const char * argv[]) {
    int a = 123; // ###
    printf("a: %d\n", a);
    
    int* p; // puntatore a intero ###
    p = &a; // assegno a p l'indirizzo di a
    
    printf("p: %p\n", p); // 4c55fe....
    printf("*p: %d\n", *p); // 123
    printf("&a: %p\n", &a); // lo stesso di p

    a = 456;
    printf("p: %p\n", p); // lo stesso di prima
    printf("*p: %d\n", *p); // 456
    printf("&a: %p\n", &a); // lo stesso di prima
    
    double f = 3.14;
    double s = sin(f);
    printf("sin(f) = %f\n", s);
    
    int d = doppio(a);
    printf("doppio(a): %d\n", d); // 912
    
    if (a % 2 == 0) {
        int k;
        k = (a+2)*3/5;
        printf("k vale %d\n", k);
    }
    
    //int l = k+10; //<--- SBAGLIATO: k non è visibile qui
    
    dueVolteISaluti();
    
    int x, y;
    //printf("dammi i valori per x e y: ");
    //scanf("%d %d", &x, &y); // "immetti un valore in x e y"
    
    //printf("e adesso x e y valgono %d e %d\n", x, y);

    incrementa(&x);
    incrementa(&y);
    
    printf("e adesso x e y valgono %d e %d\n", x, y);
    
    incrementaQ(&x, &y);
    
    incrementaQgiusto(&x, y);
    incrementaQgiusto(&x, 10);
    // incrementaQ(&x, &10); SBAGLIATO
    // incrementaQ(&x, &(y+1)); SBAGLIATO
    
    y = incrementaCorretto(y, 10);

    
    int arr[10];
    
    arr[0] = 1;
    arr[1] = 4567;
    arr[2] = 98765;

    // equivalente a
    *(arr) = 1;
    *(arr + 1) = 4567;
    *(arr + 2) = 98765;

    printf("%p\n", arr); // è un puntatore a intero
    printf("%d\n", arr[0]); // è un intero
    printf("%p\n", &arr[0]); // è un puntatore a intero

    srand((unsigned int) time(NULL));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand();
    }
    
    int *ptr = arr; // ptr è inizializzato al puntatore al primo elemento dell'array (cioè a arr)
    for (int i = 0; i < 10; i++) {
        printf("passo %d: %p\n", i, ptr);
        *ptr = rand(); // metto un numero casuale in *ptr
        ptr++;
    }
    
    
    
    
    
}




// Python: def doppio(n):
int doppio(int n) // definizione: non c'è il punto e virgola!
{
    int d = n * 2;
    printf("chamata doppio(%d)\n", n);
    return d;
}



int fattoriale(int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fattoriale(n - 1);
    }
    
    
}



void dueVolteISaluti(void)
{
    saluti(2);
}

void saluti(int n)
{
    // e nel finale due volte i saluti
    printf("e nel finale %d volte i saluti\n", n);
    for (int i = 0; i < n; i++) {
        printf("saluti\n");
    }
}

// passaggio "per riferimento":
// passo alla funzione l'indirizzo di una variabile
void incrementa(int *p)
{
    // *p++ è equivalente a...
    // (*p)++ NO!
    // *(p++) <<<--- SI!!!
    
    //(*p)++; oppure
    *p += 1;
}

void incrementaQ(int *a, int *b)
{
    //*a += *b;
    *a = *a + *b;
    
}


void incrementaQgiusto(int *a, int b)
{
    *a += b;
}


int incrementaCorretto(int a, int b)
{
    return a+b;
}




