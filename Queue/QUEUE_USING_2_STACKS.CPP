#include <iostream>
#include <stack >
using namespace std;

struct queue
{
    stack<int> s1, s2;

    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        int x = -1;
        if (s2.empty())
        {
            if (s1.empty())
                cout << "the queue is empty";
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }

        x = s2.top();
        s2.pop();

        return x;
    }
};

int main()
{

    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}