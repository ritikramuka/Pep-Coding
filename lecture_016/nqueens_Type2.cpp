#include<iostream>
#include<vector>
using namespace std;

int nqueens_1(vector<vector<bool>>& box,int qpsf,int tnq,string ans)//no constrains for any queen, but only one at one pos....
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<box.size()*box[0].size();i++)
    {
        int r=i/box[0].size();         //converting 1D to 2D dimensions!!!
        int c=i%box.size();
        if(!box[r][c])
        {
            box[r][c]=true;
            count+=nqueens_1(box,qpsf+1,tnq,ans+"q"+to_string(qpsf+1)+"b"+to_string(i+1)+" ");
            box[r][c]=false;
        }
    }
    return count;
}

int nqueensComb_1(vector<vector<bool>>& box,int idx,int qpsf,int tnq,string ans)//no constrains for any queen, but only one at one pos....
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<box.size()*box[0].size();i++)
    {
        int r=i/box[0].size();         //converting 2D from 1D dimensions!!!
        int c=i%box.size();
        if(!box[r][c])
        {
            box[r][c]=true;
            count+=nqueensComb_1(box,i+1,qpsf+1,tnq,ans+"q"+to_string(qpsf+1)+"b"+to_string(i+1));
            box[r][c]=false;
        }
    }
    return count;
}

bool isvalidLocation(int sr, int sc, vector<vector<bool>> &boxes)
{
    if (sr >= boxes.size() || sc >= boxes[0].size() || sr < 0 || sc < 0)
    {
        return false;
    }
    return true;
}

bool isValidToPlaceQueen(vector<vector<bool>> &boxes, int sr, int sc)
{
    int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    for (int rad = 1; rad < boxes.size(); rad++)
    {
        for (int dirItr = 0; dirItr < 8; dirItr++)
        {
            int r = sr + rad * dir[dirItr][0];
            int c = sc + rad * dir[dirItr][1];
            if (isvalidLocation(boxes, r, c) && boxes[r][c])
            {
                return false;
            }
        }
    }

    return true;
}

int Nqueen_01(vector<vector<bool>> &boxes, int vidx, int qpsf, int tnq, string ans)
{

    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = vidx; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();
        if (!boxes[r][c] && isValidToPlaceQueen(boxes, r, c))
        {
            boxes[r][c] = true;
            count += Nqueen2DCombination(boxes, i + 1, qpsf + 1, tnq, ans + "q" + to_string(qpsf + 1) + "b" + to_string(i + 1) + " ");
            boxes[r][c] = false;
        }
    }

    return count;
}

void solve()
{
    vector<vector<bool>>box(3,vector<bool>(3,false));
    //cout<<nqueens_1(box,0,4,"");
    cout<<nqueensComb_1(box,0,0,4,"");
}

int main(int args,char**argv)
{
    solve();
}