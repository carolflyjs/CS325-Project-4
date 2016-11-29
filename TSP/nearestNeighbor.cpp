#include "nearestNeighbor.h"
#include <limits>


nearestNeighbor::nearestNeighbor(std::vector<double> distMatrix, int numCities)
{
    this->activeDistMatrix = distMatrix;
    this->totalNumCities = numCities;
    this->activeNumCities = this->totalNumCities;
}

double nearestNeighbor::getNextCity(int current)
{
    double temp = 0;
    double nearest = std::numeric_limits<double>::max();
    int nextCityID;
    for (int j = 0; j < this->totalNumCities; j++) {
        temp = getDist(current, j);
        if (temp != 0) {
            if (temp <= nearest) {
                nearest = temp;
                nextCityID = j;
            }         
        }
    }
    crossoutMatrix(current);
    cityInOrder.push_back(nextCityID);
    distInOrder.push_back(nearest);
    activeNumCities--;

    return nearest;
}

double nearestNeighbor::getDist(int i, int j)
{
    return activeDistMatrix.at(i * totalNumCities + j);
}

void nearestNeighbor::crossoutMatrix(int usedCityID)
{
    for (int i = 0; i < totalNumCities; i++) {
        activeDistMatrix.at(i * totalNumCities + usedCityID) = 0.0;
        activeDistMatrix.at(usedCityID * totalNumCities + i) = 0.0;
    }
}

void nearestNeighbor::getAllCities()
{
    double current;
    cityInOrder.push_back(0);
    for (int i = 1; i < totalNumCities; i++) {
        current = getNextCity(cityInOrder.at(i - 1));
        totalDist += current;
    }

}

nearestNeighbor::~nearestNeighbor()
{
}
