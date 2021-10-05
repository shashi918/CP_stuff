// Brian Kernighan’s Algorithm to count set bits in an integer

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 76;
  int count = 0;
  while (a) {
    int temp = a & -a;
    count++;
    a -= temp;
  }
  cout << count;
}