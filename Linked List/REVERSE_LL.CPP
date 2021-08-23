#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *first  =NULL ;

void create(int A[] , int n)
{
    //CREATING THE FIRST NODE
    node *last , *t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    //CREATING THE OTHER NODE
    for(int i=1 ; i<n ;i++)
    {
        t = new node;
        t->data=A[i];
        t->next =NULL;
        last->next =t;
        last = t;
    }
}

void display(node *P)
{
    if(P != NULL)
    {
        cout<<P->data<<"  ";
        display(P->next);
    }
}

int count(node *P)
{
    int l =0;
    while(P != 0)
    {
        l++;
        P=P->next;
    }
    return l;
}


//REVERSING ELEMENTS OF THE NODES OF LINKED LIST USING ARRAYS
void Reverse1(node *p)
{
    int *A ,i=0;
    A= new int[count(p)];
    while(p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while(p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}


// REVERSING THE LINKS USING SLIDING POINERS
void Reverse2(node *p)
{
    node *q = NULL , *r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}


//REVERSING THE LINKED LIST USING RECURSION
void Reverse3(node *q , node *p)
{
    if(p != NULL)
    {
        Reverse3(p , p->next);
        p->next = q;
    }
    else
        first = q;
}




int main(){
    int A[] = {10 , 20 , 30 , 40 , 50};
    create(A  ,5);
    display(first);

    Reverse3(NULL , first);
    cout<<endl<<"linked list after reversing"<<endl;
    display(first);


}