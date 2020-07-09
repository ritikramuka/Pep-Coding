#include <iostream>
#include <vector>

using namespace std;

void display1D(vector<int> &arr)
{
    for (int e : arr)
        cout << e << " ";
    cout << endl;
}

void display2D(vector<vector<int>> &arr)
{
    for (vector<int> &e : arr)
    {
        for (int m : e)
            cout << m << " ";
        cout << endl;
    }
}

int mazePath2(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    for (int jump = 1; sr + jump <= er; jump++)
        count += mazePath2(sr + jump, sc, er, ec, dp);

    for (int jump = 1; sc + jump <= ec; jump++)
        count += mazePath2(sr, sc + jump, er, ec, dp);

    for (int jump = 1; sc + jump <= ec && sr + jump <= er; jump++)
        count += mazePath2(sr + jump, sc + jump, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazePath2DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            for (int jump = 1; sr + jump <= er; jump++)
                count += dp[sr + jump][sc];

            for (int jump = 1; sc + jump <= ec; jump++)
                count += dp[sr][sc + jump];

            for (int jump = 1; sc + jump <= ec && sr + jump <= er; jump++)
                count += dp[sr + jump][sc + jump];

            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

int dice1(int curSum, int tar, vector<int> &dp)
{
    if (curSum == tar)
        return dp[curSum] = 1;

    if (dp[curSum] != 0)
        return dp[curSum];

    int count = 0;
    for (int i = 1; i <= 6 && curSum + i <= tar; i++)
        count += dice1(curSum + i, tar, dp);

    return dp[curSum] = count;
}

int dice1DP(int curSum, int tar, vector<int> &dp)
{
    for (curSum = tar; curSum >= 0; curSum--)
    {
        if (curSum == tar)
        {
            dp[curSum] = 1;
            continue;
        }

        int count = 0;
        for (int i = 1; i <= 6 && curSum + i <= tar; i++)
            count += dp[curSum + i];

        dp[curSum] = count;
    }
    return dp[0];
}

//friends pair problem.=================================================

int friendPair(int n, vector<int> &dp)
{
    if (n < 2)
        return dp[n] = 1;

    if (dp[n] != 0)
        return dp[n];

    int single = friendPair(n - 1, dp);
    int pair = friendPair(n - 2, dp) * (n - 1);

    return dp[n] = (single + pair);
}

int friendPair_DP(int n, vector<int> &dp)
{
    int N = n;
    for (n = 0; n <= N; n++)
    {
        if (n < 2)
        {
            dp[n] = 1;
            continue;
        }

        if (dp[n] != 0)
            return dp[n];

        int single = dp[n - 1];
        int pair = dp[n - 2] * (n - 1);

        dp[n] = (single + pair);
    }
    return dp[N];
}

int friendPair_best(int n) //two pointer approch
{
    int N = n;
    int prev = 1, curr = 1;
    for (n = 2; n <= N; n++)
    {
        int next = curr + prev * (n - 1);
        prev = curr;
        curr = next;
    }
    return curr;
}

//gold Mine.===========================================================

int goldMine(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }

    int maxCoins = 0;
    int dir[3][2] = {{-1, 1}, {1, 1}, {0, 1}};

    for (int i = 0; i < 3; i++)
    {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
        {
            maxCoins = max(maxCoins, goldMine(x, y, grid, dp));
        }
    }

    return dp[sr][sc] = maxCoins + grid[sr][sc];
}

void goldMine_DP(vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int dir[3][2] = {{-1, 1}, {1, 1}, {0, 1}};

    for (int sc = grid[0].size() - 1; sc >= 0; sc--)
    {
        for (int sr = grid.size() - 1; sr >= 0; sr--)
        {
            if (sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int maxCoins = 0;
            for (int i = 0; i < 3; i++)
            {
                int x = sr + dir[i][0];
                int y = sc + dir[i][1];
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
                {
                    maxCoins = max(maxCoins, dp[x][y]);
                }
            }

            dp[sr][sc] = maxCoins + grid[sr][sc];
        }
    }
    int maxCoin = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        maxCoin = max(maxCoin, dp[i][0]);
    }
    cout << maxCoin << endl;
}

//https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

int partitionWays(int n, int k, vector<vector<int>> &dp)
{
    if (n == 0 || k == 0 || k > n)
        return dp[n][k] = 0;

    if (k == 1 || k == n)
        return dp[n][k] = 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    int count = 0;
    count = k * partitionWays(n - 1, k, dp) + partitionWays(n - 1, k - 1, dp);

    return dp[n][k] = count;
}

// int OptimalBinarySearchTree(vector<int> &key, int si, int ei, int level, vector<vector<int>> &dp)
// {
//     if (si + 1 == ei)
//         return level*key[si];

//     if (dp[si][ei] != 0)
//         return dp[si][ei];

//     int ans = (int)1e8;
//     for (int cut = si + 1; cut < ei; ++cut)
//     {
//         int leftans = OptimalBinarySearchTree(key, si, cut, level + 1, dp);
//         int rightans = OptimalBinarySearchTree(key, cut, ei, level + 1, dp);
//         int myans = leftans + level * key[ei] + rightans;
//         if (myans < ans)
//             ans = myans;
//     }

//     return dp[si][ei] = ans;
// }

//ques set.=============================================================

void set6()
{
    vector<int> key = {34, 8, 50};
    int n = key.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout << OptimalBinarySearchTree(key, 0, n - 1, 1, dp) << endl;
    display2D(dp);
}

// void set5()
// {
//     int n = 4, k = 2;
//     vector<vector<int>> DP(n + 1, vector<int>(k + 1, -1));
//     cout << PartitionWays(n, k, DP) << endl;
//     display2D(DP);
// }

void set4()
{
    vector<vector<int>> grid = {{1, 3, 1, 5},
                                {2, 2, 4, 1},
                                {5, 0, 2, 3},
                                {0, 6, 1, 2}};
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    // int maxCoins = 0;
    // for (int i = 0; i < grid.size(); i++)
    // {
    //     maxCoins = max(maxCoins, goldMine(i, 0, grid, dp));
    // }
    // cout << maxCoins << endl;
    goldMine_DP(grid, dp);
    display2D(dp);
}

void set3()
{
    int n = 9;
    vector<int> dp(n + 1, 0);
    // cout << friendPair(n, dp) << endl;
    cout << friendPair_DP(n, dp) << endl;
    display1D(dp);
    cout << friendPair_best(n) << endl;
}

void set2()
{
    int tar = 10;
    vector<int> dp(tar + 1, 0);
    // cout<<dice1(0,tar,dp)<<endl;
    cout << dice1DP(0, tar, dp) << endl;
    display1D(dp);
}

void set1()
{
    int n = 3, m = 3;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // cout << mazePath2(n, 0, 0, n - 1, m - 1, dp) << endl;
    cout << mazePath2DP(0, 0, n - 1, m - 1, dp) << endl;
    display2D(dp);
}

void solve()
{
    // set1();
    // set2();
    // set3();
    // set4();
    // set5();
    set6();
}

int main()
{
    solve();
    return 0;
}