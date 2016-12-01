#include "cityList.h"
#include "nearestNeighbor.h"
#include "tspSolution.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::string file = "tsp_example_1.txt";
    cityList tsp(file);

    nearestNeighbor tsp_calt(&tsp);
    tsp_calt.getAllCities();
    std::cout << tsp_calt.getTotalDist() << "\n";
    for (int i = 0; i < tsp_calt.getCityInOrder()->size(); i++) {
        std::cout << tsp_calt.getCityInOrder()->at(i) << "\n";
    }
    std::vector<int> *solution = tsp_calt.getCityInOrder();
    tspSolution tsp_solution(solution, tsp_calt.getTotalDist());
    tsp_solution.printSolution("tsp_example_1.txt.tour");
    return 0;
}