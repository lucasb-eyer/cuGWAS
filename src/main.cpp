#include <iostream>
#include <string>

#include "dep/pgetopt.h"

#include "cugwas.h"

void help(const char* self)
{
    std::cout << "Usage: " << self << " <data_directory>" << std::endl;
    std::cout << std::endl;
    std::cout << "data_directory must contain the following files (all binary, double precision):" << std::endl;
    std::cout << "Phi.in - Contains foobar" << std::endl;
    std::cout << "H.in   - Contains foobar" << std::endl;
    std::cout << "Sig.in - Contains foobar" << std::endl;
    std::cout << "XR.in  - Contains the estimated allele 1 dose for each SNP." << std::endl;
    std::cout << "XL.in  - Contains the additional covariates." << std::endl;
    std::cout << "Y.in   - Contains the phenotype/trait under analysis." << std::endl;
}

void version(const char* self)
{
    std::cout << self << ": version 0.1" << std::endl;
}

int main(int argc, char *argv[])
{
    popterr = 0;
    int c = 0;
    while((c = pgetopt(argc, argv, "hv?")) != -1) {
        switch(c) {
        case 'v':
            version(argv[0]);
            return 0;
        default: // Includes 'h' and '?'
            help(argv[0]);
            return 0;
        }
    }

    // poptind is now pointing to the first non-treated argument, which should be a pathname.

    // No argument left.
    if(poptind >= argc) {
        help(argv[0]);
        return 0;
    }

    std::string datadir = argv[poptind];
    std::cout << "Reading datafiles in " << datadir << std::endl;

    // Maybe most of the following should move to the lib too, resulting in a
    // god-function "cugwas" which "does it all"?

    gwas_leastsquares_t gls;

    gls.n = 10000;  // TODO: Infer from the size of the file for phi.
    gls.m = 100000;
    gls.p = 20;     // TODO: Infer this from the size of the file for X, given m.
    gls.w = 19;
    gls.t = 1;      // TODO: Infer from the size of the file for R or Y, given n.

    alloc_gwas_leastsquares(&gls);
    // TODO: More to come here
    free_gwas_leastsquares(&gls);

    return 0;
}

