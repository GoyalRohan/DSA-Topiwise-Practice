#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = NULL;

void create(int A[], int n)
{
    node *t , *last;
    //CREATING THE FIRST NODE
    head = new node;
    head->data = A[0];
    head->next = head;
    last = head;

    //CREATING THE OTHER NODE
    for(int i=1; i<n ; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    
}

void display(node *h)
{
   do
   {
       cout<<h->data<<" ";
       h = h->next;
   }while(h!= head );
}

int length(node *p)
{
    int len =0;
    do
    {
        len++;
        p = p->next;

    } while (p != head);
    return len;
}

int Delete(node *p , int index)
{
    node *q;
    int x;

    if(index<1 || index>length(head))
        return -1;
    if(index == 1)
    {
        while(p->next != head)
            p = p->next;
        x = head->data;
        if(p == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for(int i = 0 ; i<index-2 ; i++)
            p = p->next;
        q=p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int A[] = {10, 20, 60, 40, 50};
    create(A, 5);

    cout<<"displaying the linked list:\n";
    display(head);
    cout<<endl;

    cout<<Delete(head , 3);
    cout<<endl;             
    cout<<"after deletion: \n";
    display(head);


    return 0;
}