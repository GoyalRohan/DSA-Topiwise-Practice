#include<iostream>
using namespace std;

struct element{
    int i;
    int j;
    int x;
};

struct sparse{
    int m;
    int n;
    int num;
    element *ele ;
};

void create(sparse *S)
{
    int i;
    cout<<"enter the dimensions:";
    cin>>S->m>>S->n;
    cout<<endl<<"enter the no of non zero elements:";
    cin>>S->num;
    S->ele = new element[S->num];
    cout<<"enter all the elements:";
    for(i = 0; i<S->num ; i++)
    {
        cin>>S->ele[i].i>>S->ele[i].j>>S->ele[i].x;
    }
}

void display(sparse S)
{
    int i , j ,k =0;
    for(i=0 ; i<S.m ; i++)
    {
        for(j = 0; j<S.n ; j++)
        {
            if(i == S.ele[k].i  && j == S.ele[k].j )
                cout<<S.ele[k++].x<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

sparse * add(sparse *S1 , sparse *S2)
{
    int i , j , k;
    sparse *sum ; 
    i=j=k=0;
    if(S1->m != S2->m && S1->n != S2->n)
        return 0;

    sum = new sparse;
    sum->ele = new element[S1->num + S2->num];
    
    while (i<S1->num && j<S2->num)
    {
        if(S1->ele[i].i < S2->ele[j].i)
            sum->ele[k++]  = S1->ele[i++];
        else if(S1->ele[i].i > S2->ele[j].i)
            sum->ele[k++]  = S2->ele[j++];
        else
        {
            if(S1->ele[i].j < S2->ele[j].j)
                sum->ele[k++]  = S1->ele[i++];
            else if(S1->ele[i].j > S2->ele[j].j)
                sum->ele[k++]  = S2->ele[j++];
            else
            {
                sum->ele[k] = S1->ele[i];
                sum->ele[k++].x = S1->ele[i++].x  + S2->ele[j++].x;
            }
        }
    }

    for( ; i<S1->num ; i++)
        sum->ele[k++] = S1->ele[i];

    for( ; i<S2->num ; j++)
        sum->ele[k++] = S1->ele[j];

    sum->m = S1->m;
    sum->n = S1->n;
    sum->num = k;

    return sum;
    
}

int main(){
    struct sparse S1;
    struct sparse S2;
    struct sparse *S3;

    create(&S1);
    create(&S2);
    S3 = add(&S1 , &S2);

    cout<<endl<<"FIRST MATRIX"<<endl;
    display(S1);

    cout<<endl<<"SECOND MATRIX"<<endl;
    display(S2);

    cout<<endl<<"THIRD MATRIX"<<endl;
    display(*S3);
    return 0;
}