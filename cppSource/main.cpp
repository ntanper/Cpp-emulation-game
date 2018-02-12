#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "plant.h"
#include "carnivore.h"
#include "herbivore.h"
#include <iomanip>
#include <conio.h>
using std::setw;
using std::setfill;

void Prosomiosi();
void Plirof_plithismou();
void Plirof_organismou();
void printList();
void Dhmiourgia_organ();

bool notStarted=true;
int days=0;
int Map[10][10];
Plant A[100];
Carnivore B[100];
Herbivore C[100];
int herbMovesLeft[100];
int carnMovesLeft[100];
int count=0,plantCount=0,herbCount=0,carnCount=0,orgCount=0;
int carnDeath=0,herbDeath=0,plantDeath=0;

int main() {
    int choice,i,j;
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            Map[i][j]=0; }}
    do {
    cout<<"Dialekste leitourgia:"<<endl<<"1.Leitourgia prosomoiosis"<<endl<<"2.Dhmiourgia kainourgiou organismou"<<endl;
    cout<<"3.Plirofories ana plithismo organismwn"<<endl<<"4.Plirofories ana organismo"<<endl<<"5.Exit"<<endl;
    cin>>choice;
    switch (choice) {
    case 1:
         Prosomiosi();
         break;
    case 2:
         if (orgCount<100) {
         printList();
         Dhmiourgia_organ(); 
          }

         else { cout<<"Den xwraei allos organismos."<<endl; }
         break;
    case 3:
         Plirof_plithismou();
         break;
    case 4:
         Plirof_organismou();
         break;
    case 5:
         break;
    default:
            cout<<"Lathos epilogi"<<endl;
            break;
    }
    }while (choice!=5);
    

    
    system("PAUSE");
    return 0;
}

