/*Count Negative Numbers in a Sorted Matrix
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    -100 <= grid[i][j] <= 100

 
Follow up: Could you find an O(n + m) solution?
*/
#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int ans = 0;
    int i = 0, j = grid[0].size()-1;
    for (i; i < grid[0].size(); i++)
    {
        for (j; j >= 0;)
        {
            if (grid[i][j] < 0)
            {
                while ( j>= 0 && grid[i][j] < 0)
                {
                    ans += grid.size() - i;
                    j--;
                }
            }
            break;
        }
    }
    return ans;
}

int main()
{   vector<vector<int>> arr = {{5,1,0},{-5,-5,-5}};
    //vector<vector<int>> arr = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int ans = countNegatives(arr);
    cout<<ans<<"\n";
}