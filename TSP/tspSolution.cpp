#include "tspSolution.h"




tspSolution::tspSolution(std::vector<int>* cityInOrder, double totalDist)
{
    this->cityInOrder = cityInOrder;
    this->totalDist = totalDist;
}

void tspSolution::printSolution(std::string fileName)
{
    std::ofstream output;
    output.open(fileName.c_str());
    output << totalDist << "\n";
    for (int i = 0; i < cityInOrder->size(); i++) {
        output << cityInOrder->at(i) << "\n";
    }
}

tspSolution::~tspSolution()
{
}
