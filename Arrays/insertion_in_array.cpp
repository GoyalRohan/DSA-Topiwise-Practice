#include<iostream>
#include<stdio.h>
using namespace std;

struct Asray 
{
    int A[10];
    int size;
    int length;
};

void display(struct Asray arr)
{
    int i;
    cout<<"/nthe elements are:";
    for(i = 0 ; i<arr.length ; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

void append(struct Asray *arr , int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++] = x;
        
}

void insert(struct Asray *arr , int index , int x)
{
    if(index>=0 && index<=arr->length)
    {
        for (int i = arr->length ; i>index ; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] =x;
        arr->length++;
        
    }
}



int main(){
    struct Asray arr1 = {{2,3,4,5,6} ,10 , 5};
    append(&arr1 , 10);
    insert(&arr1 , 0 , 12);
    display(arr1);
    return 0;
}