#include<iostream>
#include<string>

using namespace std;

void  experiment_one()
{
    string str="";
    for(int i=0;i<100;i++)
    {
        str+=to_string(i);      //+ after str is used to add elements to string if it's not used it will only have last given value
        //str=to_string(i); outout=99   
    }
    cout<<str<<endl;
}

void solve()
{
    experiment_one();
}

int main(int args,char**argv)
{
    solve();
}