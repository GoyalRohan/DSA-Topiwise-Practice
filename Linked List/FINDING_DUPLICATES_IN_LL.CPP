#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *first = NULL;

void create(int A[], int n)
{
    //CREATING THE FIRST NODE
    node *last, *t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    //CREATING THE OTHER NODE
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Rdisplay(node *P)
{
    if (P != NULL)
    {
        cout << P->data << "  ";
        Rdisplay(P->next);
    }
}


void duplicate(node *p)
{
    p =first;
    node *q = first->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p =q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    int A[] = {10, 20, 20, 40, 50 , 50 ,50};
    create(A, 7);

    duplicate(first);
    Rdisplay(first);
    cout<<endl;


    return 0;
}