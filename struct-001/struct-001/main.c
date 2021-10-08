//
//  main.c
//  struct-001
//
//  Created by andreaagostini on 07/10/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LONGSAMPLES

#ifdef LONGSAMPLES
typedef double sample; // 64 bit
#endif

#ifndef LONGSAMPLES
typedef float sample; // 32 bit
#endif

typedef struct {
    sample *s;
    double sr;
    int chans;
    int size;
} audioclip;

audioclip* audioclip_new(int sr, int chans, int size);

// CONSTRUCTOR
// il costruttore restituisce un puntatore valido
// a una struttura oggetto inizializzata
audioclip* audioclip_new(int sr, int chans, int size)
{
    audioclip *c = malloc(sizeof(audioclip));
    
    c->sr = sr;
    c->chans = chans;
    c->size = size;
    // c->sr è equivalente a (*c).sr
    c->s = malloc(size * sizeof(sample));
    
    return c;
}

// DESTRUCTOR
void audioclip_free(audioclip *c)
{
    free(c->s); // libero le risorse associate all'oggetto
    free(c); // e _alla fine_ libero l'oggetto
}


// MODIFIER
void audioclip_gain(audioclip *c, double gain)
{
    for (int i = 0; i < c->size; i++) {
        c->s[i] *= gain;
    }
}


// MODIFIER
void audioclip_rm(audioclip *a, const audioclip *b);


void audioclip_sine(audioclip *a, float freq)
{
    double freqang = freq * 6.28;
    
    for (int n = 0; n < a->size; n++) {
        
        // se sia n che a->sr sono interi,
        // verrà calcolata una divisione intera
        // (che non vogliamo!)
        double x = n / a->sr / freq;

    }

}


// ACCESSOR / QUERY
sample audioclip_peakamp(const audioclip *c);


// audioclip_join
// modifica a, distrugge b
void audioclip_join(audioclip *a, audioclip *b)
{
    // dopo avere concatenato,
    // chiamerà il distruttore di b
}





int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    audioclip *sineTone = audioclip_new(44100, 1, 441000); // chiamo il costruttore
    
    // ... faccio cose con sineTone...
     // ma non la libero!

    sineTone = audioclip_new(44100, 1, 220500);
    
    // il vecchio oggetto sineTone continua a esistere ma è inaccessibile
    
    
    
    audioclip_gain(audioclip_new(44100, 1, 441000), 0.5);
    
    
    
    
    // free(sineTone); // NO!
    audioclip_free(sineTone); // Sì!

    return 0;
}
