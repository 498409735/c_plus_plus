#include <iostream>

#include "player.h"

//#include <synchapi.h>

//using namespace std;
int main()
{
    Player Thor("����",1000);
    Thor.initWeapon();
    Thor.info();
    Player Thanos("���",10000);
    Thanos.initWeapon();
    Thanos.info();
    while (1) {
        Thor.attack(Thanos);
        if(Thanos.getBlood()==0){
            cout<<"�������"<<endl;
            return  0;
        }
        sleep(1);
        Thanos.attack(Thor);
        if(Thor.getBlood()==0){
            cout<<"��������"<<endl;
            return  0;
        }
        sleep(1);
    }
    return 0;
}
