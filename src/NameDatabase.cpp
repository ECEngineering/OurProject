#include "NameDatabase.h"

NameDatabase::NameDatabase()
{
    loadPredefinedNames(predefinedNames,&totalPredefinedNames);

    loadBaseNames(allBaseNames, &totalBaseNames);

    for(int i=0;i<totalBaseNames;i++)
    {
        std::cout << allBaseNames[i].theme << std::endl;
        for(std::vector<std::string>::iterator v = (allBaseNames[i].names).begin();v!=(allBaseNames[i].names).end();v++)
        {
            std::cout << *v << " ";
        }
        std::cout << std::endl;
    }
}

NameDatabase::~NameDatabase()
{
    //dtor
}

void NameDatabase::loadPredefinedNames(predefinedName destination[100],int* totalNo)
{
    std::ifstream inputText(nameDir + "//preDefinedNames.epic");

    int i = 0;
    while(!inputText.eof())
    {
        inputText >> destination[i].name >> destination[i].surname >> destination[i].theme >> destination[i].gender;
        i+=1;
    }
    *totalNo = i-1;
}

void NameDatabase::loadBaseNames(baseNames destination[5],int* totalNo)
{
    std::ifstream inputTheme(nameDir + "//nameThemeList.epic");
    int i = 0;

    while(!inputTheme.eof())
    {
        inputTheme >> destination[i].theme;
        i+=1;
    }
    *totalNo = i;
    inputTheme.close();

    std::ifstream inputElse;
    for(i=0;i<*totalNo;i++)
    {
        std::string tmp;
        inputElse.open(nameDir + "//" + destination[i].theme + "//names.epic");
        while(!inputElse.eof())
        {
            inputElse >> tmp;
            (destination[i].names).push_back(tmp);
        }
        inputElse.close();

        inputElse.open(nameDir + "//" + destination[i].theme + "//surnames.epic");
        while(!inputElse.eof())
        {
            inputElse >> tmp;
            (destination[i].surnames).push_back(tmp);
        }
        inputElse.close();

        inputElse.open(nameDir + "//" + destination[i].theme + "//titles.epic");
        while(!inputElse.eof())
        {
            inputElse >> tmp;
            (destination[i].titles).push_back(tmp);
        }
        inputElse.close();
    }
}
