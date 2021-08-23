#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
    node(int x){
        data = x;
        prev= next = NULL;
    }
};

node *dummy = new node(-1);
node *head = dummy;
node *mid = dummy;
int cnt = 0;

void push(int data)
{
    node *t = new node(data);
    t->prev = NULL;
    t->next = head;
    cnt++;
    head->prev = t;
    head = t;
    if(cnt == 1)
        mid = t;
    else if(cnt %2 == 0)
            mid = mid->prev;
}

int pop()
{
    if(cnt == 0)
    {
        cout<<"Stack Underflow";
        return 0;
    }
    node *temp = head;
    int x = head->data;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    cnt--;

    if(cnt & 1)
        mid = mid->next;

    delete temp;
    return x;
  
}

int middle()
{
    return mid->data;
}

int main() {
	push(4);
	push(2);
	push(7);
	push(8);
	push(5);
	push(11);

    cout<<middle()<<endl<<endl;

    cout<<pop()<<endl;
    cout<<pop()<<endl;

    cout<<middle()<<endl<<endl;
	return 0;
}