void Prosomiosi() {
     int choice,choice2,week=0,c,p,s,i,j,k,l,f;
     
     char answer='n';
     cout<<"1.Start/Resume  2.Restart"<<endl;
     cin>>choice;
     if (choice==1) {
     do {
     
     if (notStarted==true) { //An twra ksekina i prosomoiosi arxikopoihse
     notStarted=false;
     for (c=0;c<herbCount;c++) {
         C[c].setEatenThisWeek(0); }
     for (c=0;c<carnCount;c++) {
         B[c].setEatenThisWeek(0); }
     for (c=0;c<carnCount;c++) { carnMovesLeft[c]=B[c].getMoves();}
     for (c=0;c<herbCount;c++) { herbMovesLeft[c]=C[c].getMoves();}
     }
       
     while (days<7) { //To loop epanalambanetai gia kathe mera tis vdomadas
     
     cout<<"Week="<<week<<" Day="<<days<<endl;
     for (l=0;l<5;l++) { //i epanalipsi auti ginetai gia kathe kinisi twn organismwn
     if (kbhit()) {//Stamata thn roi tou programmatos an patithei koumpi
                  
                  cout<<"Pause? (y/n)"<<endl;
                  cin>>answer;
                  if (answer=='y') break;}
     for (c=0;c<carnCount;c++) { //Gia kathe ena apo ta carnivores
     if (carnMovesLeft[c]>0) {
     carnMovesLeft[c]--;
     
     srand(time(0));
     s=rand()%3-1;//Ta s kai p orizoun tin metatopisi ston aksona x kai y antistoixa.
     p=rand()%3-1;//Pernoun tuxaies times apo to sunolo (-1,0,1)
     Sleep(100);//To sleep xrisimopoieitai gia na dinoun diaforetikes times oi rand, logw tou srand(time(0))
     while ((B[c].getPosX()+s>9)||(B[c].getPosX()+s<0)||(B[c].getPosY()+p>9)||(B[c].getPosY()+p<0)||((s==0)&&(p==0))||(Map[B[c].getPosX()+s][B[c].getPosY()+p]!=0)){
           s=rand()%3-1;
           p=rand()%3-1;
           Sleep(100); }
     Map[B[c].getPosX()][B[c].getPosY()]=0;
     B[c].setPosition(B[c].getPosX()+s,B[c].getPosY()+p);
     Map[B[c].getPosX()][B[c].getPosY()]=B[c].getOrgID();}
     s=B[c].getPosX();
     p=B[c].getPosY();
     for (i=(s-1);i<=(s+1);i++) {
         for (j=(p-1);j<=(p+1);j++) {
             if (Map[i][j]!=0) {
                 for (k=0;k<carnCount;k++) {
                     if (Map[i][j]==B[k].getOrgID()){
                     if (B[c].getSize()>=2*B[k].getSize()) {
                        
                        
                        B[c].setEatenThisWeek(B[c].getEatenThisWeek()+B[k].getGrowthRate());
                        Map[B[k].getPosX()][B[k].getPosY()]=0;
                        B[k].~Animal();
                        carnCount--;
                        B[k]=B[carnCount];
                        B[carnCount].~Animal();
                        carnDeath++;
                        orgCount--;
                                              }}}}}}
     }
     
     for (c=0;c<herbCount;c++) { //gia kathe ena apo ta herbivores
     if (herbMovesLeft[c]>0) {
     
     herbMovesLeft[c]--;
     srand(time(0));
     s=rand()%3-1; 
     
     p=rand()%3-1; 
     
     Sleep(100);
     while ((C[c].getPosX()+s>9)||(C[c].getPosX()+s<0)||(C[c].getPosY()+p>9)||(C[c].getPosY()+p<0)||((s==0)&&(p==0))||(Map[(C[c].getPosX()+s)][(C[c].getPosY()+p)]!=0)) {
     s=rand()%3-1;
     p=rand()%3-1;
     
     Sleep(100); 
     }
     Map[C[c].getPosX()][C[c].getPosY()]=0;
     C[c].setPosition(C[c].getPosX()+s,C[c].getPosY()+p);
     Map[C[c].getPosX()][C[c].getPosY()]=C[c].getOrgID();
  
     s=C[c].getPosX();
     p=C[c].getPosY();
       
     for (i=(s-1);i<=(s+1);i++) {
         for (j=(p-1);j<=(p+1);j++) {
             if (Map[i][j]!=0) {
             for (k=0;k<plantCount;k++) {
                 if (Map[i][j]==A[k].getOrgID()) {
                 
                 C[c].setEatenThisWeek((C[c].getEatenThisWeek()+10));
                 A[k].setSize(A[k].getSize()-A[k].getGrowthRate());
                 if (A[k].getSize()<=0) {
                                        Map[A[k].getPosX()][A[k].getPosY()]=0;
                                        A[k].~Plant();
                                        plantCount--;
                                        A[k]=A[plantCount];
                                        A[plantCount].~Plant();
                                        plantDeath++;
                                        orgCount--;}}}
             for (k=0;k<carnCount;k++) {
                 if (Map[i][j]==B[k].getOrgID()){
                         if (B[k].getSize()>=(2*C[c].getSize())) {
                         
                         
                         B[k].setEatenThisWeek(B[k].getEatenThisWeek()+C[c].getGrowthRate());
                         Map[C[c].getPosX()][C[c].getPosY()]=0;
                         C[c].~Herbivore();
                                                
                                                herbCount--;
                                                C[c]=C[herbCount];
                                                C[herbCount].~Herbivore();
                                                herbDeath++;
                                                orgCount--;}}}}}}
                                                
}
     } 
     } if (answer=='y') break;
days++; //teleiose mia mera ara arxikopoihse pali tis kinhseis
 for (c=0;c<carnCount;c++) { carnMovesLeft[c]=B[c].getMoves();}
 for (c=0;c<herbCount;c++) { herbMovesLeft[c]=C[c].getMoves();}} if (answer=='y')break; 

week++; days=0;  cout<<"Perase 1 evdomada"<<endl; Sleep(1000);
// perase mia evdomada opote upologise tis ilikies kai ta nea megethi tvn zwwn kai kane ta eatenThisWeek 0
for (c=0;c<plantCount;c++) {
    A[c].setSize(A[c].getSize()+A[c].getGrowthRate());
    A[c].setAge(A[c].getAge()+1); }
for (c=0;c<herbCount;c++) {
    C[c].setAge(C[c].getAge()+1);
    if (C[c].getEatenThisWeek()>=C[c].getFoodPerWeek()) {
        C[c].setSize(C[c].getSize()+C[c].getGrowthRate()); }
    else {
         C[c].setSize(C[c].getSize()-C[c].getGrowthRate());
         if (C[c].getSize()<=0) {
                                Map[C[c].getPosX()][C[c].getPosY()]=0;
                                C[c].~Herbivore();
                                herbCount--;
                                C[c]=C[herbCount];
                                C[herbCount].~Herbivore(); 
                                herbDeath++;
                                orgCount--;} } }
for (c=0;c<carnCount;c++) {
    B[c].setAge(B[c].getAge()+1);
    if (B[c].getEatenThisWeek()>=B[c].getFoodPerWeek()) {
        B[c].setSize(B[c].getSize()+B[c].getGrowthRate()); }
    else {
         B[c].setSize(B[c].getSize()-B[c].getGrowthRate());
         if (B[c].getSize()<=0) {
                                Map[B[c].getPosX()][B[c].getPosY()]=0;
                                B[c].~Carnivore();
                                carnCount--;
                                B[c]=B[carnCount];
                                B[carnCount].~Carnivore(); 
                                carnDeath++;
                                orgCount--;} } }
for (c=0;c<herbCount;c++) {
         C[c].setEatenThisWeek(0); }
     for (c=0;c<carnCount;c++) {
         B[c].setEatenThisWeek(0); }                                
                            
}while (1); }
 else { //periptosi restart
//diegrapse olous tous organismous kai mhdenise olous tous metrites     
     notStarted=true;
     count=0;
     
     orgCount=0;
     for (c=0;c<plantCount;c++) {
         A[c].~Plant(); }
     plantDeath=0;
     plantCount=0;
     for (c=0;c<herbCount;c++) {
         C[c].~Herbivore(); }
     herbCount=0;
     herbDeath=0;
     for (c=0;c<carnCount;c++) {
         B[c].~Carnivore(); }
     carnCount=0; 
     carnDeath=0;
     for (i=0;i<10;i++) { //mhdenizoume oles tis times tou xarti
        for (j=0;j<10;j++) {
            Map[i][j]=0; }}} 
         
}




