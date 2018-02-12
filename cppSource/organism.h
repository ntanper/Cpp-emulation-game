#ifndef ORGANISM_H
#define ORGANISM_H
class Organism {
      public:
             Organism(int=0 , int=0,int=0);
             ~Organism();
             int getOrgID();
             void setPosition (int , int);
             int getPosX();
             int getPosY();
             int getSize();
             void setAge(int);
             int getAge();
             int getGrowthRate();
             void setSize(int); 
      private:
              int age;
              int size;
              int growthRate;
              int orgID;
              int posX;
              int posY;
              
              };
#endif


