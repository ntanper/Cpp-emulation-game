#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
#include "plant.h"

Plant::Plant(int sizeValue,int growthRateValue,int orgIDValue)
           : Organism(sizeValue,growthRateValue,orgIDValue) {
                 isPlant = true; }
Plant::~Plant() { isPlant=false; }
