//Guess Number Higher or Lower
/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

    -1: The number I picked is lower than your guess (i.e. pick < num).
    1: The number I picked is higher than your guess (i.e. pick > num).
    0: The number I picked is equal to your guess (i.e. pick == num).

Return the number that I picked.

 

Example 1:

Input: n = 10, pick = 6
Output: 6

Example 2:

Input: n = 1, pick = 1
Output: 1

Example 3:

Input: n = 2, pick = 1
Output: 1

Example 4:

Input: n = 2, pick = 2
Output: 2

*/

#include <bits/stdc++.h>
using namespace std;
long long guess(long long temp) {
  long long ans = 10;
  if (temp < ans) return 1;
  else if (temp > ans) return -1;
   else return 0;

}
long long guessNumber(int n) {
  long long left = 1;
  long long right = n;
  right += 1;
  while (left < right) {
    long long mid =  (right - left) / 2 +left;
    if (guess(mid) == 1) {
      left = mid;
    } else if (guess(mid) == -1) {
      right = mid;
    } else {
      return mid;
    }
  }
  return 0;
}


int main() {
  long long n = 10;
  cout<<guessNumber(n);
}