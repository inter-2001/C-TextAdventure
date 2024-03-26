#include "Weapon.h"

std::string Weapon::GetName()
{
    return std::string(name);
}

std::string Weapon::GetDescription()
{
    return std::string(description);
}

int Weapon::GetAttack()
{
    return attack;
}

int Weapon::GetDefense()
{
    return defense;
}
