#include<iostream>
#include<vector>

using namespace std;

int coin_change(vector<int>& arr,int idx,int coinsum,string ans)
{
    if(coinsum==0)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;

    for(int vidx=idx;vidx<arr.size();vidx++)
    {
        if(coinsum-arr[vidx]>=0)
        count+=coin_change(arr,vidx,coinsum-arr[vidx],ans+to_string(arr[vidx])+" ");
    }

    return count;
}

void input(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
}

void solve()
{
    cout<<"enter no. of denominations to be used"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    input(arr);
    cout<<"enter target sum"<<endl;
    int coinsum;
    cin>>coinsum;
    cout<<coin_change(arr,0,coinsum,"");
}

int main(int args,char** argv)
{
    solve();
    return 0;
}
