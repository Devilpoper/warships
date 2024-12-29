
#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H
#include "../header/ship.h"
#include <vector>

class ShipManager {
private:
    std::vector<Ship*> _ships;
public:
    explicit ShipManager(const std::vector<int>& sizes);
    int size() const;
    void add_ship(int ship_size);
    void remove_ship(const Ship* ship);
    bool is_destroy_ship();
    bool is_ships_destriyed();
    Ship* get_ship(int idx) const;
};

#endif
