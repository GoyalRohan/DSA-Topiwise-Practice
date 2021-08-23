#include<iostream>
using namespace std;

//  RECURSIVE METHOD

// int fact(int n)
// {
//     if(n==0)
//         return 1;
//     else
//         return fact(n-1) * n;

// }

//  ITERATIVE METHOD
int ifact(int n)
{
    int i , fact = 1;
    for (i = 1 ; i<=n; i++)
    {
        fact = fact *i;
    }
    return fact;
}

int main(){
    int n;
    cout<<" enter the no whose factorial you want to get:";
    cin>>n;
    // cout<<fact(n);
    cout<<ifact(n);
    return 0;
}