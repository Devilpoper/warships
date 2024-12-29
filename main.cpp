#include "header/game.h"
#include "header/field.h"
#include "header/ship.h"

int main() {
    auto game = new Game();
    game->game_loop();
}