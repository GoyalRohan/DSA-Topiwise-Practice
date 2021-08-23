#include <iostream>
using namespace std;

struct deque
{
    int size;
    int front, rear;
    int *arr;
};

void create(deque *q)
{
    cout << "Enter the size of an double ended queue:";
    cin >> q->size;
    q->front = -1;
    q->rear = 0;

    q->arr = new int[q->size];
}

int isEmpty(deque *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

int isFull(deque *q)
{
    if ((q->front == 0 && q->rear == q->size - 1) || q->front == q->rear + 1)
        return 1;
    return 0;
}
void insertFront(deque *q, int x)
{
    if (isFull(q))
        cout << "overflow" << endl;
    else
    {
        if (q->front == -1)
            q->front = q->rear = 0;
        else if (q->front == 0)
            q->front = q->size - 1;
        else
            q->front = q->front - 1;

        q->front = x;
    }
}

void insertRear(deque *q, int x)
{
    if (isFull(q))
        cout << "overflow" << endl;
    else
    {
        if (q->front == -1)
            q->front = q->rear = 0;
        else if (q->rear == q->size - 1)
            q->rear = 0;
        else
            q->rear = q->rear + 1;
        ;

        q->arr[q->rear] = x;
    }
}

int deleteFront(deque *q)
{
    int x = -1;
    if (isEmpty(q))
        cout << "underflow" << endl;
    else
    {
        x = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else if (q->front == q->size - 1)
            q->front = 0;
        else
            q->front = q->front + 1;

        
    }

    return x;
}

int deleteRear(deque *q)
{
    int x = -1;
    if (isEmpty(q))
        cout << "underflow" << endl;
    else
    {
        x = q->arr[q->rear];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else if (q->rear == 0)
            q->rear = q->size - 1;
        else
            q->rear = q->rear - 1;
    }

    return x;
}

int main()
{

    deque q;
    create(&q);

    insertRear(&q, 10);
    insertRear(&q, 20);
    insertRear(&q, 30);
    insertRear(&q, 40);

    cout << deleteFront(&q) << endl;
    cout << deleteFront(&q) << endl;
    return 0;
}