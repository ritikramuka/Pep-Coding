#include <iostream>
#include <vector>
#include<string>

using namespace std;

bool isSafeToPlace(vector<vector<bool>> boxes, int row, int col)
{
    vector<vector<int>> Qdir = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}};
    for (int d = 0; d < Qdir.size(); d++)
    {
        for (int rad = 1; rad <= boxes.size(); rad++)
        {
            int r = row + rad * Qdir[d][0];
            int c = col + rad * Qdir[d][1];

            if (r >= 0 && c >= 0 && r < boxes.size() && c < boxes[0].size())
            {
                if (boxes[r][c])
                    return false;
            }
            else
                break;
        }
    }
    return true;
}

int nqueens_01(vector<vector<bool>> boxes, int idx, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes.size();
        int y = i % boxes.size();

        if (isSafeToPlace(boxes, x, y))
        {
            boxes[x][y] = true;
            count += nqueens_01(boxes, i + 1, qpsf + 1, tnq, ans + to_string(qpsf + 1) + "(" + to_string(x) + "," + to_string(y) + ")");
            boxes[x][y] = false;
        }
    }
    return count;
}

int queens2Dcomb(vector<vector<bool>> boxes, int idx, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes.size();
        int y = i % boxes.size();

        count += queens2Dcomb(boxes, i + 1, qpsf + 1, tnq, ans + to_string(qpsf + 1) + "(" + to_string(x) + "," + to_string(y) + ")");
    }
    return count;
}

int queens2Dper(vector<vector<bool>> boxes, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes.size();
        int y = i % boxes.size();
        if (!boxes[x][y])
        {
            boxes[x][y] = true;
            count += queens2Dper(boxes, qpsf + 1, tnq, ans + to_string(qpsf + 1) + "(" + to_string(x) + "," + to_string(y) + ")");
            boxes[x][y] = false;
        }
    }
    return count;
}

void queens()
{
    // vector<vector<bool>> boxes(4, vector<bool>(4, false));
    // cout << queens2Dcomb(boxes, 0, 0, 2, "");
    // cout << queens2Dper(boxes, 0, 2, "");
    // cout << nqueens_01(boxes, 0, 0, 4, "");
}

string str1 = "more";
string str2 = "send";
string str3 = "money";
vector<int> mapping(26, 0);
int numused = 0;


int numToChar(string& str)
{
    int res=0;
    for(int i=0;i<str.length();i++)
    {
        res=res*10+mapping[str[i]-'a'];
    }
    return res;
}

int crypto_(string& str, int idx)
{
    if (idx==str.length())
    {
        int a = numToChar(str1);
        int b = numToChar(str2);
        int c = numToChar(str3);

        if (a + b == c)
        {
            cout << " " << a << endl;
            cout << "+" << b << endl;
            cout << "------" << endl;
            cout << c;
            cout << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    for (int num = 0; num <= 9; num++)
    {
        int mask = (1 << num);
        if ((numused & mask) == 0)
        {
            numused ^= mask;
            mapping[str[idx] - 'a'] = num;

            count += crypto_(str, idx + 1);

            numused ^= mask;
            mapping[str[idx] - 'a'] = 0;
        }
    }
    return count;
}


void crypto()
{
    string str = str1 + str2 + str3;
    int freq = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int mask = (1 << (str[i] - 'a'));
        if   ((freq & mask) == 0)
        {
            freq |= mask;
        }
    }

    str = "";

    for (int idx = 0; idx < 26; idx++)
    {
        int mask=(1<<idx);
        if ((mask & freq) != 0)
        {
            str += (char)('a'+idx);
        }
    }
    cout<<crypto_(str,0);
}

void solve()
{
    queens();
    crypto();
}

int main()
{
    solve();
    return 0;
}
            