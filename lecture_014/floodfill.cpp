#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int sr, int sc, vector<vector<int>> &isvisited)
{
    if (sr >= isvisited.size() || sc >= isvisited[0].size() || sr < 0 || sc < 0 || isvisited[sr][sc] == 2 || isvisited[sr][sc] == 10)
    {
        return false;
    }
    return true;
}

int floodfill(int sr, int sc, int dr, int dc, vector<vector<int>> &isvisited, string ans)
{

    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    isvisited[sr][sc] = 2;

    //left.
    if (isvalid(sr, sc - 1, isvisited))
        count += floodfill(sr, sc - 1, dr, dc, isvisited, ans + "L");

    //right.
    if (isvalid(sr, sc + 1, isvisited))
        count += floodfill(sr, sc + 1, dr, dc, isvisited, ans + "R");
    // Down.
    if (isvalid(sr + 1, sc, isvisited))
        count += floodfill(sr + 1, sc, dr, dc, isvisited, ans + "D");

    //upward
    if (isvalid(sr - 1, sc, isvisited))
        count += floodfill(sr - 1, sc, dr, dc, isvisited, ans + "U");

    isvisited[sr][sc] = 0;
    return count;
}

int floodfillEightDir(int sr, int sc, int dr, int dc, vector<vector<int>> &isvisited, string ans)
{

    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    isvisited[sr][sc] = 2;

    //left.
    if (isvalid(sr, sc - 1, isvisited))
        count += floodfillEightDir(sr, sc - 1, dr, dc, isvisited, ans + "L");

    //right.
    if (isvalid(sr, sc + 1, isvisited))
        count += floodfillEightDir(sr, sc + 1, dr, dc, isvisited, ans + "R");
    // Down.
    if (isvalid(sr + 1, sc, isvisited))
        count += floodfillEightDir(sr + 1, sc, dr, dc, isvisited, ans + "D");

    //upward
    if (isvalid(sr - 1, sc, isvisited))
        count += floodfillEightDir(sr - 1, sc, dr, dc, isvisited, ans + "U");

    //left-up
    if (isvalid(sr - 1, sc - 1, isvisited))
        count += floodfillEightDir(sr - 1, sc - 1, dr, dc, isvisited, ans + "1");
    //left-down
    if (isvalid(sr + 1, sc - 1, isvisited))
        count += floodfillEightDir(sr + 1, sc - 1, dr, dc, isvisited, ans + "2");

    //right-up
    if (isvalid(sr - 1, sc + 1, isvisited))
        count += floodfillEightDir(sr - 1, sc + 1, dr, dc, isvisited, ans + "3");

    //right-down
    if (isvalid(sr + 1, sc + 1, isvisited))
        count += floodfillEightDir(sr + 1, sc + 1, dr, dc, isvisited, ans + "4");

    isvisited[sr][sc] = 0;
    return count;
}

int floodfillEightDirusingloops(int sr, int sc, int dr, int dc, vector<vector<int>> &isvisited, string ans)
{

    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    
    char dirval[]={'R','U','L','D','1','2','3','4'};
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    
    isvisited[sr][sc] = 2;
    for(int dirItr=0;dirItr<8;dirItr++)
    {
        int r=sr+dir[dirItr][0];
        int c=sc+dir[dirItr][1];

        if (isvalid(r, c, isvisited))
        count += floodfillEightDirusingloops(r, c, dr, dc, isvisited, ans + dirval[dirItr]);
    }

    isvisited[sr][sc] = 0;
    return count;
}

int floodfillEightDirusingloopsmulti(int sr, int sc, int dr, int dc, vector<vector<int>> &isvisited, string ans)
{

    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    
    char dirval[]={'R','U','L','D','r','u','l','d'};
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    
    isvisited[sr][sc] = 2;
    for(int rad=1;rad<dir.size();rad++)
    {
        for(int dirItr=0;dirItr<8;dirItr++)
    {
        int r=sr+rad*dir[dirItr][0];
        int c=sc+rad*dir[dirItr][1];
        if (isvalid(r, c, isvisited))
        count += floodfillEightDirusingloopsmulti(r, c, dr, dc, isvisited, ans + dirval[dirItr] + to_string(rad));
    }
    }

    isvisited[sr][sc] = 0;
    return count;
}


int floodFillVariation()
{
    //vector<vector<int>> isvisited(3, vector<int>(3, false));

    vector<vector<int>> isvisited = { {0, 0, 0},
                                      {0, 10, 0},
                                     {10, 0, 0}, };

    //cout << floodfill(0, 0, 2, 2, isvisited, "") << endl;
    //cout << floodfillEightDir(0, 0, 2, 2, isvisited, "") << endl;
    //cout << floodfillEightDirusingloops(0, 0, 2, 2, isvisited, "") << endl;
    cout << floodfillEightDirusingloopsmulti(0, 0, 2, 2, isvisited, "") << endl;
}

void solve()
{
    floodFillVariation();
}

int main(int args,char** argv)
{
    solve();
    return 0;
}