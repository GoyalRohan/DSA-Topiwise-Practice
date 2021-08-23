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

void insert(node *P , int index , int x)
{
    node *t;
    t = new node;
    t->data =x;

    if(index == 0)
    {
        t->next = first;
        first = t;   
    }
    else
    {
        for(int i=0; i<index-1 ; i++)
        {
            P = P->next;
        }
        t->next = P->next;
        P->next = t;

    }
}



int main(){
    int A[] = {2 , 3,4};
    create(A  ,3);
    Rdisplay(first);
    cout<<endl;
    insert(first , 2 ,10);
    Rdisplay(first);
    cout<<endl;
    insert(first , 0 ,20);
    Rdisplay(first);
    
    return 0;
}