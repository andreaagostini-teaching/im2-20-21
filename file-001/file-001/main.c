//
//  main.c
//  file-001
//
//  Created by andreaagostini on 08/10/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>


void incrementa(int *i);
void weird_destructor(FILE** fileptr_ptr);

int main(int argc, const char * argv[]) {
    // insert code here...

    FILE *fileptr;
    
    // COSTRUTTORE
    fileptr = fopen("/Users/andreaagostini/devel/c/smet20-21/filetext.txt", "rt");
    // r/w --- t/b
    
    // Wav / Aif
    // HEADER
    // BODY
    
    if (fileptr == NULL) { // il file non esiste o comunque non riesco ad aprirlo
        printf("il file non esiste\n");
        return 1; // uscire da main() con 1 convenzionalmente indica un errore
    }
    
    // se arrivo qui il file c'è ed è valido
    int i;
    fscanf(fileptr, "%d", &i);
    printf("dice %d\n", i);
    
    // fgetc(): prende un byte
    // fprintf(): scrive testo
    // fputc(): scrive un byte
    // feof(): il file è finito?
    
    // DISTRUTTORE
    fclose(fileptr);
    // da qui in avanti fileptr non è più valido
    fileptr = NULL;
    
    incrementa(&i); // &i è l'indirizzo di un int, cioè un int*
    printf("incrementato: %d\n", i);
    
    
    
    // analogamente:
    // weird_destructor(&fileptr); // &fileptr è l'indirizzo di un FILE*, cioè un FILE**
    
    fileptr = fopen("/Users/andreaagostini/devel/c/smet20-21/filetext.txt", "rb");


    while(1) {
        int ch = fgetc(fileptr);
        if (ch == EOF)
            break;
        printf("%d\n", ch);
    }
    
    // questo di solito non si fa
    weird_destructor(&fileptr);
    printf("e adesso fileptr vale %p\n", fileptr);

    return 0;
}


// FILE *ptr_array[];
// FILE **ptr_array;

// il doppio asterisco vuol dire:
// - puntatore a puntatore
// oppure
// - array di puntatori
// oppure anche
// - array di array

// questo è un distruttore non convenzionale
// che chiude il file e pone il suo puntatore a NULL
void weird_destructor(FILE** fileptr_ptr)
{
    fclose(*fileptr_ptr); // passo il puntatore a FILE (cioè un tipo FILE*)
    *fileptr_ptr = NULL; // assegno al puntatore a FILE (FILE*) un nuovo valore
}


void incrementa(int *i)
{
    *i = *i + 1;
}

