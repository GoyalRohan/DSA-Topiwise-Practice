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

void rdisplay(node *h)
{
    static int flag=0;
    if(h != head || flag ==0)
    {
        flag =1;
        cout<<h->data<<" ";
        rdisplay(h->next);
    }
    flag = 0;
}


int main()
{
    int A[] = {10, 20, 60, 40, 50};
    create(A, 5);

    cout<<"displaying the linked list:\n";
    rdisplay(head);


    return 0;
}