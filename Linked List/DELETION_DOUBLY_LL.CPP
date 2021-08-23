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

int Delete(node *p , int index)
{
    int x = -1;
    if(index <1 || index>length(p))
        return -1;
    
    if(index == 1)
    {
         x  = p->data;
        first = first->next;
        delete p;
        if(first)
            first->prev = NULL;
    }
    else
    {
        for(int i =0 ; i<index-1 ; i++)
        {
            p= p->next;
        }
        p->prev->next = p->next;
        if(p->next != NULL)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main(){
    int A[] = {6 , 9, 3 ,7 , 2};
    create(A , 5);
    display(first);
    
    Delete(first , 1);
    cout<<"\n Displaying linked list after insertion:\n";
    display(first);
    return 0;
}




