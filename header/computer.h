#ifndef COMPUTER_H
#define COMPUTER_H

#include "field.h"
#include "shipManager.h"

class Computer {
private:
    Field* field;
    Field* enemy_field;
    ShipManager* ship_manager;
public:
    Computer();
    Field* get_field() const;
    ShipManager* get_manager() const;
    void set_enemy_field(Field* _enemy_field);
    void set_ships();
    bool is_ships_destroyed() const;
    void step();
};

#endif
