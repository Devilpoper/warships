#ifndef CONST_H
#define CONST_H

struct coord {
    int x;
    int y;
};

enum ability : int {double_damage, shelling, scan};
enum length : int {one, two, three, four};
enum orientation : int {horizontal, vertical};
enum health : int {destroy, hurt, full};
enum ceil_state : int {unknown, is_ship, empty};

#endif
