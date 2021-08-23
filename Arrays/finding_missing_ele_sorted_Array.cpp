#include<iostream>
using namespace std;

int main(){
    const int n = 11;
    int A[n] = {6,7,8,9,11,12,15,16,17,18,19};
    int l = A[0];
    int h = A[n-1];

    int diff = A[0] - 0;
    for(int i = 0; i<n ; i++)
    {
        if( A[i] - i != diff)
        {
            while(diff<A[i] - i)
            {
                cout<<i + diff<<endl;

                diff++;
            }
        }
    }
    return 0;
}