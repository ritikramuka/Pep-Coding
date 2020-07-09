#include<iostream>
#include<vector>

using namespace std;

void display(vector<vector<int>>& arr){
     for(int i=0;i<arr.size();i++)
    {   if(i%2==0)
       {for(int j=0;j<arr[0].size();j++)
        cout<<arr[i][j]<<" ";}
        else
        {
         for(int j=arr[0].size()-1;j>=0;j--)
         cout<<arr[i][j]<<" ";
        }
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
}
int main(int args, char**argv)
{
    solve();
}