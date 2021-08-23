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

// Array * UNION(Array *arr1 , Array *arr2)
// {
//     int i , j , k;
//     i=j=k=0;
//     Array *arr3 = new Array;
//     while(i<arr1->length && j<arr2->length)
//     {
//         if(arr1->A[i]<arr2->A[j])
//             arr3->A[k++] = arr1->A[i++];
//         else if(arr1->A[i]>arr2->A[j])
//             arr3->A[k++] = arr2->A[j++];

//         else{
//             arr3->A[k] = arr1->A[i];
//             k++ ; i++ ; j++;
//         }
//     }

//     for( ; i<arr1->length ; i++)
//     {
//         arr3->A[k++] = arr1->A[i];
//     }
//     for( ; j<arr2->length ; j++)
//     {
//         arr3->A[k++] = arr2->A[j];
//     }

//     arr3->length =k;
//     arr3->size = 10;

//     return arr3;
// }

// Array * INTERSECTION(Array *arr1 , Array *arr2)
// {
//     int i , j , k;
//     i=j=k=0;
//     Array *arr3 = new Array;
//     while(i<arr1->length && j<arr2->length)
//     {
//         if(arr1->A[i]<arr2->A[j])
//             i++;
//         else if(arr1->A[i]>arr2->A[j])
//             j++;

//         else{
//             arr3->A[k] = arr1->A[i];
//             k++ ; i++ ; j++;
//         }
//     }

//     arr3->length =k;
//     arr3->size = 10;

//     return arr3;
// }


Array * DIFFERENCE(Array *arr1 , Array *arr2)
{
    int i , j , k;
    i=j=k=0;
    Array *arr3 = new Array;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            j++;

        else{
            i++ ; j++;
        }
    }

    for( ; i<arr1->length ; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length =k;
    arr3->size = 10;

    return arr3;
}


int main(){
    Array arr1 = {{2,9,21,28,35} , 10 , 5};
    Array arr2 = {{2,3,16,18,28} , 10 , 5};
    Array *arr3;
    // arr3 = UNION(&arr1 , &arr2);
    // arr3 = INTERSECTION(&arr1 , &arr2);
    arr3 = DIFFERENCE(&arr1 , &arr2);
    Display(arr1);
    Display(arr2);
    Display(*arr3);
    return 0;
}