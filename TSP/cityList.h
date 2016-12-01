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
    std::vector<double> cityList::getDistMatrix() { return this->distMatrix; }
    void removeCity(int cityToRemove);
    int cityList::getNumCities() { return this->cityInput.size(); }
    std::vector<city> getCityInput() { return this->cityInput; }
    int convert(int city1, int city2);
    void setCityInput(std::vector<city> cityInput) { this->cityInput = cityInput; }
    void setNumCitiess(int numCities) { this->numCities = numCities; }
};

#endif