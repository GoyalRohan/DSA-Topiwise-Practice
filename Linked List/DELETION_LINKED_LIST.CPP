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

int Delete(node *p, int index)
{
    node *q = NULL;
    int x = -1, i;

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    cout << Delete(first, 2)<<endl;
    Rdisplay(first);

    return 0;
}