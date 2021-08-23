#include<iostream>
using namespace std;


void Merge(int A[] , int l , int mid , int h)
{
    int i=l , j = mid+1 , k=l;
    int B[100];

    while (i<= mid && j<=h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++]  = A[j++];
    
    }

    for( ; i<=mid ; i++)
        B[k++] = A[i];
    for( ; j<=h ; j++)
        B[k++] = A[j];

    for(int i = l ; i<=h ; i++)
        A[i] = B[i];   
    
}
void RecMergeSort(int A[] , int l , int h)
{
    if(l < h)
    {
        int mid = (l+h)/2;
        RecMergeSort(A , l , mid);
        RecMergeSort(A , mid+1 , h);
        Merge(A , l , mid , h);
    }
}

int main()
{
    int A[10] = {5 , 4 , 8 , 2 , 10 , 13 , 9 , 7 , 15 , 20};
    RecMergeSort(A , 0 , 9);

    for(int i=0 ; i<10 ; i++)
    {
        cout<<A[i]<<" ";
    }
}