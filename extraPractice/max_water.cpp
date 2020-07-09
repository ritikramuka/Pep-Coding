#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void max_water( vector<int>&arr)
{
    int maxarea=0;
    int l=0,r=arr.size()-1;
    while(l<r)
    {
        int width=r-l;
        int heigth=arr[r];
        if(arr[l]<arr[r])
       {
            heigth=arr[l];
            l++;
       }
       else
       {
            r--;
       }
       int potentialAns=heigth*width;
       maxarea=max(maxarea,potentialAns);
        
    }
    cout<<"max water can be stored will be "<<maxarea;
}
void input( vector<int>&arr)
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
    max_water(arr);
}

int main(int args,char** argv)
{
    solve();
    return 0;
}