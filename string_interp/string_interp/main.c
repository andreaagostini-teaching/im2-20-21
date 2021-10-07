//
//  main.c
//  string_interp
//
//  Created by andreaagostini on 07/10/2021.
//  Copyright © 2021 Andrea Agostini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char* interp(const char* a, const char* b, int n);
char* interp2(const char* a, const char* b, int n);

int main(int argc, const char * argv[]) {
    
    char a[] = "abcde";
    char b[] = "qwert";
    
    char* c = interp(a, b, 5);
    printf("%s\n", c);
    free(c);
    return 0;
}

char* interp(const char* a, const char* b, int n)
{
    char* r = malloc(n*2+1);
    
    for (int i = 0; i < n; i++) {
        r[i*2] = a[i];
        r[i*2+1] = b[i];
    }
    
    r[n*2] = 0;
    return r;
}

char* interp2(const char* a, const char* b, int size)
{
    char* r = malloc(size+1);
    int i = 0;
    char *rp = r;
    
    // (*rp)++; // questo trasformerebbe 'a' in 'b'
    
    while (*a != 0 && *b != 0 && i < size) {
        *(rp++) = *(a++); // a++: post incremento
        *(rp++) = *(b++);
//      *(++rp) = *(++a); // ++a: pre incremento
        i++;
    }
    
    *rp = 0;
    r = realloc(r, i);
    // perché a questo punto

    return r;
}









