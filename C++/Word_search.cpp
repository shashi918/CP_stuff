//Word Search
/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

*/


#include <bits/stdc++.h>
using namespace std;
bool explore(vector<vector<char>>& board, string word, int i, int j, int n) {
  if (n == word.size()) return true;
  if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() ||
      board[i][j] != word[n])
    return false;
  board[i][j] = '0';
  bool ans = explore(board, word, i + 1, j, n+1) ||
             explore(board, word, i - 1, j, n+1) ||
             explore(board, word, i, j + 1, n+1) ||
             explore(board, word, i, j - 1, n+1);
  board[i][j] = word[n];
  return ans;
}
bool exist(vector<vector<char>>& board, string word) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] != word[0]) continue;
      bool ans = explore(board, word, i, j, 0);
      if (ans)
        return true;
    }
  }
  return false;
}
int main() {
  vector<vector<char>> board ={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word = "SEE";
  bool ans = exist(board, word);
  if (ans) cout << "true";
  else cout<<"false";
}