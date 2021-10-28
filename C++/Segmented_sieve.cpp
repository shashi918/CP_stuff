//Segmented Sieve
#include<bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;
vector<int> genPrimes(int n) {
  bool sieve[n + 1];
  for (int i = 0; i <=n; i++) {
    sieve[i] = true;
  }
  for (int i = 2; i * i <= n; i++) {
    if (sieve[i] == true) {
      for (int j = i * i; j <= n; j += i)
        sieve[j] = false;
    }
}
  vector<int> ret;
  for (int i = 2; i <= n; i++)
    if (sieve[i] == true)
      ret.push_back(i);
  return ret;
}
void segmentedSieve(int a, int b) {
  vector<int> primes = genPrimes(sqrt(b));
  int arrLen = b - a + 1;
  bool arr[arrLen];
  for (int i = 0; i <= arrLen; i++)
    arr[i] = false;
  for (auto prime : primes) {
    int multiple = ceil((a * 1.0) / prime);
    if (multiple == 1)
      multiple++;
    int index = multiple * prime - a;
    for (int j = index; j < arrLen; j += prime) {
      arr[j] = true;
    }
  }
  for (int i = 0; i < arrLen; i++) {
    if (arr[i] == false && i + a != 1) {
      int val = i +a;
      cout<<val<<" ";
    }
  }
}
int main() {
  int a = 2, b = 100;
  segmentedSieve(a,b);
}