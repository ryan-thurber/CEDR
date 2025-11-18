#include "dash.h"
#include <cstdio>
#include <cstdlib>
#include <pthread.h>

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(CPU_ONLY)
extern void enqueue_kernel(const char* kernel_name, const char* precision_name, unsigned int n_vargs, ...);
#endif

void DASH_TIMELOG_flt_cpu(timelog* tlog){
    auto temp = std::chrono::system_clock::now();
    tlog->time = &temp;
    tlog->threadID = (unsigned long)pthread_self();
}

void DASH_TIMELOG_flt_nb(timelog* tlog, cedr_barrier_t* kernel_barrier) {
#if defined(CPU_ONLY) || defined(DISABLE_ZIP_CEDR)
  DASH_TIMELOG_flt_cpu(tlog);
  if (kernel_barrier != nullptr) {
    (*(kernel_barrier->completion_ctr))++;
  }
#else
  enqueue_kernel("DASH_TIMELOG", "flt", 2, tlog, kernel_barrier);
#endif
}

void DASH_TIMELOG_flt(timelog* tlog){
#if defined(CPU_ONLY) || defined(DISABLE_ZIP_CEDR)
  DASH_TIMELOG_flt_cpu(tlog);
#else
  pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  uint32_t completion_ctr = 0;
  cedr_barrier_t barrier = {.cond = &cond, .mutex = &mutex, .completion_ctr = &completion_ctr};
  pthread_mutex_lock(barrier.mutex);

  DASH_TIMELOG_flt_nb(tlog, &barrier);

  while (completion_ctr != 1) {
    pthread_cond_wait(barrier.cond, barrier.mutex);
  }
  pthread_mutex_unlock(barrier.mutex);
#endif
}

#if defined(__cplusplus)
} // Close 'extern "C"'
#endif