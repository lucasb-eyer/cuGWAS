#include "gwas_leastsquares.h"

#include <stdlib.h>

int alloc_gwas_leastsquares(gwas_leastsquares_t* gls)
{
    gls->h2 = (double*)malloc(sizeof(double) * gls->t);
    gls->s2 = (double*)malloc(sizeof(double) * gls->t);
    gls->phi = (double*)malloc(sizeof(double) * gls->n * gls->n);
    gls->xx = (double*)malloc(sizeof(double) * gls->n * gls->w);
}

void free_gwas_leastsquares(gwas_leastsquares_t* gls)
{
    free(gls->h2);
    free(gls->s2);
    free(gls->phi);
    free(gls->xx);
}

