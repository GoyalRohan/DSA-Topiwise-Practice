#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*top = NULL;

void push(int x)
{
    node *t = new node;
    if(t == NULL)
        cout<<"Stack overflow";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    node *p ;
    if(top == NULL)
        cout<<"Stack underflow";
    else
    {
        p= top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

void display()
{
    node *p = top;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    cout<<pop();

    cout<<endl;

    display();
    
    return 0;
}
