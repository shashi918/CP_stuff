// Right Most Set Bit

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 32;
  int ans = a & -a;
  cout<<ans;
}