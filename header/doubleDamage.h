#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H
#include "ability.h"

class DoubleDamage final : public Ability{
public:
    void use_ability(Field* field) override;
    std::string get_label() override;
};

#endif
