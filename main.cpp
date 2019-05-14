#include <iostream>
#include <chrono>
#include "Sim.h"
#include "FileIO.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
    FileIO file("num.txt");
    file.makeRandom();
    Sim sim;
    string input;
    if(argc == 2)
    {
        input = argv[1];
        sim.runSim(input);
    }
    else
    {
        cout << "Invalid Arguements." << endl;
    }
    return 0;
}
