 #include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char data;
    node *next;
}*top = NULL;

void push(char x)
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

char pop()
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

int isBalanced(string exp)
{
    for(int i=0 ; exp[i] != '\0' ; i++)
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(top == NULL)
        return 1;
    else
        return 0;
}

int main(){
    
    string exp = "((a+b)*(c*d))";
    cout<<isBalanced(exp);
    
    return 0;
}
