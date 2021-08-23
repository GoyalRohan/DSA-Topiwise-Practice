#include<iostream>
using namespace std;

int Validate(char *name)
{
    for(int i =0 ;name[i]!=0 ; i++)
    {
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
            return 0;
    }
    return 1;
}

int main(){
    char *name = "Ani?350";
    if(Validate(name) == 0)
        cout<<"invalid string";
    else
        cout<<"valid string";
    return 0;
}