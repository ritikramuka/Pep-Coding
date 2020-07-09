#include<iostream>
using namespace std;

int step=0;

int power_V1(int a,int b)
{
    if(b==0)
    return 1;
    int m=a*power_V1(a,b-1);
    step++;
    return m;
    //return b!=0?a*power_V1(a,b-1):1; can be done in one line like this
}

void solve()
{
    cout<<"enter number and its power"<<endl;
    int a,b;
    cin>>a;
    cin>>b;
    int ans=power_V1(a,b);
    cout<<ans<<endl;
    cout<<step;
}

int main(int args,char**argv)
{
    solve();
}