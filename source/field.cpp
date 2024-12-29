#include <iostream>
#include <vector>
#include "../header/field.h"
#include "../header/const.h"
#include "../header/exception.h"

Field::Segment::Segment(): ship(nullptr), state(unknown), index_segment_ship(-1){}

void Field::Segment::set_ship_segment(Ship *ship, const int index_segment) {
    this->ship = ship;
    index_segment_ship = index_segment;
    state = is_ship;
}

bool Field::Segment::is_empty() const {
    if (index_segment_ship != -1)
        return false;
    return true;
}

void Field::Segment::set_state(const ceil_state state) {
    this->state = state;
}

void Field::Segment::attack_segment() const {
    if (!is_empty()) {
        ship->attack_segment(index_segment_ship);
    }
}

int Field::Segment::get_state() const {
    return state;
}

int Field::Segment::get_ship_hp() const {
    return ship->get_segment_hp(index_segment_ship);
}



Field::Field(const int width, const int height) :
                                    _width(width),
                                    _height(height)
{
    field = new Segment*[height];
    for (int i = 0; i < height; i++)
        field[i] = new Segment[width];
}

bool Field::is_out_of_bounds(int x, int y) const {
    if(x >= 0 && x < _width && y >= 0 && y < _height)
        return false;
    return true;
}

int Field::get_height() const {
    return _height;
}

int Field::get_width() const {
    return _width;
}

bool Field::is_correct_segment(int x, int y) const
{
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int newX = x + dx;
            int newY = y + dy;

            if (is_out_of_bounds(x, y))
                return false;

            if (!is_out_of_bounds(newX, newY))
                if (!field[newY][newX].is_empty())
                    return false;

        }
    }
    return true;
}

std::vector<coord> Field::get_coord_ships() const {
    std::vector<coord> coords;
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            if (!field[y][x].is_empty()) {
                coords.push_back({x, y});
            }
        }
    }
    return coords;
}


bool Field::is_correct_place(int shipSize, int x, int y, int position) const
{
    if(position == vertical){
        for(int i = 0; i < shipSize; i++){
            if(!is_correct_segment(x, y + i))
                return false;
        }
    }

    if(position == horizontal){
        for(int i = 0; i < shipSize; i++){
            if(!is_correct_segment(x + i, y))
                return false;
        }
    }
    return true;
}

bool Field::insert_ship(Ship *ship, int x, int y, int position) const {
    if (is_out_of_bounds(x, y))
        return false;

    int shipSize = ship->get_size();

    if(!is_correct_place(shipSize, x, y, position))
        return false;


    if(position == horizontal){
        for(int i = 0; i < shipSize; i++)
            field[y][x + i].set_ship_segment(ship, i);
    }

    if(position == vertical){
        for(int i = 0; i < shipSize; i++)
            field[y + i][x].set_ship_segment(ship, i);
    }
    return true;
}

void Field::attack(int x, int y) const {
    if (is_out_of_bounds(x, y)) {
        throw OutOfBoundsAttackException();
    }


    if (field[y][x].is_empty()) {
        field[y][x].set_state(empty);
        std::cout << "Miss" << std::endl;
        return;
    }

    field[y][x].set_state(is_ship);
    std::cout << "Enemy ship was attacked" << std::endl;
    field[y][x].attack_segment();
}

bool Field::has_ship(int x, int y) const {
    return !field[y][x].is_empty();
}

void Field::destroy_segment(int x, int y) const {
    if (!field[y][x].is_empty()) {
        field[y][x].attack_segment();
        field[y][x].attack_segment();
    }
}


void Field::print() const {
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            if (field[y][x].get_state() == empty)
                std::cout << "*  ";

            if (field[y][x].get_state() == unknown)
                std::cout << "~  ";

            if (field[y][x].get_state() == is_ship) {
                int hp = field[y][x].get_ship_hp();
                if (hp == full)
                    std::cout << "2  ";
                else if (hp == hurt)
                    std::cout << "1  ";
                else
                    std::cout << "0  ";
            }
        }
        std::cout << std::endl;
    }
}

void Field::useAbility(Ability *ability) {
    ability->use_ability(this);
}

void Field::reset_status_ceils() const {
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            field[y][x].set_state(unknown);
        }
    }
}

void Field::set_segment_for_coord(int x, int y, ceil_state state) const {
    field[y][x].set_state(state);
}
