#include<iostream>
using namespace std;

int main(){
    const int n= 10;
    int A[n] = {3,6,8,8,10,12,15,15,15 , 20};

    // METHOD 1
    // int lastduplicate = 0;
    // for(int i = 0;i<n-1 ; i++)
    // {
    //     if((A[i] == A[i+1]) && (A[i] != lastduplicate))
    //     {
    //         cout<<endl<<A[i];
    //         lastduplicate = A[i];
    //     }
    // }


    // int i , j;
    // for(i = 0 ; i<n-1 ; i++)
    // {
    //     if(A[i] == A[i+1]) 
    //     {
    //         j = i+1;
    //         while(A[i] == A[j])
    //             j++;
    //         cout<<endl<<A[i]<<" is repeating for "<<j-i<<" times";
    //         i=j-1;
    //     }
    // }


    //METHOD 2- USING HASHING
    int *H = new int[21];
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    for(int i = 2 ; i<=20 ; i++)
    {
        if(H[i]>1)
        cout<<endl<<i<<"="<<H[i];
    }
    




    return 0;
}