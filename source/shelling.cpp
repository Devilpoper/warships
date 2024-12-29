#pragma once
#include <string>
#include <vector>
#include "../header/Shelling.h"

void Shelling::use_ability(Field *field) {
    std::vector<coord> coords = field->get_coord_ships();
    srand(time(0));
    coord rand_pair = coords[rand() % coords.size()];
    field->attack(rand_pair.x, rand_pair.y);
}

std::string Shelling::get_label() {
    return "Shelling";
}
