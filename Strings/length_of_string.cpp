#include<iostream>
using namespace std;

int main(){
    char *s = "welcome";        //THIS WILL CREATE STRING IN HEAP
    int i;
    for(i = 0; s[i]!='\0' ; i++)
    {}
    cout<<"length:"<<i;
    return 0;
}