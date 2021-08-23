#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *first  =NULL ;

void create(int A[] , int n)
{
    //CREATING THE FIRST NODE
    node *last , *t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    //CREATING THE OTHER NODE
    for(int i=1 ; i<n ;i++)
    {
        t = new node;
        t->data=A[i];
        t->next =NULL;
        last->next =t;
        last = t;
    }
}

void display(node *P)
{
    if(P != NULL)
    {
        cout<<P->data<<"  ";
        display(P->next);
    }
}


//USING ITERATIVE VERSION
int max(node *P)
{
    int m =0;
    while(P != NULL)
    {
        if(P->data > m)
        {
            m = P->data;
        }
        P = P->next;
    }
    return m;
}


//USING RECURSIVE VERSION
int Rmax(node *P)
{
    int m =0;
    if(P == 0)
        return 0;
    else
    {
        m = Rmax(P->next);
        if(m>P->data)
            return m;
        else
            return P->data;
    }
}

int main(){
    int A[] = {2 , 3,4,8,4 , 10 , 12 , 15};
    create(A  ,8);
    
    display(first);
    cout<<"\nthe maximum element of the linked list is:"<<Rmax(first);
   
    return 0;
}