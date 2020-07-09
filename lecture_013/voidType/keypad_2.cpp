#include<iostream>
#include<string>
#include<vector>

using namespace std;

string getcode(int digit)
    {
         string arr[]={"abc","def","ghi","jkl","mno","pqr","stu","vwx","yz","*+#"};
         return arr[digit];
    }
void keypad(int num, string ans)
{
        if(num==0){
            cout<<ans<<" ";
        }
        int digit=num%10;
        num=num/10;

        string s=getcode(digit);
        for(int i=0;i<s.length();i++)
        {
            keypad=(num,ans + s[i]);
        }
}

void solve()
{
    int n;
    cin>>n;
    keypad(n,"");
}

int main(int args,char**argv)
{
    solve();
    return 0;
}
        
    