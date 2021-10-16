// Find the odd int
/*
Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.
Examples

[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is
odd).
*/
#include <vector>
#include <bits/stdc++.h>
#include <vector>

int findOdd(const std::vector<int> &numbers) {
  for (int i = 0; i < numbers.size(); i++) {
    int count = 0;
    for (int j = 0; j < numbers.size(); j++) {
      if (numbers[i] == numbers[j])
        count++;
    }
    if (count % 2 == 1)
      return numbers[i];
  }
}

int main() {
  std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1};
  int ans = findOdd(nums);
  std::cout<<ans;
}
