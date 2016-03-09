#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;

string format1(){
    string n;
    string br;
    string p[3] {"Sveti Sava", "Marko Kraljevic","Devojka"};
    string b[13]{"2","3","4","5","6","7","8","9","10","12","13","100","101"};
    string neg1[3]{"turcin","izdajnik","momak"};
    string neg2[3]{"turcina","izdajnika","momka"};
    string neg3[3]{"turcina","izdajnika","momaka"};
    n = p[rand() % 3];
    n+=" i ";
    br = b[rand() % 13];
    n+= br + " ";
    if(br[br.length()-1]=='1')
        n+= neg1[rand() % 3];
    else if(br[br.length()-1]=='2' or br[br.length()-1]=='3' or br[br.length()-1]=='4'){
        if(br.length()>2 or br.length()==1)
            n+= neg2[rand() % 3];
        else if(br[br.length()-2]=='1')
            n+= neg3[rand() % 3];
        else n+= neg2[rand() % 3];
    }
    else n+= neg3[rand() % 3];
    return n;
}

struct genericName
{
    //Za predefinisane likove
    string name;
    string surname;
    string theme;
    char gender;
};

struct baseNames
{
    string theme;
    vector<string> names;
    vector<string> surnames;
    vector<string> titles;
};

void removeUnderscores(string& s)
{
    for(string::iterator it=s.begin();it!=s.end();it++)
    {
        if(*it == '_')
        {
            *it = ' ';
        };
    }
}

void loadGenericNames(genericName destination[100],int* totalNo)
{
    ifstream inputText("names//preDefinedNames.txt");

    int i = 0;
    while(!inputText.eof())
    {
        inputText >> destination[i].name >> destination[i].surname >> destination[i].theme >> destination[i].gender;
        //removeUnderscores(destination[i].name);
        i+=1;
    }
    *totalNo = i-1;
}

void loadBaseNames(baseNames destination[5],int* totalNo)
{
    ifstream inputTheme("names//nameThemeList.txt");
    int i = 0;

    while(!inputTheme.eof())
    {
        inputTheme >> destination[i].theme;
        i+=1;
    }
    *totalNo = i;
    inputTheme.close();

    ifstream inputElse;
    for(i=0;i<*totalNo;i++)
    {
        string tmp;
        inputElse.open("names//" + destination[i].theme + "//names.txt");
        while(!inputElse.eof())
        {
            inputElse >> tmp;
            (destination[i].names).push_back(tmp);
        }
        inputElse.close();

        inputElse.open("names//" + destination[i].theme + "//surnames.txt");
        while(!inputElse.eof())
        {
            inputElse >> tmp;
            (destination[i].surnames).push_back(tmp);
        }
        inputElse.close();

        inputElse.open("names//" + destination[i].theme + "//titles.txt");
        while(!inputElse.eof())
        {
            inputElse >> tmp;
            (destination[i].titles).push_back(tmp);
        }
        inputElse.close();
    }
}

int totalPredefinedNames;
int totalBaseNames;
genericName predefinedNames[100];
baseNames allBaseNames[5];

int main()
{
    srand(time(NULL));
    int format;
    string name;
    format = rand() % 3;

    format = 1;
    for(int i = 0; i < 20; i++){
        if(format==1) name = format1();

        cout << name << endl;
    }

    loadGenericNames(predefinedNames,&totalPredefinedNames);
    loadBaseNames(allBaseNames,&totalBaseNames);

    for(int i=0;i<totalBaseNames;i++)
    {
        cout << allBaseNames[i].theme << endl;
        for(vector<string>::iterator v = (allBaseNames[i].names).begin();v!=(allBaseNames[i].names).end();v++)
        {
            cout << *v << " ";
        }
        cout << endl;
    }
    return 0;
}
