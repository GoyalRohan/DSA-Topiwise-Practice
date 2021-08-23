 #include<iostream>
#include<string.h>
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


int isOperand(char x)
{
    if(x == '+' || x =='-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int Eval(char *postfix)
{
    int i=0 , x1 , x2 , r=0;
    for(i=0 ; postfix[i] !='\0' ; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2 = pop();
            x1 = pop();

            switch (postfix[i])
            {
            case '+':
                r = x1+x2;
                push(r);
                break;
            
            case '-':
                r = x1-x2;
                push(r);
                break;
            
            case '*':
                r = x1*x2;
                push(r);
                break;
            
            case '/':
                r = x1/x2;
                push(r);
                break;
            
            default:
                break;
            }
        }
    }

    return top->data;
}

int main(){
    
    char *postfix = "23+";
    cout<<"The result of the postfix expression is:"<<Eval(postfix)<<endl;;
    
    
    return 0;
}
