#include<iostream>
using namespace std;

//NOT EXECUTED PROPERLY 

struct MATRIX{
    int  *A;
     int n;
};

void Set(MATRIX *m , int i, int j , int x)
{
    if(i<=j)
        m->A[j-1] = x;
    else if(i>j)
        m->A[m->n+i-j-1];
            
}

int Get(MATRIX m , int i , int j)
{
   if(i<=j)
       return  m.A[j-1];
    else if(i>j)
        return m.A[m.n+i-j-1];
}

void Display(MATRIX m)
{
    for(int i = 1 ; i<=m.n ; i++)
    {
        for(int j=1 ; j<=m.n ; j++)
        {
            if(i<=j)
                 cout<< m.A[j-1];
            else if(i>j)
                cout<<m.A[m.n+i-j-1];
        }
        cout<<endl;
    }
}

int main(){
    MATRIX m;
    int x;
    cout<<"ENTER THE DIMENSION\n";
    cin>>m.n;
    m.A = new int[ 2*(m.n) -1];
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

    // cout<<Get(m , 1 , 3);
    return 0;
}