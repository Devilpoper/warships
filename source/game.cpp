#include "../header/game.h"
#include <iostream>
Game::Game():
                player_(new Player),
                computer_(new Computer) {}

void Game::game_loop() {
    bool game_over = false;
    std::cout << "Computer placement: " << std::endl;
    computer_->set_ships();

    int is_rand_placement;
    std::cout << "Place ships manually? [1 - y|0 - n] : ";
    std::cin >> is_rand_placement;
    std::cout << "Your placement: " << std::endl;
    if (is_rand_placement == 0)
        player_->randomly_place_ships();
    else
        player_->place_ships();

    player_->set_enemy_data(computer_->get_field(), computer_->get_manager());
    computer_->set_enemy_field(player_->get_field());

    while (!game_over) {
        player_->step();
        computer_->step();
        game_over = player_->is_ships_destroyed();
    }
}
