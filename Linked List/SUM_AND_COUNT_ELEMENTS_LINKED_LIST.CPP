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

//ITERATIVE VERSION
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

//RECURSIVE VERSION
int Rcount(node *P)
{
    if(P == 0)
        return 0;
    else
        return Rcount(P->next) + 1;
}


int Add(node *P)
{
    int sum =0;
    while(P)
    {
        sum = sum + P->data;
        P=P->next;
    }
    return sum;
}

int RAdd(node *P)
{
    if(P != NULL)
        return RAdd(P->next) + P->data;
}

int main(){
    int A[] = {2 , 3,4,8,4 , 10 , 12 , 15};
    create(A  ,8);
    display(first);
    // cout<<endl<<"the no of nodes in the linked list are:"<<count(first);
    cout<<endl<<"the no of nodes in the linked list are:"<<Rcount(first);
    // cout<<endl<<"the sum of elements in the linked list are:"<<Add(first);
    cout<<endl<<"the sum of elements in the linked list are:"<<RAdd(first);
   
    return 0;
}