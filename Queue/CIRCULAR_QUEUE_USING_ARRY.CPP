#include<iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(queue *q)
{
    cout<<"Enter the size of queue : ";
    cin>>q->size;
    q->front = q->rear = 0;

    q->Q = new int[q->size];
}

void enqueue(queue *q , int x)
{
    if((q->rear+1)%q->size == q->front)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(queue *q)
{
    int x=-1;
    if(q->rear == q->front)
        cout<<"Queue is empty"<<endl;
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}


void display(queue q)
{
    int i;
    i = q.front + 1;
    do
    {
        cout<<q.Q[i]<<endl;
        i = (i+1)%q.size;
    } while (i != (q.rear+1)%q.size);
    cout<<endl;
    
}

int main(){
    
    queue q;
    create(&q);
    enqueue(&q , 10);
    enqueue(&q , 20);
    enqueue(&q , 30);
    enqueue(&q , 40);

    display(q);

    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl<<endl;

    display(q);

    return 0;
}