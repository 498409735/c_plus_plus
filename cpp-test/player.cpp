#include "player.h"

Player::Player(const string name_tmp,const int blood_tmp)
    :name(name_tmp),blood(blood_tmp){
    cout<<"创建玩家"<<this->name<<endl;
}
void Player::info()const{
    cout<<"玩家姓名:"<<this->name<<"玩家血量:"<<this->blood<<endl;
    for(int i=0;i<WEAPON_NUM;i++){
        cout<<"\t武器:"<<i+1<<":"<<this->m_weapon[i]->getName()<<" "<<this->m_weapon[i]->getDamage()<<endl;
    }
}
string Player::getName() const{
    return this->name;
}
void Player::initWeapon(){
    string name_tmp;
    int hurt;
    for(int i=0;i<WEAPON_NUM;i++){
        cout<<"请输入武器名称"<<endl;
        cin>>name_tmp;
        cout<<"请输入武器攻击力:"<<endl;
        cin>>hurt;
        this->m_weapon[i] = new Weapon(name_tmp,hurt);
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
    cout<<this->name<<" 用 "<<pWeapon->getName()<<" 攻击 "<<other.getName()<<"---"<<other.getName()<<
          "的血量剩下:"<<other.getBlood()<<endl;
}
