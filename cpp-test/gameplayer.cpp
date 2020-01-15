#include "gameplayer.h"

using namespace std;
void player_input(player_t* player){
    cout<<"请输入玩家名称:"<<endl;
    cin>>player->name;
    cout<<"请输入玩家血量:"<<endl;
    cin>>player->blood;
}
void player_out(player_t* player){
    cout<<"玩家名称:"<< player->name<<endl;
    cout<<"玩家血量:"<< player->blood<<endl;
}
