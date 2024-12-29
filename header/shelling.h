#ifndef SHELLING_H
#define SHELLING_H

#include "ability.h"

class Shelling final : public Ability{
public:
     void use_ability(Field *field) override;
     std::string get_label() override;
};

#endif
