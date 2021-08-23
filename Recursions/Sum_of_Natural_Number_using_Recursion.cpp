#include<iostream>
using namespace std;

//  RECURSIVE METHOD
int sum(int n)
{
    if(n==0)
        return 0;
    else
        return sum(n-1) + n;

}

//  ITERATIVE METHOD
// int isum(int n)
// {
//     int i , sum = 0;
//     for (i = 0 ; i<=n; i++)
//     {
//         sum = sum + i;
//     }
//     return sum;
// }

int main(){
    int n;
    cout<<" enter the no upto which you want to get the sum:";
    cin>>n;
    cout<<sum(n);
    // cout<<isum(n);
    return 0;
}