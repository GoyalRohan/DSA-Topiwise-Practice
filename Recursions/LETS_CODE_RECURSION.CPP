#include<iostream>
using namespace std;

void fun1(int n)
{
    if(n>0)
    {
    cout<<n<<" ";
    fun1(n-1);

    /*
    if it is written in this way then it is called head recursion
    fun1(n-1);
    cout<<n<<" ";
    */
    }
}

int main(){
    int n;
    cout<<"Enter the number you want to enter:";
    cin>>n;
    fun1(n);
    return 0;
}