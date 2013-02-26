#ifndef CUGWAS_FGLS_CHOL_CUDA_H
#define CUGWAS_FGLS_CHOL_CUDA_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    /// SIZES

    // Number of different phenotype vectors Y.
    size_t t;

    // Number of individuals in the study, i.e. size of phenotype vector y,
    // and relationship/kinship matrix phi, and thus M/V.
    size_t n;

    // Number of SNPs in the study, i.e. the number of design-matrices X.
    size_t m;

    // Number of regression parameters, i.e. size of result vector r per SNP.
    size_t p;

    // Number of fixed parts in the design matrix X, i.e. width of the
    // part called X/L: X_x or X_l.
    size_t w;

    /// DATA

    // h square: heriditabilities of the t traits.
    double *h2;

    // sigma square: variance of the MLE for each of the t traits.
    double *s2;

    // Relationship matrix containing the coefficients of kinship between
    // the individuals. See the "Estimation of genomic kinship matrix" section
    // in the ProbABEL paper for details.
    double *phi;

    // "base" part of the design-matrices X.
    double *xx;

    // The following need to be given as filenames since they'll be streamed using posix AIO.
    // No way around - that's half of what this is about.

    // SNP part of the design-matrices X. (input)
    const char* xg_filename;

    // Vectors of residuals. (input, eq. 9 in the ProbABEL paper.)
    const char* r_filename;

    // "Beta", vector of regression parameters (output, eq. 8 in the ProbABEL paper.)
    const char* b_filename;
} gwas_leastsquares_t;

// Allocates the space necessary for the data held in gls.
// Note that the sizes (esp. t and n) need to be set already.
int alloc_gwas_leastsquares(gwas_leastsquares_t* gls);

// Frees the memory allocated by alloc_gwas_leastsquares.
void free_gwas_leastsquares(gwas_leastsquares_t* gls);

#ifdef __cplusplus
}
#endif

#endif /* CUGWAS_FGLS_CHOL_CUDA_H */

