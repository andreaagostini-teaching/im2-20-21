/*
 ** Copyright (C) 1999-2012 Erik de Castro Lopo <erikd@mega-nerd.com>
 **
 ** All rights reserved.
 **
 ** Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **
 **     * Redistributions of source code must retain the above copyright
 **       notice, this list of conditions and the following disclaimer.
 **     * Redistributions in binary form must reproduce the above copyright
 **       notice, this list of conditions and the following disclaimer in
 **       the documentation and/or other materials provided with the
 **       distribution.
 **     * Neither the author nor the names of any contributors may be used
 **       to endorse or promote products derived from this software without
 **       specific prior written permission.
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 ** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 ** PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 ** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 ** OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 ** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 ** OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ** ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <math.h>

#include    <sndfile.h>

#ifndef        M_PI
#define        M_PI        3.14159265358979323846264338
#endif

#define        SAMPLE_RATE            44100
#define        SAMPLE_COUNT        (SAMPLE_RATE * 4)    /* 4 seconds */
#define        AMPLITUDE            (1.0 * 0x7F000000)
#define        LEFT_FREQ            (344.0 / SAMPLE_RATE)
#define        RIGHT_FREQ            (466.0 / SAMPLE_RATE)

int
main (void)
{
    SNDFILE    *file ;
    SF_INFO    sfinfo ;
    int        k ;
    int    *buffer ;
    
    if (! (buffer = malloc (2 * SAMPLE_COUNT * sizeof (int))))
    {    printf ("Malloc failed.\n") ;
        exit (0) ;
    } ;
    
    memset (&sfinfo, 0, sizeof (sfinfo)) ;
    
    sfinfo.samplerate    = SAMPLE_RATE ;
    sfinfo.frames        = SAMPLE_COUNT ;
    sfinfo.channels        = 1 ;
    sfinfo.format        = (SF_FORMAT_WAV | SF_FORMAT_PCM_24) ;
    
    /*
     
     SF_INFO* sfinfo = malloc(sizeof(sfinfo)); // costruttore di sfinfo
     sfinfo->samplerate    = SAMPLE_RATE ;
     sfinfo->frames        = SAMPLE_COUNT ;
     sfinfo->channels        = 2 ;
     sfinfo->format        = (SF_FORMAT_WAV | SF_FORMAT_PCM_24) ;
     file = sf_open ("sine.wav", SFM_WRITE, sfinfo); // costruttore di file
     
     */
    
    // sfinfo.format        = (SF_FORMAT_WAV | SF_FORMAT_PCM_24) ;
    // per esempio SF_FORMAT_WAV potrebbe valere 4 = 00000100(2)
    // per esempio SF_FORMAT_PCM_24 potrebbe valere 16 = 00010000 (2)
    // 00000100(2) | 00010000 (2) = 00010100 (2) = 20
    // è un bit field
    
    //     if (! (file = sf_open ("sine.wav", SFM_WRITE, &sfinfo)))
    
    // scomposta in pezzi
    // file = sf_open ("sine.wav", SFM_WRITE, &sfinfo); // costruttore
    // // ora file può essere valido (non-NULL cioè non 0) o non valido (NULL cioè 0)
    // int a = 1, b, c;
    // c = a + (b = 2); // NON CONFONDERE CON b == 2 !!!!!!
    // ora c vale 3
    // quindi:
    // (file = sf_open ("sine.wav", SFM_WRITE, &sfinfo)) vale 0 se non valido, non-0 se valido
    
    // if ((file == sf_open(blabla)) == NULL) { errore } // equivalente a
    // if (!(file = sf_open ("sine.wav", SFM_WRITE, &sfinfo))) { errore } // se FILE è 0 dai errore
    
    // if (1) { a; } else {b;} // esegue sempre a
    // if (!1) { a; } else {b;} // esegue sempre b
    
    
    if (! (file = sf_open ("/Users/andreaagostini/devel/c/smet20-21/sine.wav", SFM_WRITE, &sfinfo)))
    {    printf ("Error : Not able to open output file.\n") ;
        free (buffer) ;
        return 1 ;
    } ;
    
    if (sfinfo.channels == 1) {
        for (k = 0 ; k < SAMPLE_COUNT ; k++)
            buffer [k] = AMPLITUDE * sin (LEFT_FREQ * 2 * k * M_PI) ;
    }
    
    // esercizi:
    // dente di sega, onda quadra
    // sintesi additiva elementare
    // modulazione di ampiezza, inviluppo di ampiezza, vibrato, modulazione di frequenza
    
    // questo non lo usiamo (per ora)
    else if (sfinfo.channels == 2)
    {    for (k = 0 ; k < SAMPLE_COUNT ; k++)
    {    buffer [2 * k] = AMPLITUDE * sin (LEFT_FREQ * 2 * k * M_PI) ;
        buffer [2 * k + 1] = AMPLITUDE * sin (RIGHT_FREQ * 2 * k * M_PI) ;
    } ;
    }
    else
    {    printf ("makesine can only generate mono or stereo files.\n") ;
        exit (1) ;
    } ;
    
    // questa cosa non succederà mai
    if (sf_write_int (file, buffer, sfinfo.channels * SAMPLE_COUNT) !=
        sfinfo.channels * SAMPLE_COUNT)
        puts (sf_strerror (file)) ;
    
    
    sf_close (file) ; // distruttore del file
    
    // se ho usato il costruttore esplicito di SF_INFO:
    // free(sfinfo);
    free (buffer) ;
    return 0 ;
} /* main */

