#include<iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *S;
};

void create(stack *st )
{
    cout<<"Enter the size of an stack:";
    cin>>st->size;
    st->top = -1;

    st->S = new int[st->size];
}

void display(stack st)
{
    for(int i=st.top ; i>=0 ; i-- )
    {
        cout<<st.S[i]<<endl;
    }
    cout<<endl;
}

void push(stack *st , int x)
{
    if(st->top == st->size-1)
        cout<<"Stack overflow\n";
    else
    {
    st->top++;
    st->S[st->top]= x;
    }
}

int pop(stack *st)
{
    int x =-1;
    if(st->top == -1)
        cout<<"Stack underflow\n";
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(stack st , int index)
{
    int x=-1;
    if(st.top - index +1 <0)
        cout<<"\nInvalid index";
    else
        x = st.S[st.top - index +1];

    return x;
}

int stacktop(stack st)
{
    if(st.top != -1)
    {
        return st.S[st.top];
    }

    return -1;
}

int isFull(stack st)
{
    if(st.top != -1)
    {
        if(st.top == st.size-1)
        return 1;
    }
    return 0;
}

int isEmpty(stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}


int main(){
    
    stack st;
    create(&st);

    push(&st , 10);
    push(&st , 20);
    push(&st , 30);
    push(&st , 40);

    cout<<endl;
    display(st);

    // cout<<endl<<pop(&st)<<endl<<endl;
    
    // cout<<peek(st , 2);

    cout<<stacktop(st);
    return 0;
}