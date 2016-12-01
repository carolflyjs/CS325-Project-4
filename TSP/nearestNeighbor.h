#ifndef NEARESTNEIGHBOR
#define NEARESTNEIGHBOR

#include <vector>
#include "cityList.h"
#include <cmath>

class nearestNeighbor
{
private:
    cityList* activeCities;
    std::vector<double> distInOrder;
    std::vector<int> cityInOrder;
    double totalDist = 0;

public:
    nearestNeighbor(cityList* inputCities);
    double getDistBtw(city city1, city city2);
    city getNextCity(city current);
    void getAllCities();
    std::vector<double> getDistInOrder () {
        return distInOrder;
    }
    std::vector<int>* getCityInOrder() {
        return &cityInOrder;
    }
    double getTotalDist () {
        return totalDist;
    }
    ~nearestNeighbor();
};

#endif

