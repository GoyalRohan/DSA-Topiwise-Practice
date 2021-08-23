#include<iostream>
using namespace std;


struct Array{
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

void swap(int *x , int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//TO INSERT AN ELEMENT IN THE SORTED ARRAY
// void Insertion(Array *arr , int x)
// {
//     int i = arr->length-1;
//     if(arr->length == arr->size)
//         return;
//     while (i>= 0 && arr->A[i]>x)
//     {
//         arr->A[i + 1] = arr->A[i];
//         i--;
//     }
//     arr->A[i+1] = x;
//     arr->length++;
    
// }


//TO CHECK WHETHER THE ARRAY IS SORTED OR NOT
// int IsSorted(Array arr)
// {
//     for(int i = 0 ; i<arr.length - 1 ; i++)
//     {
//         if(arr.A[i]>arr.A[i+1])
//             return false;
//     }
//     return true;
// }


//TO SHIFT ALL THE NEGETIVE ELEMENTS TO THE LEFT AND AND ALL THE POSITIVE ELEMENTS TO RIGHT
void Shift_neg(Array *arr)
{
    int i = 0;
    int j = arr->length -1;
    while(i<j)
    {
        while(arr->A[i]<0)
        {i++;}
        
        while(arr->A[j]>=0)
        {j--;}

        if(i<j)
            swap(&arr->A[i] , &arr->A[j]);

    }
}


int main(){
    Array arr1 = {{-1 , 4 , -5 , 7 ,-10 , 6} , 10 ,6 };
    // Insertion(&arr1 , 20);
    // cout<<IsSorted(arr1);
    Shift_neg(&arr1);
    Display(arr1);
    return 0;
}