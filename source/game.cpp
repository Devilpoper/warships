#include "../header/game.h"
#include <iostream>
Game::Game():
                player_(new Player),
                computer_(new Computer) {}

void Game::setup_computer(bool is_first_setup) {
    std::cout << "Computer placement: " << std::endl;

    if (!is_first_setup) {
        delete computer_;
        computer_ = new Computer;
        computer_->set_ships();
    }
    else {
        computer_->set_ships();
    }

    player_->set_enemy_data(computer_->get_field(), computer_->get_manager());
    computer_->set_enemy_field(player_->get_field());
}

void Game::setup_player() {
    int is_rand_placement;
    std::cout << "Place ships manually? [1 - y|0 - n] : ";
    std::cin >> is_rand_placement;
    std::cout << "Your placement: " << std::endl;
    if (is_rand_placement == 0)
        player_->randomly_place_ships();
    else
        player_->place_ships();
}


void Game::game_loop() {
    setup_player();
    setup_computer(true);

    bool game_over = false;
    while (!game_over) {
        player_->step();

        if (computer_->is_ships_destroyed()) {
            std::cout << "You destroy enemy!" << std::endl;
            setup_computer(false);
        }

        computer_->step();
        game_over = player_->is_ships_destroyed();
    }
}
