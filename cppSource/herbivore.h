#ifndef HERBIVORE_H
#define HERBIVORE_H
#include "animal.h"
class Herbivore : public Animal {
      public:
             Herbivore(int=0,int=0,int=0,int=0,int=0);
             ~Herbivore();
             bool getHerb(); 
      private:
              bool herb;
};
#endif
