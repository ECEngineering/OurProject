#ifndef NAMEDATABASE_H
#define NAMEDATABASE_H

#include<iostream>
#include<vector>
#include<fstream>

struct predefinedName
{
    std::string name;
    std::string surname;
    std::string theme;
    char gender;
};

struct baseNames
{
    std::string theme;
    std::vector<std::string> names;
    std::vector<std::string> surnames;
    std::vector<std::string> titles;
};

class NameDatabase
{
    public:
        NameDatabase();
        virtual ~NameDatabase();

        int totalPredefinedNames;
        int totalBaseNames;

        predefinedName predefinedNames[100];
        baseNames allBaseNames[5];

    protected:
    private:
        std::string nameDir = "names";

        void loadPredefinedNames(predefinedName destination[100],int* totalNo);
        void loadBaseNames(baseNames destination[5],int* totalNo);
};


#endif // NAMEDATABASE_H
