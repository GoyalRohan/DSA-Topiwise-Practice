#include<iostream>
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


int  Delete(struct Asray *arr , int index )
{
    int x =0;
    if(index>=0 && index<=arr->length)
    {
        x=arr->A[index];
        for (int i = index ; i<arr->length ; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
        
    }
}



int main(){
    struct Asray arr1 = {{2,3,4,5,6} ,10 , 5};
    cout<<Delete(&arr1 , 0);
    display(arr1);
    return 0;
}