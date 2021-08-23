#include<iostream>
using namespace std;

//FIRST METHOD

// int pow(int m , int n)
// {
//     if(n == 0)
//         return 1;
//     else 
//         return pow(m , n-1) * m;
// }

//SECOND METHOD

int pow_new(int m , int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return pow_new(m* m , n/2);
    else
        return m* pow_new(m* m , (n-1)/2);
}

int main(){
    int m , n;
    cout<<"enter the values of m and n :";
    cin>>m>>n;
    // cout<<pow(m , n);
    cout<<pow_new(m , n);
    return 0;
}