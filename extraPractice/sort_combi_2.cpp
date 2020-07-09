#include<iostream>
#include<vector>
#include<algorithm>                         //if there is repitation then only print distinct pairs
#include<string>
using namespace std;

void targetSum(vector<int>&arr,int target)
{
    int left=0;
    int right=arr.size()-1;
    bool flag=false;
    while(left<right)
    {
        int sum=arr[left]+arr[right];
        if(sum==target){
            cout<<"("+to_string(left)+","+to_string(right)+")";
            left++;
            while (left<right && arr[left]==arr[left-1])
            {
                left++;
            }
            right--;
            while (left<right && arr[right]==arr[right+1])
            {
                right--;
            }
            flag=true;
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
        
    }
    if(flag==false)
    cout<<"sum not found"<<endl;
}

void sort(vector<int>&arr)
{
    sort(arr.begin(),arr.end());
    targetSum(arr,12);
}

void input(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
}

void solve()
{
    cout<<"enter array length"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    input(arr);
    sort(arr);
}

int main(int args,char** argv)
{
    solve();
    return 0;
}