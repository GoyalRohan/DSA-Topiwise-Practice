#include<iostream>
using namespace std;

// ITERATIVE STATEMENT

int fib(int n)
{
    int t0 = 0 , t1 = 1 , i , s = 0;
    if (n<=1)
        return n;
    else
    {
        for(i =2; i<=n ; i++)
        {
        s = t0 +t1;
        t0 = t1;
        t1 = s;
        }
    }
    return s;
}


//ONLY USING RECURSIONS

// int fib(int n)
// {
//     if (n<=1)
//         return n;
//     else
//         return fib(n-2) + fib(n-1);
// }

//USING RECURSIONS + MEMOAIZAITON

// int F[10];
// int fib(int n)
// {
//     if( n<=1)
//         {
//             F[n] = n;
//             return n;
//         }
//     else
//     {
//         if(F[n-2] == -1)
//             F[n-2] == fib(n-2);
//         if(F[n-1] == -1)
//             F[n-1] == fib(n-1);
        
//         F[n] = F[n-2] + F[n-1];
//         return F[n-2] + F[n-1];
//     }
// }



int main(){
    cout<<fib(5);


    // for (int i=0;i<10;i++)
    // {
    //     F[i]=-1;
    // }

    // cout<<fib(5);
    return 0;
}