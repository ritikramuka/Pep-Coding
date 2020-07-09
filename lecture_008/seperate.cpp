#include<iostream>
#include<vector>
using namespace std;

void swap(int i,int j,vector<int>& arr)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void seperate(vector<int>& arr)
{
    int itr=0,ptr=0;
    while(itr<arr.size())
    {
        if(arr[itr]==1)
        {
            itr++;
        }
        else 
        {
            swap(ptr,itr,arr);
            ptr++;
            itr++;
        }
    }
    for(int i:arr)
    cout<<i<<" ";
}

void input(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    input(arr);
    seperate(arr);
}

int main(int args,char**argv)
{
    solve();
}