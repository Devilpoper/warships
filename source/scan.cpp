#pragma once
#include <string>
#include <iostream>
#include "../header/scan.h"

void Scan::use_ability(Field *field) {
    int x;
    int y;
    std::cout << "scan activated"<<std::endl;
    std::cout << "Enter coords: " << std::endl <<"x - ";
    std::cin >> x;
    std::cout << "y - ";
    std::cin >> y;
    for (int dx = 0; dx < 2; dx++) {
        for (int dy = 0; dy < 2; dy++) {
            if (!field->is_out_of_bounds(x + dx, y + dy)) {
                if (field->has_ship(x + dx, y + dy)) {
                    std::cout << "Ship was found!" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "Ship was not found" << std::endl;
}

std::string Scan::get_label() {
    return "Scan";
}



