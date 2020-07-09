#include<iostream>
using namespace std;
int main(int args, char**argv)
{
    cout<<"enter number of rows"<<endl;
    int r,a,b,sum=0;
    cin>>r;
    a=0;
    b=1;
    
    for(int i=0;i<r;i++){
        for (int j=0;j<=i;j++){
            cout<<sum<<" ";
            a=b;
            b=sum;
            sum=a+b;
        }cout<<endl;
    }
    return 0;
}