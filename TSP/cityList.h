#ifndef CITYLIST
#define CITYLIST

#include <vector>
#include <fstream>
#include "city.h"
#include <string>
#include <cmath>

class cityList {
private:
    std::vector<city> cityInput;
    std::vector<double> distMatrix;
    std::ifstream inputFile;
    int numCities;

    void readInput();
    void updateMatrix();
    double calBtwCities(int city1, int city2);

public:
    cityList(std::string fileName);
    std::vector<double> getDistMatrix();
    int getNumCities();
    int convert(int city1, int city2);


};

#endif