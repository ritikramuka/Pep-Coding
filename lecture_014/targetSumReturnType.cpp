#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int targetSum(vector<int>& arr,int targ,int vidx,vector<int> ans)
{
    if(vidx==arr.size() || targ==0)
    {
        int rval=0;
        if(targ==0)
        {
            cout<<endl;
            for(int i:ans)
                cout<<i<<" ";
            rval=1;
        }
        return rval;
    }
    int count=0;
    
    count+=targetSum(arr,targ,vidx+1,ans);
    ans.push_back(arr[vidx]);
    count+=targetSum(arr,targ-arr[vidx],vidx+1,ans);
    //ans.pop_back(); and add & at ans

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
    cout<<"enter array length"<<endl;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    vector<int>ans;
    int m=targetSum(arr,100,0,ans);
    cout<<endl<<m;
}

int main(int args,char**argv)
{
    solve();
    return 0;
}