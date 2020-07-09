#include<iostream>
using namespace std;

int facto(int n)
{
    if(n==0)
    return 1;
    int ans=n*facto(n-1);
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    int m=facto(n);
    cout<<m;
}

int main(int args,char**argv)
{
    solve();
}