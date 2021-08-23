#include<iostream>
using namespace std;

int main(){
    char A[] = "decimal";
    char B[] = "medical";
    int H[26] = {0};
    for(int i = 0 ; A[i]!=0; i++)
    {
        H[A[i] - 97]++;
    }
    int j;
    for(j = 0 ; B[j]!=0; j++)
    {
        H[A[j] - 97]--;
        if(A[j] - 97 < 0)
            {
                cout<<"strings are not anagram";
                break;
            }
    }
    if(B[j] =='\0')
        cout<<"the strings are anagram";

    return 0;
}