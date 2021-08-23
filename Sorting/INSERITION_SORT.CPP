#include<iostream>
using namespace std;

void insertionSort(int A[] , int n)
{
    int i , j , x;
    for(int i=1 ; i<n ; i++)
    {
        j = i-1;
        x = A[i];
        while( j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(){
    int A[] = {4,6 ,10 , 5 ,7 , 15 , 8};
    insertionSort(A ,7);
    for(int i=0 ; i<7 ; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}