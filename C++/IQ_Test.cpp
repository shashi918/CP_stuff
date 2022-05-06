/* IQ Test
In the city of Ultima Thule job applicants are often offered an IQ test.

The test is as follows: the person gets a piece of squared paper with a 4 × 4 square painted on it. Some of the square's cells are painted black and others are painted white. Your task is to repaint at most one cell the other color so that the picture has a 2 × 2 square, completely consisting of cells of the same color. If the initial picture already has such a square, the person should just say so and the test will be completed.

Your task is to write a program that determines whether it is possible to pass the test. You cannot pass the test if either repainting any cell or no action doesn't result in a 2 × 2 square, consisting of cells of the same color.
Input

Four lines contain four characters each: the j-th character of the i-th line equals "." if the cell in the i-th row and the j-th column of the square is painted white, and "#", if the cell is black.
Output

Print "YES" (without the quotes), if the test can be passed and "NO" (without the quotes) otherwise.
Examples
Input
Copy

####
.#..
####
....

Output
Copy

YES

Input
Copy

####
....
####
....

Output
Copy

NO

Note

In the first test sample it is enough to repaint the first cell in the second row. After such repainting the required 2 × 2 square is on the intersection of the 1-st and 2-nd row with the 1-st and 2-nd column.

*/
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;
#define int long long
void solve() {
  map<char, int> a;
  char table[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> table[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[table[i][j]]++;
      a[table[i][j + 1]]++;
      a[table[i + 1][j]]++;
      a[table[i + 1][j + 1]]++;
      if (a['#'] > a['.'] || a['#'] < a['.']) {
        cout << "YES";
        return;
      }
    }
  }
  cout << "NO";
}
signed main() { solve(); }
/*
https://cfviz.netlify.app/





# # # #
# # . .
# # # #
. . . .

*/
