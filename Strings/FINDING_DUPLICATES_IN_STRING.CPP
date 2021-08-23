#include<iostream>
using namespace std;

int main(){

    //IN THIS HASHING TABLE IS USED
    char A[] = "finding";
    int H[26] = {0};
    for(int i=0;A[i]!= '\0'; i++)
    {
        H[A[i]-97]++;
    }
    for(int i=0 ; i<26 ;i++)
    {
        if(H[i]>1)
            cout<<endl<<char(97+i)<<" is repeating for "<<H[i]<<"times";
    }

    return 0;
}

//WE CAN ALSO DO THIS LIKE WE HAVE FOUND DUPLICATES IN ARRAY