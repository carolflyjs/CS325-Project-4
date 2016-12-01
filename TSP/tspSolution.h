#ifndef TSPSOLUTION
#define TSPSOLUTION

#include "nearestNeighbor.h"
#include "cityList.h"

class tspSolution
{
private:
    std::vector<int>* cityInOrder;
    double totalDist;

public:
    tspSolution(std::vector<int>* cityInOrder, double totalDist);
    void printSolution(std::string fileName);
    ~tspSolution();
};

#endif

