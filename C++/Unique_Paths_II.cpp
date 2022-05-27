
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int find(vector<vector<int>>& mat, int i, int j,vector<vector<int>>&dp) {
    if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || mat[i][j] == 1) {
        return 0;
    }
    if (i == mat.size()-1 && j == mat[0].size()-1) {
        return 1;
    }
    if (dp[i][j]) return dp[i][j];
    return dp[i][j] = find(mat, i + 1, j, dp) + find(mat, i, j + 1, dp);
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
    return find(obstacleGrid, 0, 0,dp);
}
int main() {
    {
        vector<vector<int>> arr = {{0, 1}, {0, 0}};
        cout << uniquePathsWithObstacles(arr);
    }
    {
        vector<vector<int>> arr = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        cout << uniquePathsWithObstacles(arr);
    }
}