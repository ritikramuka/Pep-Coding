#include<iostream>
#include<vector>

using namespace std;

void display(vector<int>& arr){
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
}

void inverse(vector<int>& arr){
    vector<int> ans(arr.size(),0);
    for(int i=arr.size();i>=0;i--){
        ans[arr[i]]=i;
    }
    arr=ans;
}

void inputArray(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    inputArray(arr);
    inverse(arr);
    display(arr);
}
int main(int args, char**argv)
{
    solve();
}