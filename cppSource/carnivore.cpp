#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
#include "carnivore.h"

Carnivore::Carnivore(int sizeValue,int growthRateValue,int orgIDValue,int foodPerWeekValue,int movesValue)
        :Animal(sizeValue,growthRateValue,orgIDValue,foodPerWeekValue,movesValue) {
                                                                       carn=true; }

Carnivore::~Carnivore() {carn=false;}                                                                      
                                                                       
                                                                        
