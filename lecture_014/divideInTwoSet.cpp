#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int setSum2(vector<int>& arr,int vidx,int set1Sum,string set1,int set2Sum,string set2)
{
    if(vidx==arr.size())
    {
        int rval=0;
        if(set1Sum==set2Sum)
        {
            cout<<set1<<"="<<set2<<endl;
            rval=1;
        }
        return rval;
    }
    int count=0;

    count+=setSum2(arr,vidx+1,set1Sum,set1,set2Sum,set2);    
    count+=setSum2(arr,vidx+1,set1Sum+arr[vidx],set1+to_string(arr[vidx])+"+",set2Sum,set2);
    count+=setSum2(arr,vidx+1,set1Sum,set1,set2Sum+arr[vidx],set2+to_string(arr[vidx])+"+");

    return count;
}

int setSum(vector<int>& arr,int vidx,int set1Sum,string set1,int set2Sum,string set2)
{
    if(vidx==arr.size())
    {
        int rval=0;
        if(set1Sum==set2Sum)
        {
            cout<<set1<<"="<<set2<<endl;
            rval=1;
        }
        return rval;
    }
    int count=0;
    
    count+=setSum(arr,vidx+1,set1Sum+arr[vidx],set1+to_string(arr[vidx])+" ",set2Sum,set2);
    count+=setSum(arr,vidx+1,set1Sum,set1,set2Sum+arr[vidx],set2+to_string(arr[vidx])+" ");

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
    cout<<setSum(arr,0,0,"",0,"")<<endl;
    //cout<<setSum2(arr,0,0,"",0,"");
}

int main(int args,char**argv)
{
    solve();
    return 0;
}