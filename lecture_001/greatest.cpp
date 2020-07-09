#include<iostream>
using namespace std;
int main(int args, char**argv){
    cout<<"enter numbers you want to verify"<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"the greatest number is \n";
    if(a>b && a>c)
    {cout<<a;}
    else if (b>c && b>a)
    cout<<b;
    else if (c>b && c>a)
    cout<<c;
    return 0;
}