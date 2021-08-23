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


int isLOOP(node *f)
{
   node *p ,*q;
   p = q = f;
   do
   {
       p = p->next;
       q = q->next;
       if(q)
        q = q->next;
   } while (p && q && p!=q);

   if(p == q)
   {
        cout<<"linked list contains loop"<<endl;
        return 1;
   }
    
   else
        cout<<"linked list doesnot contain loop";
        return 0;
}

int main()
{
    int A[] = {10, 20, 60, 40, 50};
    create(A, 5);

    node *t1 , *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    cout<<isLOOP(first);


    return 0;
}