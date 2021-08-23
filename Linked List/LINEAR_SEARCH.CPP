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


//ITERATIVE LINEAR SEARCH
node * Lsearch(node *P , int key)
{
    while(P != NULL)
    {
        if(P->data == key)
        {
            return P;
        }
        P = P->next;

    }
    return NULL;

}


//RECURSIVE LINEAR SEARCH
node * Rsearch(node *P , int key)
{
    if(P == NULL)
        return 0;
    if(P->data == key)
        return P;
    return Rsearch(P->next , key);
}


//IMPROVED LINEAR SEARCH USING MOVE TO FRONT METHOD
node * move_search(node *P , int key)
{
    node *Q = NULL;
    while(P != NULL)
    {
        if(P->data == key)
        {
            Q->next = P->next;
            P->next = first;
            first = P;
            return P;
        }
        Q = P;
        P = P->next;

    }
    return NULL;
}


int main(){
    node *temp;
    int A[] = {2 , 3,4,8,4 , 10 , 12 , 15};
    create(A  ,8);
    temp = move_search(first , 4);
    temp = move_search(first , 15);
    if(temp != NULL)
    {
        cout<<"\nthe key element is found "<<temp->data<<endl;
    }
    else
        cout<<"\nthe key element is not found";

    display(first);
    
   
    return 0;
}