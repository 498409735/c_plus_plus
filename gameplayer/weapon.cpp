#include "weapon.h"

Weapon::Weapon(const string wname_tmp,const int damage_tmp):
    wname(wname_tmp),damage(damage_tmp){
    cout<<"´´½¨ÎäÆ÷"<<this->wname<<endl;
}
void Weapon::info()const{
    cout<<"ÎäÆ÷Ãû³Æ:"<<this->wname<<"ÉËº¦Öµ:"<<this->damage<<endl;
}
string Weapon::getName() const{
    return wname;
}
int Weapon::getDamage() const{
    return damage;
}
