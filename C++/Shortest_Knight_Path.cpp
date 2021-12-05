//Shortest Knight Path
/*
Given two different positions on a chess board, find the least number of moves it would take a knight to get from one to the other. The positions will be passed as two arguments in algebraic notation. For example, knight("a3", "b5") should return 1.

The knight is not allowed to move off the board. The board is 8x8.

For information on knight moves, see https://en.wikipedia.org/wiki/Knight_%28chess%29

For information on algebraic notation, see https://en.wikipedia.org/wiki/Algebraic_notation_%28chess%29

(Warning: many of the tests were generated randomly. If any do not work, the test cases will return the input, output, and expected output; please post them.)
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<climits>
void travelKnight(std::vector<std::vector<int>> &, int, int, int, int,int&,int);
int knight(std::string start, std::string finish) {
  std::vector<std::vector<int>> board(9, std::vector<int>(9, 0));
  int startI = start[0] - 'a' + 1;
  int startJ = start[1] - '1' + 1;
  int finishI = finish[0] - 'a' + 1;
  int finishJ = finish[1] - '1' + 1;
  int ans = INT_MAX;
  travelKnight(board, startI, startJ, finishI, finishJ, ans, 0);
  return ans;
}

void travelKnight(std::vector<std::vector<int>>& maze, int startI, int startJ, int finishI,
                 int finishJ,int& ans,int count) {
  if (startI <= 0 || startI >= 9 || startJ <= 0 || startJ >= 9 ||
      maze[startI][startJ] == 1|| count>=ans)
    return;
  if (startJ == finishJ && finishI == startI) {
    if (count < ans)
      ans = count;
    return;
  }
  maze[startI][startJ] = 1;
  count+=1;
  travelKnight(maze, startI - 1, startJ + 2, finishI, finishJ,ans,count);
  travelKnight(maze, startI - 2, startJ + 1, finishI, finishJ,ans,count);
  travelKnight(maze, startI - 1, startJ - 2, finishI, finishJ,ans,count);
  travelKnight(maze, startI - 2, startJ - 1, finishI, finishJ,ans,count);
  travelKnight(maze, startI + 2, startJ +1, finishI, finishJ,ans,count);
  travelKnight(maze, startI + 1, startJ + 2, finishI, finishJ,ans,count);
  travelKnight(maze, startI+1, startJ -2, finishI, finishJ,ans,count);
  travelKnight(maze, startI+2, startJ -1, finishI, finishJ,ans,count);
  maze[startI][startJ] = 0;
  count-=1;
}

int main() {
  std::cout << knight("h6", "g1") << "\n"; // 2
  std::cout << knight("h6", "g2") << "\n"; // 3
  std::cout << knight("h6", "g3") << "\n"; // 3
  std::cout << knight("h6", "g4") << "\n"; // 4
  std::cout << knight("h6", "g5") << "\n"; // 5
  std::cout << knight("h6", "g6") << "\n"; // 5
  std::cout << knight("h6", "g7") << "\n"; // 5
  std::cout << knight("h6", "g8") << "\n"; // 5
  return 0;
}
