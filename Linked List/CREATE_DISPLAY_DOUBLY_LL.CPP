#include<iostream>
using namespace std;

struct node
{
    node *prev ;
    int data;
    node *next;
} ; 
node *first = NULL;

void create(int A[] , int n)
{
    node *t , *last;
    first = new node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(int i=1; i<n ; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int length(node *p)
{
    int len =0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int main(){
    int A[] = {6 , 9, 3 ,7 , 2};
    create(A , 5);

    display(first);
    return 0;
}




