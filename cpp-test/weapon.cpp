#include "weapon.h"

Weapon::Weapon(const string wname_tmp,const int damage_tmp):
    wname(wname_tmp),damage(damage_tmp){
    cout<<"��������"<<this->wname<<endl;
}
void Weapon::info()const{
    cout<<"��������:"<<this->wname<<"�˺�ֵ:"<<this->damage<<endl;
}
string Weapon::getName() const{
    return wname;
}
int Weapon::getDamage() const{
    return damage;
}
