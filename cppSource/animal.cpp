#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
#include "animal.h"

Animal::Animal(int sizeValue,int growthRateValue,int orgIDValue,int foodPerWeekValue,int movesValue)
            :Organism(sizeValue,growthRateValue,orgIDValue) {
                                                 foodPerWeek=foodPerWeekValue;
                                                 moves=movesValue;
                                                 eatenThisWeek=0; }
Animal::~Animal() {foodPerWeek=0; eatenThisWeek=0; moves=0;}
int Animal::getMoves() {return moves;}
int Animal::getEatenThisWeek() {return eatenThisWeek;}
void Animal::setEatenThisWeek(int eatenValue) {
     eatenThisWeek=eatenValue; }
int Animal::getFoodPerWeek() { return foodPerWeek;}
