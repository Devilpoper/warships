#include <vector>
#include <iostream>
#include "../header/computer.h"


void Computer::set_ships() {
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
    field->reset_status_ceils();
}


Computer::Computer():enemy_field(nullptr) {
    std::vector<int> ship_sizes;
    for (int i = 1; i < 5; i++)
        ship_sizes.push_back(i);


    field = new Field(10, 10);
    ship_manager = new ShipManager(ship_sizes);
}

void Computer::set_enemy_field(Field* _enemy_field) {
    enemy_field = _enemy_field;
}

Field *Computer::get_field() const {
    return field;
}

void Computer::step() {
    std::srand(std::time(nullptr));
    const int x = std::rand() % enemy_field->get_width();
    const int y = std::rand() % enemy_field->get_height();
    std::cout << "Computer was attack (" << x << ", " << y << ")" << std::endl;
    enemy_field->attack(x, y);
}

bool Computer::is_ships_destroyed() const {
    return ship_manager->is_ships_destriyed();
}

ShipManager *Computer::get_manager() const {
    return ship_manager;
}
