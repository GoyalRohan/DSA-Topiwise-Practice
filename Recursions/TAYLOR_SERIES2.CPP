#include<iostream>
using namespace std;


//USING RECURSIONS

// int e(int x , int n)
// {
//     static int s =1;
//     if (n==0)
//         return s;
//     s = 1 + (x/n) *s;
//     return e( x , n-1);
// }

//USING ITERATION

int e(int x , int n)
{
    int s =1;
    for( ; n>0 ; n--)
    {
        s = 1 + (x/n)*s;
    }
    return s;
}

int main(){
    cout<<e(2,4);
    return 0;
}