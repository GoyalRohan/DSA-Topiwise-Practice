#include<iostream>
using namespace std;

void bubbleSort(int A[] , int n)
{
    int flag;
    for(int i=0 ; i<n-1 ; i++)
    {
        flag = 0;
        for(int j=0 ; j<n-1-i ; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag =1;
            }
        }

        if(flag == 0)
            break;
    }
}

int main(){
    int A[] = {4,6 ,10 , 5 ,7};
    bubbleSort(A ,5);
    for(int i=0 ; i<5 ; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}