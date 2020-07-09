#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void reverse(vector<int>& arr2,int vidx)
{
    if(vidx==arr2.size())
    {
        return ;
    }
    int data=arr2[vidx];
    reverse(arr2,vidx+1);
    arr2[data]=vidx;
}

vector<int> allindex(vector<int>& arr,int data,int vidx,int count)
{
    if(vidx==arr.size())
    {
        vector<int> base(count,0);
        return base;
    }
    if(arr[vidx]==data)
    count++;
    vector<int> smallans=allindex(arr,data,vidx+1,count);
    if(arr[vidx]==data)
    {
        smallans[count-1]=vidx;
    }
    return smallans;
}

int lastindex(vector<int>& arr,int data,int vidx)
{
    if(vidx==arr.size())
    {
        return -1;
    }
    int ans=lastindex(arr,data,vidx+1);
    if(ans!=-1) 
    {
        return ans;
    }
    if(arr[vidx]==data)
    {
        return vidx;
    }
    else 
    {
        return -1;
    }
}

void find(vector<int>& arr,int data,int vidx)
{
    if(vidx==arr.size())
    return ;
    if(arr[vidx]==data)
    cout<<vidx<<" ";
    find(arr,data,vidx+1);
}

int max_(vector<int>& arr,int vidx)
{
    if(vidx==arr.size())
    return INT_MIN;
    int faithmax=max_(arr,vidx+1);
    int actualmax=max(faithmax,arr[vidx]);
    return actualmax;
}

int min_(vector<int>& arr,int vidx)
{
    if(vidx==arr.size())
    return INT_MAX;
    int faithmin=min_(arr,vidx+1);
    int actualmin=min(faithmin,arr[vidx]);
    return actualmin;
}

void display(vector<int>& arr, int vidx)
{
    if(vidx==arr.size()){
        return;
    }
    cout<<arr[vidx]<<" ";
    display(arr,vidx+1);
}

void solve()
{
    vector<int>arr={50,10,20,30,40,50,60,50,20,50,50,50,70,80,90,50,100};
    display(arr,0);
    int m=max_(arr,0);
    cout<<endl<<m<<endl;
    int n=min_(arr,0);
    cout<<n<<endl;
    find(arr,50,0);
    int l=lastindex(arr,50,0);
    cout<<endl<<l<<endl;
    vector<int> a=allindex(arr,50,0,0);
    for(int i:a)
    cout<<i<<" ";
    cout<<endl;
    vector<int>arr2={2,4,0,1,3};
    reverse(arr2,0);
    display(arr2,0);
}

int main(int args,char**argv)
{
    solve();
    return 0;
}