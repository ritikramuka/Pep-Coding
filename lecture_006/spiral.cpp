#include<iostream>
#include<vector>

using namespace std;


void spiral(vector<vector<int>>& arr){
     int minr=0,minc=0,maxr=arr.size()-1,maxc=arr[0].size()-1;
     int tne=arr.size()*arr[0].size();
     while(tne>0)
     {
         for(int i=minc;i<=maxc && tne>0;i++)
         {
             cout<<arr[minr][i]<<" ";
             tne--;
     }
     minr++;
      for(int i=minr;i<=maxr && tne>0;i++)
         {
             cout<<arr[i][maxc]<<" ";
             tne--;
     }
     maxc--;
      for(int i=maxc;i>=minc && tne>0;i--)
         {
             cout<<arr[maxr][i]<<" ";
             tne--;
     }
     maxr--;
      for(int i=maxr;i>=minr && tne>0;i--)
         {
             cout<<arr[maxr][i]<<" ";
             tne--;
     }
     minc++;
}
}

void input(vector<vector<int>>& arr){
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        cin>>arr[i][j];
    }
}

void solve()
{
    int n,m;
    cout<<"enter n,m"<<endl;
    cin>>n;
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    input(arr);
    spiral(arr);
}
int main(int args, char**argv)
{
    solve();
    return 0;
}