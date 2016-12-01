#include "nearestNeighbor.h"
#include <limits>


nearestNeighbor::nearestNeighbor(cityList* inputCities)
{
    this->activeCities = inputCities;
}

double nearestNeighbor::getDistBtw(city city1, city city2)
{
    return pow(pow(city1.xCoord - city2.xCoord, 2.0) + pow(city1.yCoord - city2.yCoord, 2.0), 0.5);
}

city nearestNeighbor::getNextCity(city current)
{
    double tempDis = 0;
    double nearest = std::numeric_limits<double>::max();
    int nextCityID;
    int nextCityPos;
    city nextCity;
    for (int j = 0; j < this->activeCities->getNumCities(); j++) {
        tempDis = getDistBtw(current, this->activeCities->getCityInput().at(j));
        if (tempDis <= nearest) {
                nearest = tempDis;
                nextCityID = this->activeCities->getCityInput().at(j).cityID;
                nextCityPos = j;
                nextCity = this->activeCities->getCityInput().at(j);
        }
    }

    this->activeCities->removeCity(nextCityPos);
    cityInOrder.push_back(nextCityID);
    distInOrder.push_back(nearest);
    totalDist += nearest;
    return nextCity;
}


void nearestNeighbor::getAllCities()
{
    int initialCityID = 0;
    int totalNumCities = this->activeCities->getNumCities();
    city initial = this->activeCities->getCityInput().at(initialCityID);
    city temp = initial;
    cityInOrder.push_back(initialCityID);
    this->activeCities->removeCity(initialCityID);
    for (int i = 1; i < totalNumCities; i++) {
        temp = getNextCity(temp);
    }
    double lastDist = getDistBtw(initial, temp);
    distInOrder.push_back(lastDist);
    totalDist += lastDist;
    return;
}

nearestNeighbor::~nearestNeighbor()
{
}
