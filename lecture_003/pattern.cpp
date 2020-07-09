#include<iostream>
using namespace std;
int main(int args, char**argv)
{cout<<"enter number of rows"<<endl;
int r;
cin>>r;
int nst,nsp;
nst=1;
nsp=r-1;
for(int i=1;i<=r;i++){
    for(int csp=1;csp<=nsp;csp++){
        cout<<" ";
    }
    for(int cst=1;cst<=nst;cst++){
        cout<<"*";
    }
    nst++;
    nsp--;
    cout<<endl;
}
return 0;
}