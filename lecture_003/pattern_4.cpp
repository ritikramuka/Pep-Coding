#include<iostream>
using namespace std;
int main(int args ,char**argv)
{cout<<"enter an odd number"<<endl;
int n,nst,nsp;
cin>>n;
nst=1;
nsp=n/2;
for(int i=1;i<=n;i++){
    for(int csp=1;csp<=nsp;csp++)
    {
        cout<<" "<<" ";
    }
    for(int cst=1;cst<=nst;cst++)
    cout<<"*"<<" ";

    if(i<=n/2){
    nst+=2;
    nsp--;}
    else
    {
        nst-=2;
        nsp++;
    }
    cout<<endl;

}
return 0;
}