#ifndef ABILITY_H
#define ABILITY_H
#pragma once
#include "../header/field.h"
#include <string>

class Field;

class Ability {
public:
    virtual ~Ability() = default;
    virtual void use_ability(Field *field) = 0;
    virtual std::string get_label() = 0;
};

#endif
