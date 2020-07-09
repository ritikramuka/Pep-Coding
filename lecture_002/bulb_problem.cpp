#include<iostream>
using namespace std;
int main(int args, char**argv){
    cout<<"enter the no. of person"<<endl;
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        cout<<i*i<<" ";
    }
return 0;
}