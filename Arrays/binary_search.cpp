#include<iostream>
using namespace std;

struct Array 
{
    int A[10];
    int size;
    int length;
};


void Display(Array arr)
{
    cout<<endl;
    for(int i = 0; i<arr.length ; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

// ITERATIVE VERSION
// int Binsearch(Array arr , int key)
// {
//     int l = 0 , h = arr.length - 1;
//     int mid;
//     while(l<=h)
//     {
//         mid = (l+h)/2;
//         if(key == arr.A[mid])
//             return mid;
//         else if(key<arr.A[mid])
//             h = mid - 1;
//         else 
//             l = mid+1;
//     }
//     return -1;
// }

//RECURSIVE VERSION
int RBinsearch(int A[] ,int l , int h, int key )
{
    int mid = 0;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key<A[mid])
            return RBinsearch(A , l , mid-1 , key);
        else 
           return RBinsearch(A , mid + 1 , h , key); 
    }
    return -1;
}


int main(){
    Array arr1 = {{1,2,3,4,5,6,7,8,9,10} ,10 , 10};
    // cout<<Binsearch(arr1 , 5);
    cout<<RBinsearch(arr1.A , 0 , arr1.length-1 , 8);
    Display(arr1);
    return 0;
}