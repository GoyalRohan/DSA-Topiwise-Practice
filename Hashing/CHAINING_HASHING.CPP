#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void sortedInsert(node **H, int key)
{
    node *q = NULL, *t, *p = *H;

    t = new node;
    t->data = key;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }

        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

node *search(node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
            p = p->next;
    }

    return NULL;
}

int Hash(int key)
{
    return key % 10;
}

void insert(node *H[], int key)
{
    int index = Hash(key);
    sortedInsert(&H[index], key);
}

int main()
{
    node *HT[10];
    node *temp;

    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }


    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    insert(HT, 35);

    temp = search(HT[Hash(21)], 21);
    if(temp != NULL)
        cout << temp->data;
    else
        cout<<"NULL";

    return 0;
}