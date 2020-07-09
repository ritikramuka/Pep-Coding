#include<iostream>
using namespace std;
int main(int args, char**argv)
{ cout<<"enter your number"<<endl;
int a;
cin>>a;
bool flag=true;
for(int i=2; i<a/2; i++)
{if (a%i==0)
{flag=false;
break;}
}
if(flag==true)
cout<<"prime "<<a<<endl;
else
cout<<"not a prime "<<a<<endl;
return 0;
}