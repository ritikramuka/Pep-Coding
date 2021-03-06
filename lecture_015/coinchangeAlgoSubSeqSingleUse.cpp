#include<iostream>          //combination with single time repetition of coins
#include<vector>

using namespace std;

int coin_change(vector<int>&arr,int idx,int coinsum,string ans)
{
    if(idx==arr.size() || coinsum==0)
    {
        if(coinsum==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }

    int count=0;
    //here targetsum has choice weather to accept coin or !.
    if(coinsum>=0)
    {
        count+=coin_change(arr,idx+1,coinsum-arr[idx],ans+to_string(arr[idx])+" "); 
        count+=coin_change(arr,idx+1,coinsum,ans); 
    }

    return count;
}

void input(vector<int>&arr)
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
