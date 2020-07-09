#include<iostream>
#include<vector>

using namespace std;

int find(vector<int>& arr,int data){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==data)
        return i;
    }
    return -1;
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
    cout<<"enter number to find"<<endl;
    int m;
    cin>>m;
   int d= find(arr,m);
   cout<<d;
   
}
int main(int args, char**argv)
{
    solve();
}
























