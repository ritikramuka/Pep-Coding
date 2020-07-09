#include<iostream>
using namespace std;

int power_2(int a,int b){
    if(b==0)
    {
        return 1;
    }
    int pow=power_2(a,b/2);
    pow*=pow;
    if(b%2!=0)
    pow*=a;
    return pow;
}

int power_1(int a,int b){
    if (b==0)
    return 1;
    int ans=a*power_1(a , b-1);
    return ans;
}

void fibo(int n){

}

void DI(int n){

}

void ID(int n,int tar){
    if(n==tar){
        cout<<tar<<" ";
        return;
    }
    cout<<n<<" ";
    ID(n+1,tar);
    cout<<n<<" ";   
}

void deacreasing(int n){
    if(n==0) {
        cout<<0;
        return;}
    cout<<n<<" ";
    deacreasing(n-1);
}

void increasing(int n){
    if(n==-1) return ;
    increasing(n-1);
    cout<<n<<" ";
}

void solve()
{
    int n;
    cin>>n;
    increasing(n);
    cout<<endl;
    deacreasing(n);
    cout<<endl;
    ID(0,n);
    cout<<endl;
    int m=power_2(2,10);
    cout<<m<<endl;
    int j=power_1(2,10);
    cout<<j<<endl;
}

int main(int args ,char** argv)
{
    solve();
    return 0;
}