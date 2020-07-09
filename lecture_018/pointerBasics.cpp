#include<iostream>

using namespace std;

void stackIdentification(int idx)
{
    if(idx==2)
    return;
    cout<<&idx<<endl;
    stackIdentification(idx+1);
}

void solve()
{
    stackIdentification(0);
}

int main(int args,char**argv)
{
    solve();
    return 0;
}