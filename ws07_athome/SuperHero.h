#ifndef __SUPERHERO_H_
#define __SUPERHERO_H_

#include "Hero.h"

namespace sict {

    class SuperHero : public Hero
    {
        int atkBonus;
        int defense;

    public:
        SuperHero();
        SuperHero(const char * name, int health, int atk, int atkBonus, int defend);

        int attackStrength() const;
        int defend() const;
    };

    const SuperHero& operator * (const SuperHero& first, const SuperHero& second);

}




#endif