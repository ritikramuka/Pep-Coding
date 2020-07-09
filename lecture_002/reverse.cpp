#include<iostream>
using namespace std;
int main(int args, char** argv)
{
    cout<<"enter the number"<<endl;
    int n,rev=0;
    cin>>n;
    for(int i=1;n!=0;i++){
        int rem=n%10;
        n=n/10;
        rev*=10;
        rev+=rem;
    
    }
    cout<<rev<<endl;
    return 0;
}