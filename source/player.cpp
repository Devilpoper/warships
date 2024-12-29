#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../header/player.h"
#include "../header/computer.h"

Player::Player():enemy_field(nullptr), enemy_ship_manager(nullptr)
{
    int height;
    int width;
    std::vector<int> size_ships;
    for (int i = 1; i < 5; i++)
        size_ships.push_back(i);

    std::cout << "Enter width of field: ";
    std::cin >> width;
    std::cout << "Enter height of field: ";
    std::cin >> height;

    field = new Field(width, height);
    ability_manager = new AbilityManager;
    ship_manager = new ShipManager(size_ships);

}

Field *Player::get_field() const {
    return field;
}

void Player::randomly_place_ships() const {
    for (int idx = 0; idx < ship_manager->size(); idx++) {
        const auto ship = ship_manager->get_ship(idx);
        bool state = false;

        while (!state) {
            std::srand(std::time(nullptr));
            const int r_width = std::rand() % field->get_width();
            const int r_height = std::rand() % field->get_height();
            const int r_position = std::rand() % 2;
            state = field ->insert_ship(ship, r_width, r_height, r_position);
        }
    }
    field->print();
}

void Player::place_ships() const {
    int x;
    int y;
    int position;
    int answ;
    std::cout << "Do you want randomly place ships? [1 - y/0 - n]: ";
    std::cin >> answ;

    if (answ == 1) {
        randomly_place_ships();
        return;
    }

    for (int i = 0; i < ship_manager->size(); i++) {
        auto ship = ship_manager->get_ship(i);
        bool state = false;
        while (!state) {
            std::cout << "Enter x coord: ";
            std::cin >> x;
            std::cout << "Enter y coord: ";
            std::cin >> y;
            std::cout << "Set pos 0 - hrznt, 1 - vrtkl";
            std::cin >> position;
            state = field->insert_ship(ship, x, y, position);
            if (!state)
                std::cout << "Something went wrong" << std::endl;
        }
    }
}

void Player::set_enemy_data(Field* _enemy_field, ShipManager* _enemy_manager) {
    enemy_field = _enemy_field;
    enemy_ship_manager = _enemy_manager;
}


void Player::step() {
    int x;
    int y;
    int choice;
    std::cout << "Do you want use an ability? [1 - y/0 - n] : ";
    std::cin >> choice;

    if (choice == 1) {
        if (ability_manager->print() == 0) {
            std::cout << "you can not use ability, it is empty" << std::endl;
            return;
        }
        ability_manager->use_ability(enemy_field);

        if (enemy_ship_manager->is_destroy_ship()) {
            std::cout << "You destroy enemy ship" << std::endl;
            ability_manager->add_ability();
        }


        enemy_field->print();
        return;
    }

    std::cout << "Enter x coord: ";
    std::cin >> x;
    std::cout << "Enter y coord: ";
    std::cin >> y;


    enemy_field->attack(x, y);

    if (enemy_ship_manager->is_destroy_ship()) {
        std::cout << "you destroy enemy ship!" << std::endl;
        ability_manager->add_ability();
    }
    enemy_field->print();
}

bool Player::is_ships_destroyed() {
    return ship_manager->is_ships_destriyed();
}


