#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*front=NULL , *rear = NULL;

void enqueue(int x)
{
    node *t = new node;
    if(t == NULL)
        cout<<"Queue is full";
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear =t;
        else
        {
            rear->next = t;
            rear =t;
        }
    }
}

int dequeue()
{
    int x=-1;
    if(front == NULL)
        cout<<"queue is empty";
    else
    {
        node *p = front;
        front = front->next;
        x = p->data;
        delete p ;
    }
    return x;
}

void display()
{
    node *p = front;
    while(p)
    {
        cout<<p->data<<"  ";
        p = p->next;
    }
    cout<<endl;

}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
   
  

    display();

    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    
    display();
    return 0;
}