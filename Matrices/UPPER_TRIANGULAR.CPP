#include<iostream>
using namespace std;

struct MATRIX{
    int  *A;
     int n;
};

void Set(MATRIX *m , int i, int j , int x)
{
    if(i<=j)
    {
        m->A[m->n*(i-1) + (i-2)*(i-1)/2 + j-i] = x;         //FOR ROW MAJOR
        // m->A[j*(j-1)/2 + i-1]<<" ";     //FOR COLUMN MAJOR
    }
}

int Get(MATRIX m , int i , int j)
{
    if(i <= j)
        return m.A[m.n*(i-1) + (i-2)*(i-1)/2 + j-i];           //FOR ROW MAJOR
        // return m.A[j*(j-1)/2 + i-1];     //FOR COLUMN MAJOR
    else
        return 0;
}

void Display(MATRIX m)
{
    for(int i = 1 ; i<=m.n ; i++)
    {
        for(int j=1 ; j<=m.n ; j++)
        {
            if(i <= j)
                cout<<m.A[m.n*(i-1) + (i-2)*(i-1)/2 + j-i]<<" ";     //FOR ROW MAJOR
                // cout<<m.A[j*(j-1)/2 + i-1]<<" ";     //FOR COLUMN MAJOR
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

int main(){
    MATRIX m;
    int x;
    cout<<"ENTER THE DIMENSION\n";
    cin>>m.n;
    m.A = new int[m.n*(m.n+1)/2];
    cout<<"enter all elements:";
    for(int i =1 ; i<=m.n ;i++)
    {
        for(int j =1 ;j<=m.n ; j++)
        {
            cin>>x;
            Set(&m , i , j , x);
        }
    }

    Display(m);

    cout<<Get(m , 1 , 3);
    return 0;
}