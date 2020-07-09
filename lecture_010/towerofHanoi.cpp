#include<iostream>
using namespace std;

void towerOfHanoi(int n,string src,string desti,string help)
{
    if(n==0)
    return;
    towerOfHanoi(n-1,src,help,desti);
    cout<<n<<"th block from source-> "<<src<<" to destination-> "<<desti<<endl;
    towerOfHanoi(n-1,help,desti,src);
}

void solve()
{
    towerOfHanoi(3,"A","B","C");
}

int main(int args,char** argv)
{
    solve();
    return 0;
}