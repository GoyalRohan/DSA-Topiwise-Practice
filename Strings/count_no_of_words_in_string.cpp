#include<iostream>
using namespace std;

int main(){
    char A[] = "how are you Rohan";
    int words = 1;
    for(int i =0 ; A[i]!='\0' ; i++)   
    {
        if(A[i] == ' ' && A[i-1]!= ' ')
        {
            words++;
        }
    }
    cout<<"no. of words in the string:"<<words;
    return 0;
}