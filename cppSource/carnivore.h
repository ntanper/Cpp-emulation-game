#ifndef CARNIVORE_H
#define CARNIVORE_H
#include "animal.h"

class Carnivore : public Animal {
      public:
             Carnivore(int=0,int=0,int=0,int=0,int=0);
             ~Carnivore();
      private:
              bool carn;
};
#endif
