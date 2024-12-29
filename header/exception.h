#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class NoAbilityException : public std::exception {
    const char* what() const noexcept override;
};

class OutOfBoundsAttackException : public std::exception {
    const char* what() const noexcept override;
};

class CollosionShipsException : public std::exception {
    const char* what() const noexcept override;
};


#endif
