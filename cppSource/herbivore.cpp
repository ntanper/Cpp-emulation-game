#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
#include "herbivore.h"

Herbivore::Herbivore(int sizeValue,int growthRateValue,int orgIDValue,int foodPerWeekValue,int movesValue)
        :Animal(sizeValue,growthRateValue,orgIDValue,foodPerWeekValue,movesValue) {
                                                                       herb=true; }

Herbivore::~Herbivore() {herb=false;}
bool Herbivore::getHerb() {return herb;}
