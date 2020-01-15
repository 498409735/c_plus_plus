#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <unistd.h>
#include <time.h>
#include "weapon.h"

#define WEAPON_NUM 3
class Player
{
public:
    Player(const string name_tmp,const int blood_tmp);
    void info()const;
    void attack(Player &other);
    void initWeapon();
    int getBlood()const;
    string getName()const;
    Weapon* getWeapon()const;
    void dropBood(const int blood);
private:
    string name;
    int blood;
    Weapon* m_weapon[WEAPON_NUM];
};

#endif // PLAYER_H
