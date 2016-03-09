#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character
{
    public:
        Character(std::string theme, std::string name);
        virtual ~Character();

        std::string name;
        std::string theme;                   //Ovo oznaèava dal je karakter turcin, srpski heroj, srpski izdajnik, srpski svetac, itd.
    protected:
    private:
        std::string generateName(std::string theme);
};

#endif // CHARACTER_H
