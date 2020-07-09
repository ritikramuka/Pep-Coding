#include<iostream>

using namespace std;

void twoDpointer()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    int m;
    cout<<"enter m"<<endl;
    cin>>m;
    int **arr=new int *[n];
    for(int i=0;i<n;i++)
    {
        int *ar=new int(m);
        arr[i]=ar;
    }
    cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j];
    }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    
}
    int max_=arr[0][0];
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
        if(arr[i][j]>max_)
        max_=arr[i][j];
    }
    cout<<endl;}
    cout<<"max value is "<<max_;
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