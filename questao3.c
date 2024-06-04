#include <stdlib.h>
#include <stdio.h>


int main (void) {

    int valor = 7, *p, *q;
    p = &valor;
    q = p;
    printf("%u\n", p+1);
    printf("%u\n", *p);
    printf("%u\n", (*p+1));
    printf("%u\n", *q+1);
    printf("%u\n", (*q)%(*p));


    return EXIT_SUCCESS;
}