#include<iostream>
#include<vector>

using namespace std;

void Dpointer()
{
    int n=10;
    int *arr=new int(n);
    for(int i=0;i<n;i++)
    arr[i]=0;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void solve(){
    Dpointer();
}
int main(int args,char**argv)
{
    solve();
    return 0;
}