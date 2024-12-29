#ifndef SCAN_H
#define SCAN_H
#include "ability.h"

class Scan final : public Ability {
public:
    void use_ability(Field* field) override;
    std::string get_label() override;
};

#endif
