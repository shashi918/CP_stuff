//Grey code
#include <bits/stdc++.h>
#include <codecvt>
#include <string>
#include <vector>
using namespace std;
vector<string> greyCode(int n) {
  if (n == 1) return {"0", "1"};
  vector<string> ans;
  vector<string> temp = greyCode(n - 1);
  for (int i = 0; i < temp.size(); i++) {
    ans.push_back("0"+temp[i]);
  }
  for (int i = temp.size() - 1; i >= 0; i--) {
    ans.push_back("1"+temp[i]);
  }
  return ans;
}
int main() {
  vector<string> ans = greyCode(2);
  for (auto i : ans) {
    cout<<i<<"\n";
  }
}