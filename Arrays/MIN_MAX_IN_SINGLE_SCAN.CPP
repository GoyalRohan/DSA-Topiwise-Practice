#include<iostream>
using namespace std;

int main(){
    const int n = 10;
    int A[n] = {5,8,3,9,6,2,10,7,-1,4};
    int min = A[0];
    int max = A[0];
    for(int i = 0 ; i<n; i++)
    {
        if(A[i]<min)
            min = A[i];
        else if(A[i]>max)
            max = A[i];
    }
    cout<<endl<<"the maximum element is :"<<max;
    cout<<endl<<"the minimum element is :"<<min;

    return 0;
}