#include "player.h"

Player::Player(const string name_tmp,const int blood_tmp)
    :name(name_tmp),blood(blood_tmp){
    cout<<"�������"<<this->name<<endl;
}
void Player::info()const{
    cout<<"�������:"<<this->name<<"���Ѫ��:"<<this->blood<<endl;
    for(int i=0;i<WEAPON_NUM;i++){
        cout<<"\t����:"<<i+1<<":"<<this->m_weapon[i]->getName()<<" "<<this->m_weapon[i]->getDamage()<<endl;
    }
}
string Player::getName() const{
    return this->name;
}
void Player::initWeapon(){
    string name;
    int hurt;
    for(int i=0;i<WEAPON_NUM;i++){
        cout<<"��������������"<<endl;
        cin>>name;
        cout<<"����������������:"<<endl;
        cin>>hurt;
        this->m_weapon[i] = new Weapon(name,hurt);
    }
}
int Player::getBlood()const{
    return this->blood;
}
Weapon* Player::getWeapon()const{
    srand((unsigned int)time(NULL));
    int num = rand()%WEAPON_NUM;
    return m_weapon[num];
}
void Player::dropBood(const int blood_tmp){
    this->blood-= blood_tmp;
}

void Player::attack(Player&other){
    Weapon * pWeapon = this->getWeapon();
    if(pWeapon->getDamage()>=other.getBlood()){
        other.dropBood(other.getBlood());
    }else {
        other.dropBood(pWeapon->getDamage());
    }
    cout<<this->name<<" �� "<<pWeapon->getName()<<" ���� "<<other.getName()<<"---"<<other.getName()<<
          "��Ѫ��ʣ��:"<<other.getBlood()<<endl;
}
