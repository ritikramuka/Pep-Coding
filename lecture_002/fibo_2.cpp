#include<iostream>
using namespace std;
int main(int args, char**argv){
    cout<<"enter the number "<<endl;
    int n,a=0,b=1,sum=0;
    cin>>n;

    if(n>=0)
    {cout<<0<<" ";
     if(n==0) return 0;}
    if(n>=1){
    cout<<1<<" ";
    if(n==1) return 0;
    }
    for(int i=2;i<=n;i++)
    {sum=a+b;
    cout<<sum<<" ";
    a=b;
    b=sum;}
    return 0;
}