#pragma once
#define MAX_NO_OF_SAMPLES 20

#ifndef NAMESPACE_HEADERFILENAMEGRAPH_H
#define NAMESPACE_HEADERFILENAMEGRAPH_H

namespace sict
{

    void printGraph(int samples[], int noOfSamples);
    void printBar(int value, int max);
    void getSamples(int samples[], int noOfSamples);
    int findMax(int samples[], int noOfSamples);

}

#endif