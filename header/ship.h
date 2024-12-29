#ifndef SHIP_H
#define SHIP_H

class Ship {
private:
    int _len;
    int _orientation;
    int* _segments;
public:
    Ship(int len, int orientation);
    explicit Ship(int len);
    ~Ship();

    int get_orientation() const;
    void attack_segment(int num_segment) const;
    int get_segment_hp(int idx) const;
    bool is_destroyed() const;
    int get_size() const;
};

#endif
