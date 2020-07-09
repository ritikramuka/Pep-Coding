#include<iostream>
#include<string>

using namespace std;

void subsequence(string que, string ans)
{
    if(que.length()==0)
    {
        cout<<ans<<" ";
        return;
    }
    char ch=que[0];
    que=que.substr(1);

    subsequence(que,ans+ch);//coming situation
     subsequence(que,ans);
}

void solve()
{
    subsequence("123","");
}

int main (int args,char** argv)
{
    solve();
    return 0;
}