#include<iostream>
using namespace std;

int fun(int x,int n)
{
    int cof=n;
    int px=x;
    int sum=0;
    while(cof!=0)
    {
        sum+=cof*px;
        px=px*x;
        cof--;
    }
    return sum;
}

void soe(int n)
{
    bool arr[n+1];
    arr[0]==true;
    arr[1]==true;

    for (int  i = 2; i*i <= n; i++)
    {
        if(!arr[i])
        {
            for(int j=i; j*i <= n; j++)
            {
                arr[i*j]==true;
            }
        }
    }
    
    for (int  i = 0; i <= arr.size()-1; i++)
    {
        if(arr[i]==false)
        {
            cout<<i;
        }
    }
    
}

// void factorization(int[] spf,int x)
// {
// }

solve()
{
    int x,n;
    cin>>n;
    cin>>x;
    // cout<<fun(x,n);
    soe(100);
}

int main(int args,char** argv)
{
    solve();
    return 0;
}