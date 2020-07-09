#include<iostream>
using namespace std;
int main(int args, char**argv)
{cout<<"enter the number of termth of a fibo you want to know."<<endl;
int n,a=0,b=1,sum=0;
cin>>n;
if(n<=1)
{
    cout<<n<<endl;
    return 0;
}
for(int i=2;i<=n;i++)
{sum=a+b;
a=b;
b=a;
}
cout<<sum;
return 0;
}