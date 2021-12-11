//Domino and Tromino Tiling
/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:

Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:

Input: n = 1
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

int numTilings(int n) {
  if(n==1)
  return 1;
  if (n == 2)
    return 2;
  int mod = 1000000007;
  int arr[n + 1];
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 5;
  for (int i = 4; i <= n; i++) {
    arr[i] = (2* arr[i-1] % mod + arr[i-3] % mod)%mod;
  }
  return arr[n];
}

int main() {
  cout << numTilings(3) << "\n";
  cout << numTilings(4) << "\n";
  cout << numTilings(5) << "\n";
  
}