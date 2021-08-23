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

void Rdisplay(node *P)
{
    if(P != NULL)
    {
        cout<<P->data<<"  ";
        Rdisplay(P->next);
    }
}

void SortedInsert(node *P ,int x )
{
    node *t , *q = NULL;
    t = new node;
    t->data = x;
    t->next=NULL;

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(P && P->data <x)
        {
            q=P;
            P = P->next;
        }
        if(P == first)
        {
            t->next = first;
            first =t;
        }
        else{
            t->next = q->next;
            q->next =t;
        }
    }
}



int main(){
    int A[] = {10 , 20,30 , 40 ,50};
    create(A  ,5);

    SortedInsert(first , 5);
    Rdisplay(first);
    
    
    return 0;
}