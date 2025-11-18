#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "dash.h"

int main(void){
    printf("Time log application begin\n");
    timelog *output;
    output = (timelog*)malloc(sizeof(timelog));
    DASH_TIMELOG_flt(output);
    auto duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    std::cout << "First timestamp: " << duration_since_epoch_ns.count() << std::endl;
    std::cout << "Thread: " << output->threadID << std::endl;
    DASH_TIMELOG_flt(output);
    duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    std::cout << "Second timestamp: " << duration_since_epoch_ns.count() << std::endl;
    std::cout << "Thread: " << output->threadID << std::endl;
    DASH_TIMELOG_flt(output);
    duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    std::cout << "Third timestamp: " << duration_since_epoch_ns.count() << std::endl;
    std::cout << "Thread: " << output->threadID << std::endl;
    DASH_TIMELOG_flt(output);
    duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    std::cout << "Fourth timestamp: " << duration_since_epoch_ns.count() << std::endl;
    std::cout << "Thread: " << output->threadID << std::endl;

    free(output);
}