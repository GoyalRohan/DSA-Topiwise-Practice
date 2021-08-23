#include<iostream>
using namespace std;

struct MATRIX{
    int  *A;
     int n;
};

void Set(MATRIX *m , int i, int j , int x)
{
    if(i-j == 1)
        m->A[i-2] = x;              
    else if(i-j == 0)
        m->A[m->n-1+i-1] = x; 
    else if(i-j == -1)
        m->A[2*(m->n) - 1 +i-1] = x; 
    
}

int Get(MATRIX m , int i , int j)
{
    if(i-j == 1)
        return m.A[i-2] ;              
    else if(i-j == 0)
        return m.A[m.n-1+i-1] ; 
    else if(i-j == -1)
        return m.A[2*(m.n) - 1 +i-1] ; 
    
    else
        return 0;
}

void Display(MATRIX m)
{
    for(int i = 1 ; i<=m.n ; i++)
    {
        for(int j=1 ; j<=m.n ; j++)
        {
            if(i-j == 1)
                cout<<m.A[i-2]<<" " ;              
            else if(i-j == 0)
                 cout<<m.A[m.n-1+i-1]<<" " ; 
            else if(i-j == -1)
                 cout<<m.A[2*(m.n) - 1 +i-1]<<" " ; 
    
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
    m.A = new int[3*(m.n)-2];
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