#pragma once
#include <iostream>
#include <string>
#include "../header/doubleDamage.h"

void DoubleDamage::use_ability(Field* field) {
    int x;
    int y;
    std::cout << "double damage activated"<<std::endl;
    std::cout << "Enter coords: " << std::endl <<"x - ";
    std::cin >> x;
    std::cout << "y - ";
    std::cin >> y;

    if (field->has_ship(x, y)) {
        field->destroy_segment(x, y);
        field->set_segment_for_coord(x, y, is_ship);
    }
}

std::string DoubleDamage::get_label() {
    return "DoubleDamage";
}
