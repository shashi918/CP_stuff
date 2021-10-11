// Lucky Ticket
/*
Petya loves lucky numbers very much. Everybody knows that lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya loves tickets very much. As we know, each ticket has a number that is a positive integer. Its length equals n (n is always even). Petya calls a ticket lucky if the ticket's number is a lucky number and the sum of digits in the first half (the sum of the first n / 2 digits) equals the sum of digits in the second half (the sum of the last n / 2 digits). Check if the given ticket is lucky.
Input

The first line contains an even integer n (2 ≤ n ≤ 50) — the length of the ticket number that needs to be checked. The second line contains an integer whose length equals exactly n — the ticket number. The number may contain leading zeros.
Output

On the first line print "YES" if the given ticket number is lucky. Otherwise, print "NO" (without the quotes).
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;
void solve() {
  int len;
  cin >> len;
  string s;
  cin >> s;
  int first = 0;
  int second = 0;
  for (int i = 0; i < len / 2; i++) {
    if ((s[i] == '4' || s[i] == '7') &&
        (s[len + (-1 - i)] == '4' || s[len + (-1 - i)] == '7')) {
      first += (int)(s[i] - '0');
      second += (int)(s[len + (-1 - i)] - '0');
    } else {
      cout << "NO"
           << "\n";
      return;
    }
  }

  if (first == second)
    cout << "YES"
         << "\n";
  else {
    cout << "NO"
         << "\n";
  }
}
int main() { solve(); }
