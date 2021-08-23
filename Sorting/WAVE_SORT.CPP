#include<iostream>
using namespace std;

void Swap(int A[] , int i , int j)
{
    int temp = A[i];
    A[i] =A[j];
    A[j]  =temp;
}

void wave(int A[] , int size)
{
    for(int i=1 ; i<size ; i = i+2)
    {
        if(A[i] > A[i-1])
            Swap(A , i , i-1);

        if(A[i] > A[i+1] && i<=size-2)
            Swap(A , i , i+1);
    }
}

int main(){
    const int n=7;
    int A[n] = {1,2,3,4,5,6 ,7};

    cout<<"Aray before sorting : ";
    for(int i=0 ; i<n ; i++)
    {
        cout<<A[i]<<" ";
    }

    wave(A , n);

     cout<<"\nAray after sorting : ";
    for(int i=0 ; i<n ; i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}