void Plirof_organismou() {
     int i,a,found;
     found=0;
     cout<<"Yparxoun oi ekshs organismoi auti ti stgmh sto oikosysthma:"<<endl;
     cout<<"Plants:";
     for (i=0;i<plantCount;i++) {
         if (A[i].getOrgID()!=0)
         cout<<" "<<A[i].getOrgID(); }
     cout<<endl<<"Herbivores:";
     for (i=0;i<herbCount;i++) {
         if (C[i].getOrgID()!=0)
         cout<<" "<<C[i].getOrgID(); }   
     cout<<endl<<"Carnivores:";
     for (i=0;i<carnCount;i++) {
         if (B[i].getOrgID()!=0)
         cout<<" "<<B[i].getOrgID(); }
     cout<<endl;
     cout<<"Dwste to orgID tou organismou pou thelete"<<endl;
     cin>>a;
     for (i=0;i<plantCount;i++) {
         if (A[i].getOrgID()==a) {
            found=1; 
            cout<<"Age: "<<A[i].getAge()<<endl;
            cout<<"Size: "<<A[i].getSize()<<endl;
            cout<<"Growth Rate: "<<A[i].getGrowthRate()<<endl;
            cout<<"Food Per Week: "<<"N/A"<<endl;
            cout<<"Eaten This Week: "<<"N/A"<<endl;
            cout<<"Thesi ston xarti: "<<A[i].getPosX()<<" "<<A[i].getPosY()<<endl;
            break;}}
     if (found==0) {
     for (i=0;i<herbCount;i++) {
         if (C[i].getOrgID()==a) {
            found=1; 
            cout<<"Age: "<<C[i].getAge()<<endl;
            cout<<"Size: "<<C[i].getSize()<<endl;
            cout<<"Growth Rate: "<<C[i].getGrowthRate()<<endl;
            cout<<"Food Per Week: "<<C[i].getFoodPerWeek()<<endl;
            cout<<"Eaten This Week: "<<C[i].getEatenThisWeek()<<endl;
            cout<<"Thesi ston xarti: "<<C[i].getPosX()<<" "<<C[i].getPosY()<<endl;
            break;}}} 
     if (found==0) {
     for (i=0;i<carnCount;i++) {
         if (B[i].getOrgID()==a) {
            found=1; 
            cout<<"Age: "<<B[i].getAge()<<endl;
            cout<<"Size: "<<B[i].getSize()<<endl;
            cout<<"Growth Rate: "<<B[i].getGrowthRate()<<endl;
            cout<<"Food Per Week: "<<B[i].getFoodPerWeek()<<endl;
            cout<<"Eaten This Week: "<<B[i].getEatenThisWeek()<<endl;
            cout<<"Thesi ston xarti: "<<B[i].getPosX()<<" "<<B[i].getPosY()<<endl;
            break;}}}            
                 }

