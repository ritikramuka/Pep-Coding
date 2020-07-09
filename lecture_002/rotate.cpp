#include<iostream>
using namespace std;
int main(int args, char**argv){
    cout<<"enter the num"<<endl;
    int n,rot,len=1,temp;
    cin>>n;
    temp=n;
    cout<<"enter the rotate num"<<endl;
    cin>>rot;
    while(temp!=0){
        len++;
        temp=temp/10;
    }
    rot%=len;
    rot=rot < 0 ? rot + len :rot;

    int div=1;
    int mul=1;
    for(int i=1;i<=len;i++){
        if(i<=rot)
        mul*=10;
        else
        div*=10;
    }
    int lastnum=n/div;
    int firstnum=n%div;
    int newnum=(firstnum*mul + lastnum);
    cout<<newnum;
    return 0;
}