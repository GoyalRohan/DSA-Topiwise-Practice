#include<iostream>
using namespace std;


// NOT EXECUTED PROPERLY

struct MATRIX{
    int  *A;
     int n;
};

void Set(MATRIX *m , int i, int j , int x)
{
    if(i>=j)
    {
        m->A[i*(i-1)/2 + j-1] = x;         
    }
}

int Get(MATRIX m , int i , int j)
{
        return m.A[i*(i-1)/2 + j-1];           
}

void Display(MATRIX m)
{
    for(int i = 1 ; i<=m.n ; i++)
    {
        for(int j=1 ; j<=m.n ; j++)
        {
            if(i >= j)
                cout<<m.A[i*(i-1)/2 + j-1]<<" ";
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

    cout<<Get(m , 2 , 3);
    return 0;
}