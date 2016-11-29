#include "cityList.h"
#include "nearestNeighbor.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::string file = "tsp_example_3.txt";
    cityList tsp_1(file);
    std::vector<double> matrix = tsp_1.getDistMatrix();
    int numCities = tsp_1.getNumCities();
    nearestNeighbor tsp_1_calt(matrix, numCities);
    tsp_1_calt.getAllCities();
    std::cout << tsp_1_calt.getTotalDist();

    return 0;
}