void printList() { //Typonei tin lista me tous diathesimous gia dhmiourgia organismous.
     cout<<"Dialekste ton organismo pou thelete na dhiourghsete:"<<endl;
     cout<<"  "<<"Onoma"<<setw(13)<<"size"<<setw(8)<<"growth"<<setw(7)<<"moves"<<setw(6)<<"food"<<setw(7)<<"typos"<<endl;
     cout<<"1."<<"Tsouknida"<<setw(7)<<"30"<<setw(5)<<"9"<<setw(8)<<"-"<<setw(7)<<"-"<<setw(10)<<"plant"<<endl;
     cout<<"2."<<"Thamnos"<<setw(9)<<"50"<<setw(6)<<"15"<<setw(7)<<"-"<<setw(7)<<"-"<<setw(10)<<"plant"<<endl;
     cout<<"3."<<"Grasidi"<<setw(9)<<"15"<<setw(5)<<"4"<<setw(8)<<"-"<<setw(7)<<"-"<<setw(10)<<"plant"<<endl;
     cout<<"4."<<"Arkouda"<<setw(10)<<"140"<<setw(5)<<"40"<<setw(7)<<"5"<<setw(8)<<"65"<<setw(8)<<"carn"<<endl;
     cout<<"5."<<"Lukos"<<setw(12)<<"120"<<setw(5)<<"30"<<setw(7)<<"7"<<setw(8)<<"53"<<setw(8)<<"carn"<<endl;
     cout<<"6."<<"Alepou"<<setw(10)<<"60"<<setw(6)<<"20"<<setw(8)<<"10"<<setw(7)<<"26"<<setw(8)<<"carn"<<endl;
     cout<<"7."<<"Nyfitsa"<<setw(9)<<"30"<<setw(6)<<"7"<<setw(7)<<"7"<<setw(8)<<"30"<<setw(8)<<"herb"<<endl;
     cout<<"8."<<"Lagos"<<setw(11)<<"25"<<setw(5)<<"5"<<setw(9)<<"10"<<setw(7)<<"20"<<setw(8)<<"herb"<<endl;
     cout<<"9."<<"Agriokatsiko"<<setw(4)<<"60"<<setw(6)<<"15"<<setw(7)<<"5"<<setw(8)<<"40"<<setw(8)<<"herb"<<endl;
     cout<<"10.Epistrofi"<<endl;
}


void Dhmiourgia_organ() {//Analoga me tin epilogi tou xristi apo tin lista kalei ton katallhlo constructor
     int choice,choice2,i,j;
     
     cout<<"Dwste to antisoixo arithmo gia epilogi"<<endl;
         cin>>choice2;
     if (choice2>=1 && choice2<=9) //Vres thesi mono se periptwsi pou epilextike organismos
     {cout<<"1.Dwste thesi "<<"2.Tyxaia thesi"<<endl; 
         cin>>choice;
     if (choice==1) {
         do {           
                    cin>>i; 
                    cin>>j;
                    if (Map[i][j]!=0) { cout<<"Thesi katillimeni.Dwste nea thesi."<<endl; } 
                   }while (Map[i][j]!=0);
                   }
     else {    
         srand(time(0));//H thesi tou organismou ston xarti epilegetai tuxaia me tis rand
         i=rand()%10;
         j=rand()%10;
         while (Map[i][j]!=0) {//Elegxos gia to an i tixaia thesi pou epilextike einai katilimmeni
              i=rand()%10;     //An einai ksanakane tin diadikasia mexri na vreis keni
              j=rand()%10; } } }
          
         switch (choice2) { //Analoga me tin epilogi kaleitai o katallhlos constructor
            case 1:
                 A[plantCount]=Plant::Plant(20,6,count+1);
                 A[plantCount].Organism::setPosition(i,j);
                 Map[i][j]=A[plantCount].Organism::getOrgID();
                 plantCount++;
                 count++;
                 orgCount++;
                 break; 
            case 2:
                 A[plantCount]=Plant::Plant(25,5,count+1);
                 A[plantCount].Organism::setPosition(i,j);
                 Map[i][j]=A[plantCount].Organism::getOrgID();
                 plantCount++;
                 count++;
                 orgCount++;
                 break;
            case 3:
                 A[plantCount]=Plant::Plant(17,8,count+1);
                 A[plantCount].Organism::setPosition(i,j);
                 Map[i][j]=A[plantCount].Organism::getOrgID();
                 plantCount++;
                 count++;
                 orgCount++;
                 break;
            case 4:
                 B[carnCount]=Carnivore::Carnivore(140,60,count+1,39,3);
                 B[carnCount].Organism::setPosition(i,j);
                 Map[i][j]=B[carnCount].Organism::getOrgID();
                 carnCount++;
                 count++;
                 orgCount++;
                 break;
            case 5:
                 B[carnCount]=Carnivore::Carnivore(120,40,count+1,34,4);
                 B[carnCount].Organism::setPosition(i,j);
                 Map[i][j]=B[carnCount].Organism::getOrgID();
                 carnCount++;
                 count++;
                 orgCount++;
                 break;                 
            case 6:
                 B[carnCount]=Carnivore::Carnivore(80,25,count+1,29,5);
                 B[carnCount].Organism::setPosition(i,j);
                 Map[i][j]=B[carnCount].Organism::getOrgID();
                 carnCount++;
                 count++;
                 orgCount++;
                 break;     
            case 7:
                 C[herbCount]=Herbivore::Herbivore(40,20,count+1,20,4);
                 C[herbCount].Organism::setPosition(i,j);
                 Map[i][j]=C[herbCount].Organism::getOrgID();
                 herbCount++;
                 count++;
                 orgCount++;
                 break;
            case 8:
                 C[herbCount]=Herbivore::Herbivore(30,15,count+1,20,5);
                 C[herbCount].Organism::setPosition(i,j);
                 Map[i][j]=C[herbCount].Organism::getOrgID();
                 herbCount++;
                 count++;
                 orgCount++;
                 break;
            case 9:
                 C[herbCount]=Herbivore::Herbivore(60,30,count+1,30,3);
                 C[herbCount].Organism::setPosition(i,j);
                 Map[i][j]=C[herbCount].Organism::getOrgID();
                 herbCount++;
                 count++;
                 orgCount++;
                 break;   
            case 10:
                 break;
            default:
                    cout<<"Lathos epilogi"<<endl;
                    break; }     
                 }
                 
