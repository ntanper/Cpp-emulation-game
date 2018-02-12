#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
#include <iomanip>
#include "organism.h"

Organism::Organism(int sizeValue,int growthRateValue,int orgIDValue):size(sizeValue),growthRate(growthRateValue),orgID(orgIDValue) {
                       age=0; }
Organism::~Organism() {size=0; growthRate=0; orgID=0; age=0; posX=0; posY=0;}

int Organism::getOrgID() { return orgID; }

void Organism::setPosition (int posXValue,int posYValue) {
     posX=posXValue;
     posY=posYValue; }

int Organism::getPosX () {return posX; }
int Organism::getPosY() { return posY; }
int Organism::getSize() { return size;}
int Organism::getAge() {return age;}
void Organism::setSize(int sizeValue) {size=sizeValue;}
int Organism::getGrowthRate() {return growthRate;}
void Organism::setAge(int ageValue) {age=ageValue;}
