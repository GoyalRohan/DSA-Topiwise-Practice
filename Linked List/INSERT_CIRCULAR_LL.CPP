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

void Insert(node *p , int index , int x)
{
    if(index<0 || index >length(head))
        return;
    node *t , *q;
    if(index == 0)
    {
        t = new node;
        t->data = x;
        if(head == NULL)
        {
            head =t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
            {
                p = p->next;
            }
            t= new node;
            t->data = x;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(int i=0 ; i<index-1 ; i++)
        {
            p = p->next;
        }
        t = new node;
        t->data = x;
        t->next = p->next;
        p->next =t;
    }
    
}

int main()
{
    int A[] = {10, 20, 60, 40, 50};
    create(A, 5);

    cout<<"displaying the linked list:\n";
    display(head);
    cout<<endl;

    Insert(head , 4 ,110);
    Insert(head , 7 ,110);                       //THIS DOES NOT DO ANYTHING
    cout<<"after insertion: \n";
    display(head);


    return 0;
}