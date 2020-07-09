#include<iostream>
#include<vector>
using namespace std;


bool iswordPresent(vector<string>& dict,string word)
{
    for(string str : dict)
    {
        if(word.compare(str)==0)
        {
            return true;
        }
    }
    return false;
}

int wordBreak(vector<string>& dict,string statement,string ans)
{
    int count=0;
    if(statement.size()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
   
    for(int i=0;i<=statement.size;i++)
    {
        
    }
}



void wordBreak_Crypto()
{
    vector<string> dict = {"mobile","samsung","sam","sung","main","mango","icecream","and","go","i","like","ice","cream"};
    string str="ilikesamsung";
    cout<<wordBreak(dict,str,"")<<endl;
}


int main(int args,char** argv)
{
    solve();
    return 0;
}
