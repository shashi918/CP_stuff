//Median of Two Sorted Arrays
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  if (nums1.size() > nums2.size()) {
    vector<int> temp = nums1;
    nums1 = nums2;
    nums2 = temp;
  }
  int low = 0;
  int high = nums1.size();
  int total = nums1.size() + nums2.size();
  while (low <= high) {
    int nums1partition = (low + high) / 2;
    int nums2partition = (total + 1) / 2 - nums1partition;

    int nums1left = (nums1partition == 0) ? INT_MIN : nums1[nums1partition - 1];
    int nums1right =
        (nums1partition == nums1.size()) ? INT_MAX : nums1[nums1partition];
    int nums2left = (nums2partition == 0) ? INT_MIN : nums2[nums2partition - 1];
    int nums2right =
        (nums2partition == nums2.size()) ? INT_MAX : nums2[nums2partition];

    if (nums1left <= nums2right && nums2left <= nums1right) {
      if (total % 2 == 0) {
        return (max(nums1left,nums2left)+min(nums1right,nums2right))/2.0;
      } else {
        return max(nums1left,nums2left);
      }
    } else if (nums1left > nums2right) {
      high = nums1partition-1;
    } else if (nums2left > nums1right) {
      low = nums1partition +1;
    }
  }
  return 0;
}

int main() {
  vector<int> first = {1,3};
  vector<int> second = {2};
  double ans = findMedianSortedArrays(first, second);
  cout << ans;
}
