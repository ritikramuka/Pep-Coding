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
    int itr=0,ptr1=0,ptr2=arr.size()-1;
    while(ptr2>=itr)
    {
        if(arr[itr]==1)
        itr++;
        else if(arr[itr]==0)
        {
            swap(itr,ptr1,arr);
            itr++;
            ptr1++;
        }
        else
        {
            swap(ptr2,itr,arr);
            ptr2--;
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