#include <iostream>

#include "player.h"

//#include <synchapi.h>

//using namespace std;
int main()
{
    Player Thor("À×Éñ",1000);
    Thor.initWeapon();
    Thor.info();
    Player Thanos("Ãð°Ô",10000);
    Thanos.initWeapon();
    Thanos.info();
    while (1) {
        Thor.attack(Thanos);
        if(Thanos.getBlood()==0){
            cout<<"Ãð°ÔËÀÍö"<<endl;
            return  0;
        }
        sleep(1);
        Thanos.attack(Thor);
        if(Thor.getBlood()==0){
            cout<<"À×ÉñËÀÍö"<<endl;
            return  0;
        }
        sleep(1);
    }
    return 0;
}
