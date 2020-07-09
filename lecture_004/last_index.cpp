#include<iostream>
#include<vector>

using namespace std;

int last_index(vector<int>& arr,int data){
    int pos=0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]==data)
        pos=i;
    }
    return pos;
    
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
    int b;
    cout<<"enter data pos to find"<<endl;
    cin>>b;
    int p=last_index(arr,b);
    cout<<"last index is"<<p;
    
}
int main(int args, char**argv)
{
    solve();
    return 0;
}