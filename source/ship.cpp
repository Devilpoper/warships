#include "../header/ship.h"
#include "../header/const.h"

Ship::Ship(const int len, const int orientation) :
                                        _len(len),
                                        _orientation(orientation),
                                        _segments(new int[len])
{
    for (int i = 0; i < len; i++) {
        _segments[i] = full;
    }
}

Ship::Ship(const int len): Ship(len, horizontal){}

Ship::~Ship(){
    delete[] _segments;
}

int Ship::get_orientation() const{
    return _orientation;
}

int Ship::get_segment_hp(const int idx) const {
    return _segments[idx];
}


void Ship::attack_segment(const int num_segment) const {
    if (_segments[num_segment] > 0)
        _segments[num_segment] -= 1;
}

bool Ship::is_destroyed() const {
    for (int i = 0; i < _len; i++) {
        if (_segments[i] != 0)
            return false;
    }
    return true;
}

int Ship::get_size() const {
    return _len;
}

