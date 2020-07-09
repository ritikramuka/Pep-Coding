#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n==0||n==1)
    {return n;}
    int nthMinusOne=fibo(n-1);
    int nthMinusTwo=fibo(n-2);
    int nthFibo=nthMinusOne+nthMinusTwo;
    return nthFibo;
}

void solve()
{
    cout<<"enter numberth of fibo term required"<<endl;
    int n;
    cin>>n;
    int m=fibo(n);
    cout<<"-->"<<fibo(n);
}

int main(int args,char** argv)
{
    solve();
}