#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& aans)
{
    for(int i:aans)
    cout<<i<<" ";

}

vector<int> find(vector<int>& arr,int data)
{
    vector <int> ans;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==data)
        ans.push_back(i);
    }
    return ans;
}

void insertValue(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
}

void solve()
{
    cout<<"enter n"<<endl;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    insertValue(arr);
    cout<<"enter data index to find"<<endl;
    int b;
    cin>>b;
    vector<int>aans=find(arr,b);
    display(aans);
}

int main(int args, char** argv)
{
    solve();
    return 0;
}