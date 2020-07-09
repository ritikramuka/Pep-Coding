#include<iostream>
#include<vector>
using namespace std;

vector<int> add_(vector<int>& a,vector<int>& b)
{
    int n=max(a.size(),b.size())+1;
    vector<int>ans(n,0);
    int i=a.size()-1;
    int j=b.size()-1;
    int k=n-1;
    int carry=0;
    while(i>=0 && j>=0){
        int val1=a[i];
        int val2=b[j];
        int stateans=val1+val2+carry;
        ans[k]=stateans%10;
        carry=stateans/10;
        i--;
        j--;
        k--;
    }
    while(i>=0){
        int stateans=carry+a[i];
        ans[k]=stateans%10;
        carry=stateans/10;
        i--;
        k--;
    }
        while(j>=0){
        int stateans=carry+b[j];
        ans[k]=stateans%10;
        carry=stateans/10;
        j--;
        k--;
    }
    ans[k]=carry;
    if(ans[0]==0)
    {
        for(int i=1;i<ans.size();i++)
        cout<<ans[i]<<" ";
    }
    else
    {
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    }
    
}

void input(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
}

void solve()
{
    int n,m;
    cin>>n;
    vector<int>a(n,0);
    input (a);
    cin>>m;
    vector<int>b(m,0);
    input(b);
    vector<int>arr=add_(a,b);
}

int main(int args,char**argv)
{
    solve();
    return 0;
}