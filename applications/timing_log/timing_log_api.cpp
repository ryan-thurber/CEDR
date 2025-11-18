#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "dash.h"

int main(void){
    printf("Time log application begin\n");
    timelog *output;
    std::ofstream outputFile("output/timing_log_output.txt");
    output = (timelog*)malloc(sizeof(timelog));
    DASH_TIMELOG_flt(output);
    auto duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    outputFile << "First timestamp: " << duration_since_epoch_ns.count() << std::endl;
    outputFile << "Thread: " << output->threadID << std::endl;
    DASH_TIMELOG_flt(output);
    duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    outputFile << "Second timestamp: " << duration_since_epoch_ns.count() << std::endl;
    outputFile << "Thread: " << output->threadID << std::endl;
    DASH_TIMELOG_flt(output);
    duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    outputFile << "Third timestamp: " << duration_since_epoch_ns.count() << std::endl;
    outputFile << "Thread: " << output->threadID << std::endl;
    DASH_TIMELOG_flt(output);
    duration_since_epoch_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((*(output->time)).time_since_epoch());
    outputFile << "Fourth timestamp: " << duration_since_epoch_ns.count() << std::endl;
    outputFile << "Thread: " << output->threadID << std::endl;

    outputFile.close();
    free(output);
}