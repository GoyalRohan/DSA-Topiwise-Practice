#include<iostream>
using namespace std;

void PERM(char S[] , int k)
{
    static int A[10] = {0};
    static char res[10];
    int i;
    if(S[k] == '\0')
    {
        res[k]  = '\0';
        cout<<endl<<res;
    }
    else
    {
        for(i = 0 ; S[i] != 0 ; i++)
        {
            if(A[i] == 0)
            {
                res[k] = S[i];
                A[i] = 1;
                PERM(S , k+1);
                A[i] = 0;
            }
        }
    }
}

int main(){
    char S[] = "abc";
    PERM(S , 0);
    return 0;
}