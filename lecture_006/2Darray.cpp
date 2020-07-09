#include<iostream>

using namespace std;

void twoDpointer()
{
    int n=3;
    int m=4;
    int **arr=new int *[n];
    for(int i=0;i<n;i++)
    {
        int *ar=new int(m);
        arr[i]=ar;
    }
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
        arr[i][j]=10;
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    
}
}

void solve()
{
    twoDpointer();
}
int main(int args,char**argv)
{
    solve();
    return 0;
}