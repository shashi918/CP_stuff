//Cut Ribbon
/*
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

    After the cutting each ribbon piece should have length a, b or c.
    After the cutting the number of ribbon pieces should be maximum. 

Help Polycarpus and find the number of ribbon pieces after the required cutting.
Input

The first line contains four space-separated integers n, a, b and c (1 ≤ n, a, b, c ≤ 4000) — the length of the original ribbon and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.
Output

Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.
Examples
Input
Copy

5 5 3 2

Output
Copy

2

Input
Copy

7 5 5 2

Output
Copy

2

Note

In the first example Polycarpus can cut the ribbon in such way: the first piece has length 2, the second piece has length 3.

In the second example Polycarpus can cut the ribbon in such way: the first piece has length 5, the second piece has length 2.

*/
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
vector<int> arr(4001, 0);
int dp(int n, int a, int b, int c) {
  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;
  if (arr[n] != 0)
    return arr[n];
  return arr[n] = 1 + max(dp(n - a, a, b, c),
                          max(dp(n - b, a, b, c), dp(n - c, a, b, c)));
}

void solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int ans = dp(n, a, b, c);
  cout << ans << "\n";
}

int main() { solve(); }

