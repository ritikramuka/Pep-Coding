#include<iostream>
#include<vector>

using namespace std;

void display(vector<int>& arr){
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
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
    display(arr);
}
int main(int args, char**argv)
{
    solve();
}