#include<iostream>
using namespace std;

struct MATRIX{
    int A[10];
    int n;
};

void Set(MATRIX *m , int i, int j , int x)
{
    if(i==j)
        m->A[i-1] = x; 
}

int Get(MATRIX *m , int i , int j)
{
    if(i == j)
        return m->A[i-1];
    else
        return 0;
}

void Display(MATRIX m)
{
    for(int i = 0 ; i<m.n ; i++)
    {
        for(int j=0 ; j<m.n ; j++)
        {
            if(i == j)
                cout<<m.A[i]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

int main(){
    MATRIX m;
    m.n = 4;
    Set(&m , 1 ,1 ,5);
    Set(&m , 2 ,2 ,8);
    Set(&m , 3 ,3 ,9);
    Set(&m , 4 ,4 ,6);

    Display(m);

    cout<<Get(&m , 1 , 1);
    return 0;
}