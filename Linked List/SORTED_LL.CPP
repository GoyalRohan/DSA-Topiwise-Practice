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


int isSorted(node *P)
{
    int x=-32867;
    while(P != NULL)
    {
        if(P->data < x)        
            return false;
        x = P->data;
        P = P->next;

    }
    return true;
}

int main()
{
    int A[] = {10, 20, 60, 40, 50};
    create(A, 5);

    Rdisplay(first);
    cout<<endl;
    cout<<isSorted(first);


    return 0;
}