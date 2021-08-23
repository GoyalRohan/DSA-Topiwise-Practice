#include<iostream>
using namespace std;

void selectionSort(int A[] , int n)
{
    int i , j ,k;
    for(i=0 ; i<n-1 ; i++)
    {
        for(j=k=i ; j<n ; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int main(){
    int A[] = {4,6 ,10 , 5 ,7 , 15 , 8};
    selectionSort(A ,7);
    for(int i=0 ; i<7 ; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}