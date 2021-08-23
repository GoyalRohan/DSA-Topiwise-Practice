#include<iostream>
using namespace std;

int main(){
    const int n = 10;
    int A[n] = {1,3,4,5,6,8,9,10,12,14};
    int k;
    cout<<"enter the sum you want to get:";
    cin>>k;
    int i = 0 , j = n-1;
    while(i<j)
    {
        if(A[i] + A[j] == k)
            {
                cout<<endl<<A[i]<<'+'<<A[j]<<'='<<k;
                i++; j--;
            }
        else if(A[i] + A[j] < k)
            i++;
        else
            j--;

    }
    return 0;
}