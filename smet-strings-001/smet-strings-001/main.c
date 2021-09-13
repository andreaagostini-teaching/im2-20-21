//
//  main.c
//  smet-strings-001
//
//  Created by andreaagostini on 13/09/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* prendistringa(int size);


int main(int argc, const char * argv[]) {

    char str[10]; // lunghezza max: 9 char
    
    /*
     ASCII:
     13: CR (carriage return)
     32: spazio
     48-57: cifre decimali
     65-90: A-Z
     97-122: a-z
     */
    
    str[0] = 'c'; // cioè str[0] = 99;
    str[1] = 'i'; // cioè str[1] = 105;
    str[2] = 'a'; // cioè str[2] = 97;
    str[3] = 'o'; // ecc.
    str[4] = 0; // non: str[4] = '0';!!!
                // che equivarrebbe a str[4] = 48;

    char str2[5] = "ciao";
    
    printf("%s\n", str);
    
    for (int i = 0; i < 5; i++) {
        printf("%d\n", str[i]);
    }
    
    int i;
    printf("seconda versione:\n");
    for (i = 0; str[i] != 0; i++) {
        printf("%d\n", str[i]);
    }
    printf("dimensione: %d\n", i);
    
    printf("sizeof(arr): %d\n", sizeof(str));
    
    
    int size;
    printf("quanto lunga? ");
    scanf("%d", &size);
    
    char *heapstr = prendistringa(size);
    
    printf("%p: %s\n", heapstr, heapstr);
    
    
    // esercizio 1: riempire heapstr di lettere a caso
    
    char *txt = "abcde";
    printf("%p: %s\n", heapstr, heapstr);

    int n;
    for (n = 0; txt[n] != 0; n++) {
        heapstr[n] = txt[n];
    }
    heapstr[n] = 0;
    
    // alternativa brutta:
    int p = -1;
    do {
        p++;
        heapstr[p] = txt[p];
    } while (txt[p] != 0);
    
    // esercizio: creare una funzione che concatena due stringhe
    // passare due stringhe alla funzione
    // ottenere una stringa composta dalla concatenazione delle due
    // ho varie possibilità:
    // 1. può essere un costruttore: char* concatena(const char* s1, const char* s2);
    // 2. riceve anche un puntatore in cui mette la stringa risultante: void concatena(const char* s1, const char* s2, char* dst);
    // 2b. stessa cosa ma sapendo quanti caratteri posso scrivere: void concatena(const char* s1, const char* s2, int n, char* dst);
    // 3. aggiunge la seconda stringa in coda alla prima: void concatena(char* s1, const char* s2);
    // 3b. stessa cosa sapendo quanti caratteri: ...
    
    // altre funzioni di esercizio:
    // rovesciare una stringa: ciao -> oaic
    // ruotare una stringa: ciao mamma, 2 -> ao mammaci (o maciao mam)
    // interpolare due stringhe: mamma, babbo -> mbaambmbao
    
    
    unsigned long l = strlen(txt);
    
    const char *s = "abc"; // dove metto un letterale di stringa, dovrei dichiararlo come const char
    const char *t = "def";
    //char *u = strcat(s, t); // sbagliato perché il primo termine non è const, e quindi non posso passarlo da un letterale presente nel codice
    char *sdup = malloc(100);
    strcpy(sdup, s); // non è un costruttore (strdup lo è)
    // ora ho in sdup una copia di s che posso modificare
    char *u = strcat(sdup, t); // posso farlo perché lavoro su sdup che ho il diritto di modificare
    
    
    
    
    printf("%p: %s\n", heapstr, heapstr);

    printf("dammi qualcosa: ");
    int fuffa;
    scanf("%d", &fuffa);
    
    return 0;
}




char* prendistringa(int size)
{
    char *s = malloc(size + 1);
    s[0] = 0;
    return s;
}


