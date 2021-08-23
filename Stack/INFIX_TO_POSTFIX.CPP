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


int isOperand(char x)
{
    if(x == '+' || x =='-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*')
        return 2;
    else if(x == '/')
        return 2;
    else
        return 0;
}

char * intoPost(char  *infix)
{
    int i=0, j=0;
    char * postfix;
    int len = strlen(infix);
    postfix = new char[len+2];

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }

    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix;

    postfix = intoPost(infix);

    cout<<endl<<postfix;
   
    return 0;
}
