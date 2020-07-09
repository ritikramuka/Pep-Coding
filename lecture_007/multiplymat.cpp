#include<iostream>
#include<vector>

using namespace std;

void display(vector<vector<int>>& ans){
     for(int i=0;i<ans.size();i++)
    {   
       for(int j=0;j<ans[0].size();j++)
       { 
           cout<<ans[i][j]<<" ";
           
       }
        cout<<endl;
    }
    cout<<endl;
}

void multiply (vector<vector<int>>& A,vector<vector<int>>& B){
    vector<vector<int>> K;
    if(A[0].size()==B.size())
    {
        for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B[0].size();j++)
        {
            for(int f=0;f<A[0].size();f++)
            {
                K[i][j]+=(A[i][f]*B[f][j]);
            }
        }
    }
    display(K);
    }
    else 
    cout<<"cann't be multiplied"<<endl;
    
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
    cout<<"enter matrix A coordinates"<<endl;
    cin>>n;
    cin>>m;
    vector<vector<int>>A(n,vector<int>(m,0));
    input(A);
    cout<<"enter matrix B coordinates"<<endl;
    int q,w;
    cin>>q;
    cin>>w;
    vector<vector<int>>B(q,vector<int>(w,0));
    input(B);
    multiply(A,B);
    }
int main(int args, char**argv)
{
    solve();
    return 0;
}