#include<iostream>
#include<vector>

using namespace std;

void maximum(vector<vector<int>>& arr){
    int max_=arr[0][0];
    for(int i=0;i<arr.size();i++)
    {
    for(int j=0;j<arr[0].size();j++)
    {
        if(arr[i][j]>max_)
        max_=arr[i][j];
    }
    cout<<endl;}
    cout<<"max value is "<<max_;
}

void display(vector<vector<int>>& arr){
     for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void input(vector<vector<int>>& arr){
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        cin>>arr[i][j];
    }
}

void solve()
{
    int n,m;
    cout<<"enter n,m"<<endl;
    cin>>n;
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    input(arr);
    display(arr);
    maximum(arr);
}
int main(int args, char**argv)
{
    solve();
}