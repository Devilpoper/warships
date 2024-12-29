#include "../header/exception.h"

const char *NoAbilityException::what() const noexcept {
    return "No ability available";
}

const char *OutOfBoundsAttackException::what() const noexcept {
    return "Attack has out of bounds";
}

const char *CollosionShipsException::what() const noexcept {
    return "This placement of the ship is impossible";
}