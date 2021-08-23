#include<iostream>
using namespace std;

int main(){
    char A[] = "MADAM";
    int i , j;
    for(j = 0;A[j]!='\0' ; j++)
    {}
    j=j-1;
    for(i=0;i<j ; i++ , j--)
    {
        if(A[i] != A[j])   
        {
            cout<<"STRING IS NOT PALINDROME";
            return 0;
        }   
    }
    cout<<"STRING IS PALINDROME";
        return 0;
}