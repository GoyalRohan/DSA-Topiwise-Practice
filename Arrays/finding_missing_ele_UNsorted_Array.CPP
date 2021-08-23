#include<iostream>
using namespace std;

int main(){
    const int n = 10;
    int A[n] = {3,7,4,9,12,6,1,11,2,10};
    int l =1 , h= 12;
    int *H = new int[h];

    for(int i =0;i<n ; i++)
    {
        H[A[i]]++;
    }

    for(int i = l; i<=h ; i++)
    {
        if(H[i] == 0)
        cout<<endl<<i;
    }
    return 0;
}