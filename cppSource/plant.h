#ifndef PLANT_H
#define PLANT_H
#include "organism.h"
class Plant:public Organism {
      public:
             Plant(int=0,int=0,int=0);
             ~Plant();
      private:
              bool isPlant;
      };
#endif
