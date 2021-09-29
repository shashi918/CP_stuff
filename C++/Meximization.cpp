// Meximization

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
void solve() {
  vector<int> temp;
  int arr[102];
  std::fill(arr,arr+102,-1);
  int n;
  cin >> n;
  int in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    if (arr[in] == -1)
      arr[in] = in;
    else
      temp.push_back(in);
  }
  for (int i = 0; i < 101; i++) {
    if (arr[i] == -1) continue;
    else
      cout << arr[i] << " ";
  }
  for (auto i : temp) cout << i << " ";
  cout << "\n";
  return;

}
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
