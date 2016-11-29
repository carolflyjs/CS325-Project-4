#include "cityList.h"
#include <iostream>
cityList::cityList(std::string fileName) {
    // open input
    inputFile.open(fileName.c_str());
    if (inputFile.is_open()) {
        numCities = 0;

        // read input into cityInput
        readInput();

        // update distance matrix
        updateMatrix();

        //close input
        inputFile.close();
    }
    else {
        std::cout << "Fail to open file\n";
    }
}

std::vector<double> cityList::getDistMatrix()
{
    return distMatrix;
}

int cityList::getNumCities()
{
    return numCities;
}

void cityList::readInput()
{
    city temp;
    std::string str;
    std::string::size_type sz;
    while (!inputFile.eof()) {      
        inputFile >> str;
        temp.cityID = std::stoi(str, &sz);

        inputFile >> str;
        temp.xCoord = std::stoi(str, &sz);

        inputFile >> str;
        temp.yCoord = std:: stoi(str, &sz);

        if (temp.cityID != temp.xCoord || temp.xCoord != temp.yCoord || temp.cityID != temp.yCoord) {
            cityInput.push_back(temp);
            numCities++;
        }
    }


}

void cityList::updateMatrix()
{
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            if (i == j) {
                // city X to city X has 0 distance
                distMatrix.push_back(0);
            }
            else if (i < j) {
                // calculate city X to city Y if X < Y
                distMatrix.push_back(calBtwCities(i, j));
            }
            else {
                // copy value from city Y to city X if X > Y
                distMatrix.push_back(distMatrix.at(convert(j, i)));
            }
        }
    }
}

int cityList::convert(int city1, int city2)
{
    int converted = city1 * numCities + city2;
    return converted;
}

double cityList::calBtwCities(int city1, int city2)
{
    double distance;
    int xDiff = cityInput.at(city1).xCoord - cityInput.at(city2).xCoord;
    int yDiff = cityInput.at(city1).yCoord - cityInput.at(city2).yCoord;
    distance = pow(pow(xDiff, 2.0) + pow(yDiff, 2.0), 0.5);
    return distance;
}
