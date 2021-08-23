#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size; 
    int length;
};

void Display(Array arr)
{
    for(int i = 0; i<arr.length ; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

void swap(int *x , int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


//IMPROVED LINEAR SEARCH USING MOVE TO FRONT METHOD
int Linearsearch(Array *arr , int key)
{
    for(int i = 0 ; i<arr->length ; i++)
    {
        if(arr->A[i] == key)
        {
            swap(arr->A[i] , arr->A[0]);
            return 0;
        }
    }
    return -1;
}


// IMPROVED LINEAR SEARRCH USING TRANSPOSITION METHOD
// int Linearsearch(Array *arr , int key)
// {
//     for(int i = 0 ; i<arr->length ; i++)
//     {
//         if(arr->A[i] == key)
//         {
//             swap(arr->A[i] , arr->A[i-1]);
//             return i-1;
//         }
//     }
//     return -1;
// }


// FOR SIMPLE LINEAR SEARCH
// int Linearsearch(Array arr , int key)
// {
//     for(int i = 0 ; i<arr.length ; i++)
//     {
//         if(arr.A[i] == key)
//             return i;
//     }
//     return -1;
// }


int main(){
    Array arr1 = {{2,23 , 14 , 5 , 6,9,8, 12},10 ,8 };
    // cout<<Linearsearch(arr1 , 5)<<endl;               //FOR SIMPLE LINEAR SEARCH
    // cout<<Linearsearch(&arr1 , 23)<<endl;           //FOR IMPROVED LINEAR SEARCH USING TRANSPOSITION METHOD
    cout<<Linearsearch(&arr1 , 14)<<endl;             //FOR IMPROVED LINEAR SEARCH USING MOVE TO FRONT METHOD
    Display(arr1);
    return 0;
}