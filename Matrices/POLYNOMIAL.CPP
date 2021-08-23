#include<iostream>
using namespace std;

struct terms
{
    int coff;
    int exp;
};

struct poly
{
    int n;
    terms *t;
};

void create(poly *P)
{
    cout<<"enter the no of terms:";
    cin>>P->n;
    P->t = new terms[P->n];
    for(int i=0 ; i<P->n ; i++)
    {
        cin>>P->t[i].coff>>P->t[i].exp;
    }
}

void display(poly P)
{
    for(int i =0 ; i<P.n ; i++)
    {
        cout<<P.t[i].coff<<"x"<<P.t[i].exp<<" + ";
    }
}

poly * add(poly *P1 , poly *P2)
{
    int i , j, k;
    i = j = k =0;
    poly *sum ; 
    sum  = new poly;
    sum->t = new terms[P1->n + P2->n];

    while(i<P1->n && j<P2->n)
    {
        if(P1->t[i].exp>P2->t[j].exp)
            sum->t[k++]=P1->t[i++];
        else if(P1->t[i].exp < P2->t[j].exp)
            sum->t[k++]=P2->t[j++];
        else
        {
            sum->t[k].exp=P1->t[i].exp;
            sum->t[k++].coff=P1->t[i++].coff+P2->t[j++].coff;
        }
    }
    for(;i<P1->n;i++)sum->t[k++]=P1->t[i];
    for(;j<P2->n;j++)sum->t[k++]=P2->t[j];
 
    sum->n=k;
    return sum;
}


int main(){
    poly P1 , P2 ,  *P3;
    create(&P1);
    create(&P2);
    
    P3 = add(&P1 , &P2);

    cout<<endl;
    display(P1);

    cout<<endl;
    display(P2);


    cout<<endl;
    display(*P3);

    return 0;
}