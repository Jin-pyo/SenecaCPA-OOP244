#include <iostream>
#include <cstring>
#include "Hero.h"


namespace sict
{
    Hero::Hero()
    {
        name[0] = '\0';
        health = 0;
        strength = 0;
    }

    Hero::Hero(const char *p_name, int p_health, int p_strength)
    {
        bool valid = false;

        if (p_name != nullptr)
        {
            if (p_health > 0)
            {
                if (p_strength > 0)
                {
                    strncpy(name, p_name, 40);
                    name[40] = '\0';

                    health = p_health;

                    strength = p_strength;

                    valid = true;
                }
            }

        }

        if (!valid)
        {
            name[0] = '\0';
            health = 0;
            strength = 0;
        }

    }

    void Hero::operator -= (int p_attack)
    {
        if (p_attack > 0)
        {
            if ((health - p_attack) <= 0)
            {
                health = 0;
            }

            else
            {
                health -= p_attack;
            }
        }

        return;
    }

    bool Hero::isAlive() const
    {
        bool alive = false;

        if (health > 0)
        {
            alive = true;
        }

        return alive;
    }

    int Hero::attackStrength() const
    {
        return strength;
    }

    std::ostream& operator << (std::ostream& os, const Hero& hero)
    {
        if (hero.name != nullptr)
        {
            os << hero.name;
        }

        else
        {
            os << "No hero";
        }

        return os;
    }

    const Hero& operator * (const Hero& first, const Hero& second)
    {
        int rounds = 0;
        int flag = 0;

        
        Hero cpyOne = first;
        Hero cpyTwo = second;

        for (int i = 1; !flag; i++)
        {

            cpyOne -= cpyTwo.attackStrength();
            cpyTwo -= cpyOne.attackStrength();

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



        std::cout << "Ancient Battle! " << first << " vs " << second
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

