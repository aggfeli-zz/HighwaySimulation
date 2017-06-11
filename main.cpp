/*
 * Pagona Vourou - 1115201300254
 * Ageliki Felimega - 1115201300192
 */

#include <cstdlib>
#include "highway.h"


int main(int argc, char** argv) 
{
    int N, NSegs, K;
    double Percent;
    if (argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4] != NULL)
    {
        N = atoi(argv[1]);         
        NSegs = atoi(argv[2]);
        K = atoi(argv[3]);
        Percent = atof(argv[4]);
    }
    else
    {
        N = 3;         
        NSegs = 4;
        K = 10;
        Percent = 0.5;
    }
    highway h(NSegs, K, Percent);           //Highway constructor
    
    cout << "Just exiting main" << endl;
    return 0;
}

