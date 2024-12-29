#ifndef PLAYER_H
#define PLAYER_H

#include "field.h"
#include "abilityManager.h"
#include "shipManager.h"

class Player {
private:
    Field* field;
    Field* enemy_field;
    AbilityManager* ability_manager;
    ShipManager* ship_manager;
    ShipManager* enemy_ship_manager;
public:
    Player();
    void randomly_place_ships() const;
    void place_ships() const;
    Field* get_field() const;
    void set_enemy_data(Field* _enemy_field, ShipManager* _enemy_manager);
    bool is_ships_destroyed();

    void step();
};

#endif //PLAYER_H
