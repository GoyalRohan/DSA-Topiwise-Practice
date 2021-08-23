#include<iostream>
using namespace std;

int HasH(int key)
{
    return key%10;
}

int probe(int H[] , int key)
{
    int index = HasH(key);
    int i=0;
    while(H[index + i]%10 != 0)
        i++;
    return (index+i)%10;
}

void insert(int H[] , int key)
{
    int index = HasH(key);
    if(index != 0)
        index = probe(H , key);
    H[index] = key;
}

int search(int H[] , int key)
{
    int index = HasH(key);
    int i=0;

    
    while(H[(index+i)%10] != key)
        i++;

    return (index+i);

}

int main(){
    int H[10] = {0} , key;
    

    insert(H , 12);
    insert(H , 25);
    insert(H , 35);
    insert(H , 36);

    for(int i=0 ; i<10 ; i++)
    {
        cout<<H[i]<<" ";
    }    

    cout<<endl<<endl;
    cout<<search(H , 36);
        
    return 0;
}