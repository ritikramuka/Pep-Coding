#include<iostream>
#include<vector>
using namespace std;

int Karma(vector<int>arr,int sword)
{
    if(arr.size()==1)
    {
        return sword;
    }
    sword=(sword+2)%arr.size();
    arr.erase(arr.begin()+(sword-1));
    Karma(arr,sword+1);
    return sword;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=1;i<=arr.size();i++)
    {
        arr[i]=i;
    }
    cout<<Karma(arr,1);
}

int main(int args,char**argv)
{
    solve();
}