// #include<iostream>
// using namespace std;

// //TO INSERT AN ELEMENT IN THE HEAP
// void Insert(int arr[] , int len)
// {
//     int i=len;
//     int temp = arr[len];
//     while(i>1 && temp > arr[i/2])
//     {
//         arr[i] = arr[i/2];
//         i = i/2;

//     }
//     arr[i] = temp;

// }

// //  TO CREATE THE HEAP 
// void Create(int arr[] , int len)
// {

//     for(int i=2 ; i<=len ; i++)
//     {
//         Insert(arr , i);
//     }
// }

// // TO DELETE AN ELEMENT FROM THE HEAP
// // WE CAN ONLY DELETE THE ROOT ELEMENT(GREATEST) FROM THE MAX HEAP AND ROOT ELEMENT(SMALLEST) FROM   THE MIN HEAP 
// int Delete(int arr[] , int len)
// {
//     int i , j , temp , x , val;
//     x = arr[len];
//     val = arr[1];
//     arr[1] = arr[len];
//     i = 1; j = 2*i ; 

//     while(j<len-1)
//     {
//         if(arr[j+1] > arr[j])
//             j +=1 ;
        
//         if(arr[i] < arr[j])
//         {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             i=j;
//             j = 2*j;
//         }
//         else
//             break;
//     }
//     arr[len] = val;
    
//     return val;
// }

// // TO DISPLAY THE HEAP
// void Display(int arr[] , int len)
// {
//     for(int i=1 ; i<len ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }


// int main(){
    
//     int arr[] = {0 , 10 , 20 , 30 ,25 ,  5 ,40 , 35};
//     int len = sizeof(arr)/sizeof(arr[0]);

//     Create(arr , len);
//     Display(arr , len); 

//     // cout<<"\nThe deleted value is:"<<Delete(arr , len-1)<<endl;
//     // cout<<"\nThe deleted value is:"<<Delete(arr , len-2)<<endl;
//     // cout<<"\nThe deleted value is:"<<Delete(arr , len-3)<<endl;
//     // cout<<"\nThe deleted value is:"<<Delete(arr , len-4)<<endl;
//     // cout<<"\nThe deleted value is:"<<Delete(arr , len-5)<<endl;
//     // cout<<"\nThe deleted value is:"<<Delete(arr , len-6)<<endl;

//     for(int i=len-1 ; i>=1 ; i--)
//     {
//         cout<<"The deleted value is : "<<Delete(arr , i)<<endl;
//     }
   
//     Display(arr , len); 
//     return 0;
// }

#include<iostream>
using namespace std;


int main(){
    int arr[] = {0 , 10 , 20 , 30 ,25 ,  5 ,40 , 35};
    int len = sizeof(arr)/sizeof(arr[0]);

    return 0;
}