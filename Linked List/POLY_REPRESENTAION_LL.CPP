#include<iostream>
#include<math.h>
using namespace std;

struct node
{
    int coff;
    int exp;
    node *next;
}*poly=NULL;

void create()
{
    node *t , *last = NULL;
    int num;
    cout<<"Enter the no of terms:";
    cin>>num;
    cout<<endl<<"Enter the terms";
    for(int i= 0 ; i<num ; i++)
    {
        t = new node;
        cin>>t->coff>>t->exp;
        t->next = NULL;
        if(poly == NULL)
            poly = last =t;
        else
        {
            last->next =t;
            last =t;
        }
    }
}

void display(node *p)
{
    while(p!= NULL)
    {
        cout<<p->coff<<'x'<<p->exp<<" + ";
        p=p->next;
    }
}

double eval(node *p , int x)
{
    double sum = 0.0;
    while(p != NULL)
    {
        sum += p->coff*pow(x , p->exp);
        p = p->next;
    }
    return sum;
}

int main(){

    create();
    cout<<"The polynomial is \n";
    display(poly);

    cout<<"\nThe sum is:"<<eval(poly , 1);
    
    return 0;
}