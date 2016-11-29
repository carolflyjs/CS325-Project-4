#ifndef NEARESTNEIGHBOR
#define NEARESTNEIGHBOR

#include <vector>

class nearestNeighbor
{
private:
    std::vector<double> activeDistMatrix;
    int totalNumCities;
    int activeNumCities;
    std::vector<double> distInOrder;
    std::vector<int> cityInOrder;
    double totalDist = 0;

public:
    nearestNeighbor(std::vector<double> distMatrix, int numCities);
    double getNextCity(int current);
    double getDist(int i, int j);
    void crossoutMatrix(int usedCityID);
    void getAllCities();
    std::vector<double> getDistInOrder () {
        return distInOrder;
    }
    double getTotalDist () {
        return totalDist;
    }
    ~nearestNeighbor();
};

#endif

