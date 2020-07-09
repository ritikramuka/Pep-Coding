#include<iostream>
#include<vector>

using namespace std;

void display(vector<int>& arr)
{
    for(int i : arr)
    cout<<i<<" ";
}

void input_value(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
}

void solve()
{
    cout<<"enter n";
    int n;
    cin>>n;
    vector<int> arr(n,0);
    input_value(arr);
    display(arr);
}

int main(int args,char** argv)
{
    solve();
    return 0;
}

