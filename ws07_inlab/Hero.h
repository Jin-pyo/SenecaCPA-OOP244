
#ifndef __HERO__H_
#define __HERO_H_

#include <iostream>

namespace sict
{

    const int max_rounds = 100;

    class Hero
    {
        char name[41];
        int health;
        int strength;
        
    public:
        Hero();
        Hero(const char *p_name, int p_health, int p_strength);

        void operator -= (int attack);
        bool isAlive() const;
        int attackStrength() const;

        friend std::ostream& operator << (std::ostream& os, const Hero& hero);

    };

    const Hero& operator* (const Hero& first, const Hero& second);
}


#endif
