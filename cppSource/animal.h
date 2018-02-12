#ifndef ANIMAL_H
#define ANIMAL_H
#include "organism.h"
class Animal: public Organism {
      public:
             Animal(int =0,int=0,int=0,int=0,int=0);
             ~Animal();
             int getMoves();
             void setEatenThisWeek(int);
             int getEatenThisWeek();
             int getFoodPerWeek();
      private:
              int foodPerWeek;
              int eatenThisWeek;
              int moves;
};
#endif
