cmake_minimum_required(VERSION 3.30)
project(war_of_warships)

set(CMAKE_CXX_STANDARD 20)

add_executable(war_of_warships main.cpp
        header/ship.h
        header/const.h
        source/ship.cpp
        header/shipManager.h
        source/shipManager.cpp
        header/Field.h
        source/field.cpp
        header/ability.h
        header/doubleDamage.h
        source/doubleDamage.cpp
        header/shelling.h
        header/scan.h
        source/scan.cpp
        source/shelling.cpp
        header/abilityManager.h
        source/abilityManager.cpp
        header/exception.h
        source/exception.cpp
        header/game.h
        header/player.h
        source/player.cpp
        header/computer.h
        source/computer.cpp
        source/game.cpp
)
