#include <iostream>
#include <vector>
using namespace std;

int verify(vector<int>& arr,int el)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if (arr[i]==el)
        {
            sum++;
        }
        
    }
    if(sum>arr.size()/2)
    return el;
    else
    return 1;
}

int potentialcand(vector<int>& arr)
{
    int ele=arr[1];
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==ele)
        sum++;
        else
        sum--;
        if(sum==0)
        {ele=arr[i];
        sum=1;}
    }
    return ele;
}

void input(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
    cout<<endl;
}

void solve()
{
    cout<<"enter array size"<<endl;
    int n;
    cin>>n;
    cout<<"enter array"<<endl;
    vector<int>arr(n,0);
    input(arr);
    int m=potentialcand(arr);
    int f=verify(arr,m);
    if(f==1)
    cout<<"no potential ele";
    else
    cout<<"potential ele is "<<f<<endl;
}

int main(int args, char** argv)
{
    solve();
    return 0;
}