#include<iostream>
#include<vector>
#include<string>

using namespace std;

int targetSum(vector<int>& arr,int targ,int vidx,string ans)
{
    if(vidx==arr.size() || targ==0)
    {
        int rval=0;
        if(targ==0)
        {
            cout<<ans<<endl;
            rval=1;
        }
        return rval;
    }
    int count=0;

    count+=targetSum(arr,targ-arr[vidx],vidx+1,ans+to_string(arr[vidx])+" ");
    count+=targetSum(arr,targ,vidx+1,ans);

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
    cout<<"enter array length";
    int n;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    int m=targetSum(arr,100,0,"");
    cout<<m;
}

int main(int args,char**argv)
{
    solve();
    return 0;
}