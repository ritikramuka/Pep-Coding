#include<iostream>
using namespace std;
int main(int args, char**argv){
    cout<<"enter the numbers of rows"<<endl;
    int r,a=1;
    cin>>r;
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++){
            cout<<a<<" ";
            a=(a*(i-j))/(j+1);
        }a=1;
        cout<<endl;
    }
return 0;
}