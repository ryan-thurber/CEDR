#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "dash.h"
#define SEC2NANOSEC 1000000000

int main(void){
    printf("Time log application begin\n");
    timelog *output;
    std::ofstream outputFile("output/timing_log_output.txt");
    std::string dev_type;
    output = (timelog*)malloc(sizeof(timelog));
    int i = 0;
    struct timespec queue_time;
    struct timespec return_time;
    while(i < 30){
        clock_gettime(CLOCK_MONOTONIC_RAW, &queue_time);
        output->queue_time = (queue_time.tv_sec * SEC2NANOSEC + queue_time.tv_nsec);
        DASH_TIMELOG_flt(output);
        clock_gettime(CLOCK_MONOTONIC_RAW, &return_time);
        output->return_time = (return_time.tv_sec * SEC2NANOSEC + return_time.tv_nsec);
        switch(output->accelerator){
            case CPU:
                dev_type = "CPU";
                break;
            case FFT:
                dev_type = "FFT";
                break;
            case ZIP:
                dev_type = "ZIP";
                break;
        }
        outputFile << "queue_time " << output->queue_time << " run_time " << output->run_time << " thread_id " << output->threadID << " dev_type " << dev_type << std::endl;
        i++;
    }

    outputFile.close();
    free(output);
}