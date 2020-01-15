#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
using namespace std;
class Weapon
{
public:
    Weapon(const string,const int);
    void info()const;
    string getName()const;
    int getDamage()const;
private:
    string wname;
    int damage;
};

#endif // WEAPON_H
