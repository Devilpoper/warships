#pragma once
#include "../header/abilityManager.h"
#include "../header/doubleDamage.h"
#include "../header/scan.h"
#include "../header/shelling.h"
#include "../header/const.h"
#include "../header/exception.h"
#include <ctime>
#include <random>
#include <iostream>
#define COUNT_ABILITY 3

void AbilityManager::print_abilities() const {
    if (abilities.empty()) {
        std::cout << "ability manager is empty" << std::endl;
        return;
    }
    std::cout << "Your abilities: ";
    std::queue<Ability*> temp = abilities;
    while (!temp.empty()) {
        std::cout << temp.front()->get_label() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

AbilityManager::AbilityManager() {
    std::mt19937 generator(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution distribution(0, 2);

    int rand_num =  distribution(generator);
    for (int i  = 0; i < COUNT_ABILITY; i++) {
        rand_num = (rand_num + 1) % COUNT_ABILITY;
        Ability* ability = nullptr;
        switch (rand_num % COUNT_ABILITY) {
            case double_damage:
                ability = new DoubleDamage();
            break;
            case scan:
                ability = new Scan();
            break;
            case shelling:
                ability = new Shelling();
            break;
            default:
                break;
        }
        abilities.push(ability);
    }
    print_abilities();
}

void AbilityManager::add_ability() {

    std::mt19937 generator(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution distribution(0, 2);

    int rand_num =  distribution(generator);

    Ability* ability = nullptr;
    switch (rand_num % COUNT_ABILITY) {
        case double_damage:
            ability = new DoubleDamage();
        break;
        case scan:
            ability = new Scan();
        break;
        case shelling:
            ability = new Shelling();
        break;
        default:
            break;
    }
    abilities.push(ability);
    print_abilities();
}

void AbilityManager::use_ability(Field* field) {
    if (abilities.empty())
        return;
    auto* ability = abilities.front();
    abilities.pop();
    ability->use_ability(field);
}

AbilityManager::~AbilityManager() {
    if (abilities.empty())
        throw NoAbilityException();

    for (int i = 0; i < abilities.size(); i++) {
        auto* ability = abilities.front();
        abilities.pop();
        delete ability;
    }
}

int AbilityManager::print() const {
   return abilities.size();
}

std::string AbilityManager::get_front_ability() const {
    return abilities.front()->get_label();
}
