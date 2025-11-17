#include "dash.h"
#include <cstdio>
#include <cstdlib>

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(CPU_ONLY)
extern void enqueue_kernel(const char* kernel_name, const char* precision_name, unsigned int n_vargs, ...);
#endif

void DASH_TIMELOG_cpu(const char* accel_name, const char* filename){

}

#if defined(__cplusplus)
} // Close 'extern "C"'
#endif