#include<iostream>
#include<vector>

using namespace std;

void display(vector<int>& arr){
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
}

void reverse(vector<int>& arr, int i, int j)
{
    while(i<j)
    {
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        i++;j--;
    }
}

void rotate(vector<int>& arr,int m)
{
    m%=arr.size();
    m=m>0?m:(m+arr.size());
    reverse(arr,0,m-1);
    reverse(arr,m,arr.size()-1);
    reverse(arr,0,arr.size()-1);

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
    cout<<"enter rotate number"<<endl;
    int r;
    cin>>r;
    rotate(arr,r);
    display(arr);
}
int main(int args, char**argv)
{
    solve();
}