#include<iostream>
using namespace std;
int main(int args, char**argv){
    cout<<"enter number"<<endl;
    int n,r;
    cin>>n;
    for(int i=2;i<n;i++)
    {if(n%i==0)
    r=0;
    else r=1;
    }
    if(r==0)
    cout<<"not prime";
    else
    cout<<"prime";
    return 0;
}