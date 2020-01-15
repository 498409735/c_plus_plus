#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#include <iostream>
using namespace std;

typedef struct Player{
    string name;
    unsigned int blood;
}player_t;

void player_input(player_t* player);
void player_out(player_t* player);
#endif // GAMEPLAYER_H
