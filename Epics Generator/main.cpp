#include <iostream>
#include <stdlib.h>
#include <string>

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

int main()
{
    int format;
    string name;
    format = rand() % 3;

    format = 1;
    for(int i = 0; i < 20; i++){
        if(format==1) name = format1();

        cout << name << endl;
    }
    return 0;
}
