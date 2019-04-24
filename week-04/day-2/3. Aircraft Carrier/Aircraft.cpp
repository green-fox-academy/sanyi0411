//
// Created by sando on 2019. 04. 23..
//

#include "Aircraft.h"

Aircraft::Aircraft(Type type)
{
    _type = type;
    _ammunition = 0;
}

int Aircraft::getAmmunition()
{
    return _ammunition;
}

void Aircraft::setAmmunition(int a)
{
    _ammunition = a;
}

int Aircraft::baseDamage()
{
    if(_type == F16) {
        return 30;
    } else {
        return 50;
    }
}

int Aircraft::maxAmmo()
{
    if(_type == F16) {
        return 8;
    } else {
        return 12;
    }
}

int Aircraft::flight()
{
    int damage = _ammunition * baseDamage();
    _ammunition = 0;
    return damage;
}

int Aircraft::refill(int ammo)
{
    int canHaveAmmo = maxAmmo() - _ammunition;
    if(ammo <= canHaveAmmo) {
        _ammunition += ammo;
        return 0;
    } else {
        _ammunition = maxAmmo();
        return ammo - canHaveAmmo;
    }
}

std::string Aircraft::getType()
{
    if(_type == F16) {
        return "F16";
    } else {
        return "F35";
    }
}

std::string Aircraft::getStatus()
{
    std::string status = "Type " + getType() + ", Ammo: " + std::to_string(_ammunition) + ", Base Damage: " +
            std::to_string(baseDamage()) + ", All Damage: " + std::to_string(_ammunition * baseDamage());
    return status;
}

bool Aircraft::isPriority()
{
    if(_type == F16) {
        return false;
    } else {
        return true;
    };
}