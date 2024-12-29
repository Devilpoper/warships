#ifndef FIELD_H
#define FIELD_H
#pragma once
#include "const.h"
#include <vector>
#include "../header/ship.h"
#include "../header/ability.h"

class Ability;

class Field {
private:
    class Segment {
    private:
        Ship* ship;
        int state;
        int index_segment_ship;
    public:
        Segment();
        void set_ship_segment(Ship* ship, int index_segment);
        void set_state(ceil_state state);
        void attack_segment() const;
        int get_ship_hp() const;
        bool is_empty() const;
        int get_state() const;
    };

    Segment** field;
    int _width;
    int _height;

    bool is_correct_place(int ship_size, int x, int y, int orientation) const;
    bool is_correct_segment(int x, int y) const;

public:
    Field(int width, int height);
    std::vector<coord> get_coord_ships() const;
    int get_width() const;
    int get_height() const;
    bool insert_ship(Ship* ship, int x, int y, int position) const;
    bool is_out_of_bounds(int x, int y) const;
    bool has_ship(int x, int y) const;
    void useAbility(Ability* ability);
    void destroy_segment(int x, int y) const;
    void attack(int x, int y) const;
    void set_segment_for_coord(int x, int y, ceil_state state) const;
    void reset_status_ceils() const;
    void print() const;
};

#endif //FIELD_H
