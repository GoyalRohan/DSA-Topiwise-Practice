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


void reverse2(Array *arr)
{
    int i , j;
    for(i=0 , j = arr->length - 1; i<j ; i++ , j--)
    {
        swap(&arr->A[i] , &arr->A[j]);
    }
}


// void reverse(Array *arr)
// {
//     int *B;
//     B = new int[arr->length];
//     int i , j;
//     for(i =arr->length-1 , j=0 ; i>=0 ; i-- , j++)
//     {
//         B[j] = arr->A[i];
//     }
//     for(i = 0 ; i<arr->length ; i++)
//     {
//         arr->A[i] = B[i];
//     }
// }

int main(){
    Array arr1 = {{2,3,4,5,6,7,8,9} ,10 ,8};
    // reverse(&arr1);
    reverse2(&arr1);
    Display(arr1);
    return 0;
}