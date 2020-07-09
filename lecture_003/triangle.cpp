#include<iostream>
using namespace std;
int main(int args, char**argv)
{int row;
cin>>row;
int nst=1;
while(row-->0){
    for(int cst=1;cst<=nst;cst++)
    cout<<"*";
    nst++;
cout<<endl;
}return 0;
}