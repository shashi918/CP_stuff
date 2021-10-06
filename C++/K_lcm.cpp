// k-LCM (easy version)
/*
  It is the easy version of the problem. The only difference is that in this
  version k=3

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
  int a, t;
  cin >> a >> t;
  if (a % 2 == 1) {
    cout << (a - 1) / 2 << " " << (a - 1) / 2 << " " << 1 << endl;
    return;
  } else {
    if ((a / 2) % 2 == 1) {
      cout << 2 << " " << (a / 2) - 1 << " " << (a / 2) - 1 << endl;
      return;
    } else {
      cout << a / 2 << " " << (a / 2) / 2 << " " << (a / 2) / 2 << endl;
      return;
    }
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}