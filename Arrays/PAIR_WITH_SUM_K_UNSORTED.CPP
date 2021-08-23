#include<iostream>
#include<math.h>
using namespace std;

int main(){
    const int n = 10;
    int A[n] = {6,3,8,10,16,7,5,2,9,14};
    int k;
    cout<<"enter the sum you want to get:";
    cin>>k;


    //FIRST METHOD
    // for(int i = 0 ; i<n-1 ; i++ )
    // {
    //     for(int j = i+1 ; j<n ; j++)
    //     {
    //         if(A[i] + A[j] == k)
    //             cout<<endl<<A[i]<<"+"<<A[j]<<"="<<k;
    //     }
    // }

    //SECOND METHOD
    int *H = new int[17];
    for(int i = 0; i<n ; i++)
    {
        if(H[k - A[i]] != 0)
        {
            if(A[i] <k)
            cout<<endl<<A[i]<<"+"<<k - A[i]<<"="<<k;

        }
        H[A[i]]++;
    }
    return 0;
}