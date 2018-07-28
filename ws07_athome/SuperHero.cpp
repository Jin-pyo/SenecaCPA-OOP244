#include <iostream>
#include <cstring>
#include "SuperHero.h"

namespace sict {

    SuperHero::SuperHero() : Hero()
    {
        atkBonus = 0;
        defense = 0;
    }

    SuperHero::SuperHero(const char * p_name, int p_health, int p_atk, int p_atkbonus, int p_defense) : Hero(p_name, p_health, p_atk)
    {
        bool valid = false;

        if (p_atkbonus > 0)
        {
            if (p_defense)
            {

                atkBonus = p_atkbonus;
                defense = p_defense;

                valid = true;
            }
        }


        if (!valid)
        {
            atkBonus = 0;
            defense = 0;
        }

    }


    int SuperHero::attackStrength() const
    {
        return Hero::strength + atkBonus;
    }

    int SuperHero::defend() const
    {
        return defense;
    }

    const SuperHero& operator * (const SuperHero& first, const SuperHero& second)
    {
        int rounds = 0;
        int flag = 0;


        SuperHero cpyOne = first;
        SuperHero cpyTwo = second;

        for (int i = 1; !flag; i++)
        {

            cpyOne -= (cpyTwo.attackStrength() - cpyOne.defend());
            cpyTwo -= (cpyOne.attackStrength() - cpyTwo.defend());

            if (!(cpyOne.isAlive()) || !(cpyTwo.isAlive()))
            {
                rounds = i;
                flag = 1;
            }

            if (i == max_rounds)
            {
                flag = 1;
            }

        }

        std::cout << "Super Fight! " << first << " vs " << second
            << " : Winner is ";

        if (cpyOne.isAlive())
        {
            std::cout << first;
        }

        else
        {
            std::cout << second;
        }

        std::cout << " in " << rounds << " rounds." << std::endl;


        return cpyOne.isAlive() ? first : second;
    }

}
