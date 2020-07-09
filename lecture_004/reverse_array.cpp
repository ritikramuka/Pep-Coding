#include<iostream>
#include<vector>

using namespace std;
void display(vector<int>& arr){
    for(int i:arr)
    cout<<i<<" ";
    cout<<endl;
}

void reverse(vector<int>& arr){
    
    for(int i=0,j=arr.size()-1;i<arr.size()/2,j>arr.size()/2;i++,j--)
   { int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;}
    
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
    reverse(arr);
    display(arr);
    
}
int main(int args, char**argv)
{
    solve();
    return 0;
}