void Plirof_plithismou() {
     int choice,plithos,c;
     float sizeAvg=0,eatenThisWeekAvg=0,deathRate=0,ageAvg=0;
     cout<<"Dialekste katigoria organismwn:"<<endl<<"1.Herbivores"<<endl<<"2.Carnivores"<<endl<<"3.Plants"<<endl;
     cin>>choice;
     switch (choice) {
            case 1:
                 plithos=herbCount;
                 for (c=0;c<herbCount;c++) {
                     sizeAvg+=C[c].getSize();
                     eatenThisWeekAvg+=C[c].getEatenThisWeek();
                     ageAvg+=C[c].getAge(); }
                 if ((plantDeath+carnDeath+herbDeath)!=0)
                 deathRate=(float)(herbDeath)/(herbDeath+plantDeath+carnDeath)*100;
                 if (herbCount!=0) {
                 sizeAvg/=herbCount;
                 eatenThisWeekAvg/=herbCount;
                 ageAvg/=herbCount; }
                 break;
            case 2:
                 plithos=carnCount;
                 for (c=0;c<carnCount;c++) {
                     sizeAvg+=B[c].getSize();
                     eatenThisWeekAvg+=B[c].getEatenThisWeek();
                     ageAvg+=B[c].getAge(); }
                 if ((plantDeath+carnDeath+herbDeath)!=0)
                 deathRate=(float)(carnDeath)/(herbDeath+carnDeath+plantDeath)*100;
                 if (carnCount!=0) {
                 sizeAvg/=carnCount;
                 eatenThisWeekAvg/=carnCount;
                 ageAvg/=carnCount; }
                 break;
            case 3:
                 plithos=plantCount;
                 for (c=0;c<plantCount;c++) {
                     sizeAvg+=A[c].getSize();
                     
                     ageAvg+=A[c].getAge(); }
                 if ((plantDeath+carnDeath+herbDeath)!=0)
                 deathRate=(float)(plantDeath)/(plantDeath+carnDeath+herbDeath)*100;
                 if (plantCount!=0) {
                 sizeAvg/=plantCount;
                 
                 ageAvg/=plantCount; }
                 break;
                 default:
                         cout<<"lathos epilogi"<<endl;
                         break;
                         }
cout<<"Mesos oros megethous: "<<sizeAvg<<endl<<"Plithos: "<<plithos<<endl;
cout<<"Mesi katanalosi trofis tin teleutaia evdomada: "<<eatenThisWeekAvg<<endl;
cout<<"Pososto thanatwn: "<<deathRate<<endl<<"Mesos oros ilikias: "<<ageAvg<<endl;
}

