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

int get(Array arr , int index)
{
    if(index>0 && index<arr.length)
        return arr.A[index];
}

void set(Array *arr , int index , int x)
{
    if(index>0 && index<arr->length)
        arr->A[index] = x;
}

int max(Array arr )
{
    int max = arr.A[0];
    for(int i = 1; i<arr.length ; i++)
    {
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}

int sum(Array arr)
{
    int total = 0;
    for (int i = 0 ; i<arr.length ; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}

int avg(Array arr)
{
    int total = 0;
    for (int i = 0 ; i<arr.length ; i++)
    {
        total = total + arr.A[i];
    }
    return total/arr.length;
}


int main(){
    Array arr1 = {{1,2,3,4,5,6},5 ,5 };
    cout<<endl<<get(arr1 , 3)<<endl;
    set(&arr1 ,2,45);
    Display(arr1);
    cout<<endl<<max(arr1);
    cout<<endl<<sum(arr1);
    cout<<endl<<avg(arr1);

    return 0;
}