#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <queue>
#include "../header/ability.h"

class AbilityManager {
private:
    std::queue<Ability*> abilities;
public:
    AbilityManager();
    void add_ability();
    void use_ability(Field* field);
    int print() const;
    void print_abilities() const;
    std::string get_front_ability() const;
    ~AbilityManager();
};

#endif
