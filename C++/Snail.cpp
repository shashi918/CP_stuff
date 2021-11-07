// snail
/*
Given an n x n array, return the array elements arranged from outermost elements
to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]

For better understanding, please follow the numbers of the next array
consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

This image will illustrate things more clearly:

NOTE: The idea is not sort the elements from the lowest value to the highest;
the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array
[[]].
*/
#include <bits/stdc++.h>
using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  std::vector<int> ans;
  if (snail_map.size() == 0)
    return {};
  if (snail_map.size() == 1) {
    for (auto i : snail_map) {
      for (auto j : i) {
        ans.push_back(j);
      }
    }
    return ans;
  }
  int dir = 0;
  int top = 0, bottom = snail_map.size() - 1, left = 0,
      right = snail_map.size() - 1;
  while (top <= bottom && left <= right) {
    if (dir == 0) {
      for (int i = left; i <= right; i++) {
        ans.push_back(snail_map[top][i]);
      }
      top++;
    } else if (dir == 1) {
      for (int i = top; i <= bottom; i++) {
        ans.push_back(snail_map[i][right]);
      }
      right--;
    } else if (dir == 2) {
      for (int i = right; i >= left; i--) {
        ans.push_back(snail_map[bottom][i]);
      }
      bottom--;
    } else if (dir == 3) {
      for (int i = bottom; i >= top; i--) {
        ans.push_back(snail_map[i][left]);
      }
      left++;
    }
    dir = (dir + 1) % 4;
  }
  return ans;
};
int main() {
  std::vector<std::vector<int>> temp = {
      {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
  std::vector<int> ans = snail(temp);
  for (auto i : ans) {
    std::cout << i << " ";
  }
}
