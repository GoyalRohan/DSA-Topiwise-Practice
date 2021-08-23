#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

void create2(int A[], int n)
{
    //CREATING THE FIRST NODE
    node *last, *t;
    second = new node;
    second->data = A[0];
    second->next = NULL;
    last = second;

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

void merge(node *p, node *q)
{
    node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {15, 25, 35, 45, 55};

    create(A, 5);
    Rdisplay(first);
    cout<<endl;

    create2(B, 5);
    Rdisplay(second);
    cout<<endl;

    merge(first, second);
    Rdisplay(third);
    cout<<endl;

    return 0;
}