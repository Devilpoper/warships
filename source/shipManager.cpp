#include "../header/shipManager.h"
#include <algorithm>

ShipManager::ShipManager(const std::vector<int>& sizes)
{
    for (auto i : sizes) {
        _ships.push_back(new Ship(i));
    }
}

int ShipManager::size() const {
    return _ships.size();
}

bool ShipManager::is_ships_destriyed() {
    return _ships.empty();
}


void ShipManager::add_ship(const int ship_size) {
        const auto ship = new Ship(ship_size);
        _ships.push_back(ship);
}

void ShipManager::remove_ship(const Ship *ship) {
    int idx = 0;
    for (int i = 0; i < _ships.size(); i++) {
        if (_ships[i] == ship)
            idx = i;
    }
    _ships.erase(_ships.begin() + idx);
}

Ship *ShipManager::get_ship(int idx) const {
    return _ships[idx];
}

bool ShipManager::is_destroy_ship() {
    auto erased = std::erase_if(_ships, [](const auto& ship) {
        return ship->is_destroyed();
    });
    return erased > 0;
}



