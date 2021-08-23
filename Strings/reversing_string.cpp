#include<iostream>
using namespace std;

int main(){
    char A[]="python";

    //FIRST METHOD

    // char B[7];
    // int i;
    // for( i =0; A[i]!= '\0' ; i++)
    // {}
    // i = i-1; int j;
    // for(j = 0;i>=0 ; i-- , j++)
    // {
    //     B[j] = A[i];
    // }
    // B[j]= '\0';
    // cout<<B;


    //SECOND METHOD

    int i , j;
    for(j = 0;A[j]!='\0' ; j++)
    {}
    j=j-1;
    for(i=0;i<j ; i++ , j--)
    {
        char t;
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout<<A;
    return 0;
}