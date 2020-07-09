#include<iostream>
#include<vector>
using namespace std;

int equi_index( vector<int>&arr)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    int left_sum=arr[0];
    for(int i=1;i<arr.size()-1;i++)
    {
        if(left_sum==(sum-arr[i]-left_sum))
        {
            return i;               //if want to find more possible index cout here only and dont return;
        }
        else
        {
            left_sum+=arr[i];
        }
    }
    return -1;
}

void input( vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
}

void solve()
{
    cout<<"enter array length"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    input(arr);
    int m=equi_index(arr);
    if(m==-1)
    cout<<"no such index found";
    else
    cout<<"equi index is "<<m;
}

int main(int args,char** argv)
{
    solve();
    return 0;
}