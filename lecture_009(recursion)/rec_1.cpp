#include<iostream>
using namespace std;

void oddeven(int n,int tar)
{
    if(n>tar)
    return;
    if(n%2==1)
    cout<<n<<" ";
    oddeven(n+1,tar);
    if(n%2==0)
    cout<<n<<" ";
}

void ID(int n,int tar)
{
    if(n==tar)
    {
        cout<<tar<<" ";
        return;
    }
    cout<<n<<" ";
    ID(n+1,tar);
    cout<<n<<" ";
}

void increasing(int n)
{
    if(n==0)
    return;
    increasing(n-1);
    cout<<n<<" ";
}

void decreasing(int n)
{
    if(n==0)
    return;
    cout<<n<<" ";
    decreasing(n-1); //faith
}

void DIV_1(int n)
{
    if(n==0)
    return;
    cout<<n<<" ";
    DIV_1(n-1);//print 1 two time
    cout<<n<<" ";
}

void DIV_2(int n)
{
    if(n==1)
    {
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    DIV_2(n-1);//do not print one
    cout<<n<<" ";
}

void solve()
{
    cout<<"enter n"<<endl;
    int n;
    cin>>n;
    increasing(n);
    cout<<endl;
    decreasing(n);
    cout<<endl;
    DIV_1(n);
    cout<<endl;
    DIV_2(n);
    cout<<endl;
    ID(1,n);
    cout<<endl;
    oddeven(1,10);
}

int main(int args, char**argv)
{
    solve();
    return 0;
}