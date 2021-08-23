#include<iostream>
using namespace std;

int main(){
    int A[5]={1,2,3,4,5};

    int *P;
    P = new int[5];
    P[0] = 1;
    P[1] = 2;
    P[2] = 3;
    P[3] = 4;
    P[4] = 5;

    for(int i = 0; i<5 ; i++)
    {
        cout<<A[i]<<" ";
    }

    cout<<endl;

    for(int j = 0; j<5 ; j++)
    {
        cout<<A[j]<<" ";
    }

    return 0;
}