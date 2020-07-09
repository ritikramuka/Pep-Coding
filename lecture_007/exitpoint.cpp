#include<iostream>
#include<vector>

using namespace std;

void exitpoint (vector<vector<int>>& arr){
    int dir=0,c=0,r=0;

    while(true)
    {
        dir=(dir+arr[r][c])%4;
        
        if(dir==0)
        {
            c++;
            if(c==arr[0].size())
            {
                cout<<r<<","<<c-1;
                break;
            }
        }
        else if(dir=1)
        {
            r++;
            if(r==arr.size())
            {
                cout<<(r-1)<<","<<c;
                break;
            }
        }
        else if(dir==2)
        {
            c--;
            if(c==-1)
            {
                cout<<r<<","<<c+1;
                break;
            }
        }
        else
        {
            r--;
            if(r==-1)
            {
                cout<<r+1<<","<<c;
                break;
            }
        }
        
    }
    
}

void display(vector<vector<int>>& arr){
     for(int i=0;i<arr.size();i++)
    {   
       for(int j=0;j<arr[0].size();j++)
       { 
           cout<<arr[i][j]<<" ";
           
       }
        cout<<endl;
    }
    cout<<endl;
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
    display(arr);
    exitpoint(arr);
}
int main(int args, char**argv)
{
    solve();
}