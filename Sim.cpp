#include <iostream>
#include "Sim.h"

using namespace std;

Sim::Sim()
{

}

Sim::~Sim()
{
}

void Sim::runSim(string input)
{
    Sort s(input);
    s.bubbleSort();
    s.insertionSort();
    s.quickSort();
    s.mergeSort();
}
