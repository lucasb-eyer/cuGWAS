#ifndef CUGWAS_FGLS_CHOL_CUDA_H
#define CUGWAS_FGLS_CHOL_CUDA_H

#include "gwas_leastsquares.h"

#ifdef __cplusplus
extern "C" {
#endif

int gwas_leastsquares_chol_cuda(gwas_leastsquares_settings_t settings);

#ifdef __cplusplus
}
#endif

#endif /* CUGWAS_FGLS_CHOL_CUDA_H */

