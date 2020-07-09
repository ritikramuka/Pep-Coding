#include<iostream>
#include<vector>

using namespace std;

void dispaly(vector<vector<int>>& ans)
{
     for(int i=0;i<ans.size();i++)
         {
             for(int j=0;j<ans[0].size();j++)
             {
                 cout<<ans[i][j]<<" ";

             }
             cout<<endl;
         }
 
}

vector<vector<int>> turn(vector<vector<int>>& arr){
     cout<<"enter type of turn 1 for +90 0 for -90";
     int r;
     cin>>r;
     if(r==1)
     {
         for(int i=0;i<arr.size();i++)
         {
             for(int j=0;j<arr[0].size();j++)
             {
                 if(i<j)
                 {
                     int temp=arr[i][j];
                     arr[i][j]=arr[j][i];
                     arr[j][i]=temp;
                 }
             }
         }
         for(int i=0;i<arr[0].size()/2;i++){
             for(int j=0;j<arr[0].size();j++)
             {
                 
                 int temp=arr[i][j];
                 arr[i][j]=arr[(arr[0].size()-i)-1][j];
                 arr[arr[i].size()-1-i][j]=temp;
             } 
         }
     }
     else 
     {
         for(int i=0;i<arr.size();i++)
         {
             for(int j=0;j<arr[0].size();j++)
             {
                 if(i<j)
                 {
                     int temp=arr[i][j];
                     arr[i][j]=arr[j][i];
                     arr[j][i]=temp;
                 }
             }
         }
         for(int i=0;i<arr.size()/2;i++)
         {
             for(int j=0;j<arr[0].size();j++)
             {
                 
                 int temp=arr[i][j];
                 arr[i][j]=arr[(arr[0].size()-1)-i][j];
                 arr[(arr[0].size()-1)-i][j]=temp;
             }
         }
     }
     return arr;
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
    cout<<"enter n"<<endl;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    input(arr);
    vector<vector<int>>ans=turn(arr);
    dispaly(ans);
}
int main(int args, char**argv)
{
    solve();
}