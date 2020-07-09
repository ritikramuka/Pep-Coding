#include<iostream>
#include<vector>

using namespace std;

 maximum_(vector<int>& arr){
    int max_=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>max_)
        max_=arr[i];
    }
    return max_;
    
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
    int b=maximum_(arr);
    cout<<"max is"<<b;
    
}
int main(int args, char**argv)
{
    solve();
}