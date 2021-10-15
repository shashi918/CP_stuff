// Sieve of Eratosthenes


#include <bits/stdc++.h>
using namespace std;
#define N 1001
bool sieve[N];
void createSieve() {
  for (int i = 2; i <= N; i++) {
    sieve[i] = true;
  }
  for (int i = 2; i * i <= N; i++) {
    if (sieve[i] == true) {
      for (int j = i * i; j <= N; j += i) {
        sieve[j] = false;
      }
    }
  }
}
int main() {
  createSieve();
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    if (sieve[a] == true) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}