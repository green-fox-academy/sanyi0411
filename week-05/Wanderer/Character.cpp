//
// Created by sando on 2019. 04. 29..
//

#include "Character.h"

int Character::getMaxHealthPoint() const
{
    return _maxHealthPoint;
}

int Character::getCurrentHealthPoint() const
{
    return _currentHealthPoint;
}

int Character::getDefendPoint() const
{
    return _defendPoint;
}

int Character::getStrikePoint() const
{
    return _strikePoint;
}

int Character::getLevel() const
{
    return _level;
}

int Character::getXOfCharacter() const
{
    return _xOfCharacter;
}

int Character::getYOfCharacter() const
{
    return _yOfCharacter;
}

void Character::setMaxHealthPoint(int maxHealthPoint)
{
    _maxHealthPoint = maxHealthPoint;
}

void Character::setCurrentHealthPoint(int currentHealthPoint)
{
    _currentHealthPoint = currentHealthPoint;
}

void Character::setDefendPoint(int defendPoint)
{
    _defendPoint = defendPoint;
}

void Character::setStrikePoint(int strikePoint)
{
    _strikePoint = strikePoint;
}

void Character::setLevel(int level)
{
    _level = level;
}

void Character::setXOfCharacter(int xOfCharacter)
{
    _xOfCharacter = xOfCharacter;
}

void Character::setYOfCharacter(int yOfCharacter)
{
    _yOfCharacter = yOfCharacter;
}


