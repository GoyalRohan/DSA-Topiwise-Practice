#include <iostream>
using namespace std;

class RADIX
{
    int data;
    RADIX **top;
    RADIX *next;

public:
    RADIX();
    void INSERT(int, int);
    int DELETE(int);
    bool CHECK(int);
};

RADIX::RADIX()
{
    top = new RADIX *[10];
    for (int i = 0; i < 10; i++)
        top[i] = NULL;
}

void RADIX::INSERT(int x, int p)
{
    next = new RADIX;
    next->data = x;
    next->next = NULL;
    if (top[p] == NULL)
        top[p] = next;
    else
    {
        RADIX *t = top[p];
        while (t->next)
            t = t->next;
        t->next = next;
    }
}

int RADIX::DELETE(int p)
{
    int d = top[p]->data;
    next = top[p]->next;
    delete top[p];
    top[p] = next;
    return d;
}

bool RADIX::CHECK(int x)
{
    if (top[x] == NULL)
        return false;
    return true;
}

int main()
{
    int n, i, max, c = 0, j, p = 1, k;
    RADIX R;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    while (max != 0)
    {
        c++;
        max /= 10;
    }
    i = 0;
    while (i < c)
    {
        k = 0;
        for (j = 0; j < i; j++)
            p *= 10;
        for (j = 0; j < n; j++)
        {
            R.INSERT(a[j], (a[j] / p) % 10);
        }
        for (j = 0; j < 10; j++)
        {
            while (R.CHECK(j))
            {
                a[k++] = R.DELETE(j);
            }
        }
        i++;
    }
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}