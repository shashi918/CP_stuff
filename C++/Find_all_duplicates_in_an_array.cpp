// Find All Duplicates in an Array

/*
Given an integer array nums of length n where all the integers of nums are in
the range [1, n] and each integer appears once or twice, return an array of all
the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra
space.



Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:

Input: nums = [1,1,2]
Output: [1]

Example 3:

Input: nums = [1]
Output: []


*/

#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
  map<int, int> temp;
  vector<int> ans;
  for (auto it : nums) {
    temp[it]++;
  }
  for (auto it : temp) {
    if (it.second > 1) ans.push_back(it.first);
  }
  return ans;
}
int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> ans = findDuplicates(nums);
  for (auto it : ans) cout << it << endl;
}