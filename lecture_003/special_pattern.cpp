#include<iostream>
using namespace std;
int main(int args, char**argv)
{
    cout<<"enter number of rows.."<<endl;
    int n;
    cin>>n;
    int nst=1,nsp=n+1;
    int count=1;
    for(int i=1;i<=n;i++){
        for(int cst=1;cst<=nst;cst++){
            cout<<count;
            count++;
        }if(i<n)
        {
        for(int csp=1;csp<=nsp;csp++){
            cout<<" ";
        }
        }
        else
        {count--;}
        
        for(int cst=1;cst<=nst;cst++){
            count--;
            if(count!=0)
            cout<<count;
        }
        nst++;
        nsp-=2;
        cout<<endl;
    }
}