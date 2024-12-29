#ifndef GAME_H
#define GAME_H

#include "computer.h"
#include "player.h"

class Game {
private:
    Computer* computer_;
    Player* player_;
public:
    Game();
    void game_loop();
    void save_game();
    void load_game();
};


#endif
