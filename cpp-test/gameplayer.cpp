#include "gameplayer.h"

using namespace std;
void player_input(player_t* player){
    cout<<"�������������:"<<endl;
    cin>>player->name;
    cout<<"���������Ѫ��:"<<endl;
    cin>>player->blood;
}
void player_out(player_t* player){
    cout<<"�������:"<< player->name<<endl;
    cout<<"���Ѫ��:"<< player->blood<<endl;
}
