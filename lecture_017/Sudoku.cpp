#include<iostream>
#include<vector>
using namespace std;

void sudokuSolve(vector<vector<bool>>& isAv,vector<vector<bool>>& sudoku,int r,int c,vector<vector<int>>& ans)
{
    if(r==sudoku[0].size() && c==sudoku.size() || !isAv || !is
    {
    }
    for(r=0;r<sudoku[0].size() && isAv[r][c];r++)
    {
        for(c=0;c<sudoku.size() && isAv[r][r];c++)
        {
            for(int m=1;m<=9;m++)
            {
                if(isvalid(r,c,isAv))
                {
                    sudokuSolve(isAv,sudoku,r,c,ans[r][c]=m);
                }
            }
        }
    }
    return;
}

void solve()
{
    vector<vector<bool>>isAv(8,vector<bool>(8,0));
    vector<vector<int>>sudoku=
    sudokuSolve(sudoku,0,0);
}

int main(int args,char**argv)
{
    solve();
}