#include "dash.h"
#include <cstdio>
#include <cstdlib>

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(CPU_ONLY)
extern void enqueue_kernel(const char* kernel_name, const char* precision_name, unsigned int n_vargs, ...);
#endif

void DASH_TIMELOG_cpu(timelog* tlog){
    *(tlog->time) = std::chrono::system_clock::now();
    *(tlog->threadID) = std::this_thread::get_id();
}

#if defined(__cplusplus)
} // Close 'extern "C"'
#endif