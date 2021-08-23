#include<iostream>
using namespace std;

void sellSort(int A[] , int n)
{
    int gap , i , j , temp;
    for(gap = n/2 ; gap >= 1 ; gap = gap/2)
    {
        for(i = gap ; i<n ; i++)
        {
            temp = A[i];
            j = i-gap;
            while(j>= 0 && A[j] > temp)
            {
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main(){
    int A[] = {4,6 ,10 , 5 ,7 , 15 , 8};
    sellSort(A ,7);
    for(int i=0 ; i<7 ; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}