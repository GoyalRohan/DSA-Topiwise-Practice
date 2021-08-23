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

void revdisplay(node *P)
{
    if(P != NULL)
    {
        revdisplay(P->next);
        cout<<P->data<<"  ";
    }
}


int main(){
    int A[] = {2 , 3,4,8,4};
    create(A  ,5);
    Rdisplay(first);
    cout<<endl;
    revdisplay(first);
    return 0;
}