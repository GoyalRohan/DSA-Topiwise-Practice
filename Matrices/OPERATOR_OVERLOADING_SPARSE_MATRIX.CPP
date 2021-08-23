#include<iostream>
using namespace std;


class element{
public:
    int i;
    int j;
    int x;
};

class sparse{
    private :
        int m;
        int n;
        int num;
        element *ele ;

    public:
        sparse(int m , int n , int num)
        {
            this->m  = m;
            this->n  = n;
            this->num  = num;
            ele = new element[this->num];
        }

        ~sparse()
        {
            delete [] ele;
        }

        sparse operator+(sparse &s);
        friend istream & operator>>(istream &is , sparse &s);
        friend ostream & operator<<(ostream &os , sparse &s);
};


istream & operator>>(istream &is , sparse &s)
{
    cout<<"enter the non zero elements:";
    for(int i =0;i<s.num ;i++)
    {
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    }
    return is;

}

ostream & operator<<(ostream &os , sparse &s)
{
    int i , j ,k =0;
    for(i=0 ; i<s.m ; i++)
    {
        for(j = 0; j<s.n ; j++)
        {
            if(i == s.ele[k].i  && j == s.ele[k].j )
                cout<<s.ele[k++].x<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    return os;
}


sparse sparse :: operator+(sparse &s)
{
    int i , j , k;
    sparse *sum ; 
    i=j=k=0;
    if(m != s.m && n != s.n)
        return sparse(0 , 0, 0);

    sum = new sparse(m, n , num+s.num);
    
    while (i<num && j<s.num)
    {
        if(ele[i].i < s.ele[j].i)
            sum->ele[k++]  = ele[i++];
        else if(ele[i].i > s.ele[j].i)
            sum->ele[k++]  = s.ele[j++];
        else
        {
            if(ele[i].j < s.ele[j].j)
                sum->ele[k++]  = ele[i++];
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++]  = s.ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x  + s.ele[j++].x;
            }
        }
    }

    for( ; i<num ; i++)
        sum->ele[k++] = ele[i];

    for( ; i<s.num ; j++)
        sum->ele[k++] = s.ele[j];

    sum->m = m;
    sum->n = n;
    sum->num = k;

    return *sum;
}



int main(){
    sparse s1(5 ,5 ,5 );
    sparse s2(5 ,5 ,5 );

    cin>>s1;
    cin>>s2;

    cout<<s1;
    cout<<s2;

    sparse sum = s1 + s2;

    cout<<endl<<"FIRST MATRIX"<<s1;
    cout<<endl<<"SECOND MATRIX"<<s2;
    cout<<endl<<"SUM MATRIX"<<sum;

    return 0;
}
