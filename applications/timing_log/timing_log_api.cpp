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
    int i = 0;
    while(i < 100){
        DASH_TIMELOG_flt(output);
        outputFile << "Time " << output->time << " Thread " << output->threadID << std::endl;
        i++;
    }

    outputFile.close();
    free(output);
}