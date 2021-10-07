//k-LCM (hard version)
/*
It is the hard version of the problem. The only difference is that in this version 3≤k≤n

.

You are given a positive integer n
. Find k positive integers a1,a2,…,ak

, such that:

    a1+a2+…+ak=n

LCM(a1,a2,…,ak)≤n2

Here LCM
is the least common multiple of numbers a1,a2,…,ak

.

We can show that for given constraints the answer always exists.
*/

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int onceCount = k-3;
  for (int i = 1; i <=onceCount; i++) cout << 1 << " ";
  n = n - onceCount;
  if (n % 2 == 1) {
    cout << (n - 1) / 2 << " " << (n - 1) / 2 <<" "<< "1"
         << "\n";
  } else {
    if (n % 2 == 0) {
      if ((n / 2) % 2 == 1) {
        cout << (n / 2) - 1 << " " << (n / 2) - 1 << " "
             << "2"
             << "\n";
        return;
      } else {
        cout << (n / 2) << " " << (n / 2) / 2 << " " << n / 2 << "\n";
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while(t--)
  solve();
}