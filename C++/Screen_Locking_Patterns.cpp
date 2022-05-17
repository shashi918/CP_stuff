//Screen Locking Patterns
/*
Screen Locking Patterns

You might already be familiar with many smartphones that allow you to use a geometric pattern as a security measure. To unlock the device, you need to connect a sequence of dots/points in a grid by swiping your finger without lifting it as you trace the pattern through the screen.

The image below has an example pattern of 7 dots/points: (A -> B -> I -> E -> D -> G -> C).

lock_example.png

For this kata, your job is to implement a function that returns the number of possible patterns starting from a given first point, that have a given length.

More specifically, for a function countPatternsFrom(firstPoint, length), the parameter firstPoint is a single-character string corresponding to the point in the grid (i.e.: 'A') where your patterns start, and the parameter length is an integer indicating the number of points (length) every pattern must have.

For example, countPatternsFrom("C", 2), should return the number of patterns starting from 'C' that have 2 two points. The return value in this case would be 5, because there are 5 possible patterns:

(C -> B), (C -> D), (C -> E), (C -> F) and (C -> H).

Bear in mind that this kata requires returning the number of patterns, not the patterns themselves, so you only need to count them. Also, the name of the function might be different depending on the programming language used, but the idea remains the same.
Rules

    In a pattern, the dots/points cannot be repeated: they can only be used once, at most.
    In a pattern, any two subsequent dots/points can only be connected with direct straight lines in either of these ways:
    Horizontally: like (A -> B) in the example pattern image.
    Vertically: like (D -> G) in the example pattern image.
    Diagonally: like (I -> E), as well as (B -> I), in the example pattern image.
    Passing over a point between them that has already been 'used': like (G -> C) passing over E, in the example pattern image. This is the trickiest rule. Normally, you wouldn't be able to connect G to C, because E is between them, however when E has already been used as part the pattern you are tracing, you can connect G to C passing over E, because E is ignored, as it was already used once.


The sample tests have some examples of the number of combinations for some cases to help you check your code.

Haskell Note: A data type Vertex is provided in place of the single-character strings. See the solution setup code for more details.

Fun fact:

In case you're wondering out of curiosity, for the Android lock screen, the valid patterns must have between 4 and 9 dots/points. There are 389112 possible valid patterns in total; that is, patterns with a length between 4 and 9 dots/points.

*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

void pathFind(std::map<char, std::vector<char>> &, int &, char, int,
              std::string);

unsigned int countPatternsFrom(char firstDot, unsigned short length) {
  if (length == 0)
    return 0;
  if (length == 1)
    return 1;
  if (length > 9)
    return 0;
  std::map<char, std::vector<char>> paths = {
      {'A', {'B', 'D', 'E', 'H', 'F'}},
      {'B', {'C', 'A', 'D', 'E', 'F', 'G', 'I'}},
      {'C', {'B', 'E', 'F', 'D', 'H'}},
      {'D', {'B', 'E', 'H', 'G', 'C', 'I', 'A'}},
      {'E', {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I'}},
      {'F', {'C', 'E', 'I', 'B', 'H', 'A', 'G'}},
      {'G', {'D', 'E', 'H', 'F', 'B'}},
      {'H', {'G', 'E', 'I', 'D', 'A', 'C', 'F'}},
      {'I', {'B', 'E', 'H', 'D', 'F'}}};
  int ans = 0;
  std::string present(1, firstDot);
  pathFind(paths, ans, firstDot, length - 1, present);
  return ans;
}

void pathFind(std::map<char, std::vector<char>> &paths, int &ans, char firstDot,
              int length, std::string present) {
  if (length <= 0) {
    ans++;
    return;
  } else {
    auto it = paths.find(firstDot);
    if (it != paths.end()) {
      for (int i = 0; i <= it->second.size() - 1; i++) {
        if (present.find(it->second[i]) == std::string::npos) {
          char temp = it->second[i];
          present += temp;
          pathFind(paths, ans, temp, length - 1, present);
          present.pop_back();
        }
      }
    }
  }
  if (present.find('E') != std::string::npos) {
    if (present[present.size() - 1] == 'D' &&
        present.find('F') == std::string::npos) {
      present += 'F';
      pathFind(paths, ans, 'F', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'F' &&
               present.find('D') == std::string::npos) {
      present += 'D';
      pathFind(paths, ans, 'D', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'B' &&
               present.find('H') == std::string::npos) {
      present += 'H';
      pathFind(paths, ans, 'H', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'H' &&
               present.find('B') == std::string::npos) {
      present += 'B';
      pathFind(paths, ans, 'B', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'C' &&
               present.find('G') == std::string::npos) {
      present += 'G';
      pathFind(paths, ans, 'G', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'G' &&
               present.find('C') == std::string::npos) {
      present += 'C';
      pathFind(paths, ans, 'C', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'I' &&
               present.find('A') == std::string::npos) {
      present += 'A';
      pathFind(paths, ans, 'A', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'A' &&
               present.find('I') == std::string::npos) {
      present += 'I';
      pathFind(paths, ans, 'I', length - 1, present);
      present.pop_back();
    }
  }
  if (present.find('D') != std::string::npos) {
    if (present[present.size() - 1] == 'G' &&
        present.find('A') == std::string::npos) {
      present += 'A';
      pathFind(paths, ans, 'A', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'A' &&
               present.find('G') == std::string::npos) {
      present += 'G';
      pathFind(paths, ans, 'G', length - 1, present);
      present.pop_back();
    }
  }
  if (present.find('B') != std::string::npos) {
    if (present[present.size() - 1] == 'A' &&
        present.find('C') == std::string::npos) {
      present += 'C';
      pathFind(paths, ans, 'C', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'C' &&
               present.find('A') == std::string::npos) {
      present += 'A';
      pathFind(paths, ans, 'A', length - 1, present);
      present.pop_back();
    }
  }
  if (present.find('F') != std::string::npos) {
    if (present[present.size() - 1] == 'C' &&
        present.find('I') == std::string::npos) {
      present += 'I';
      pathFind(paths, ans, 'I', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'I' &&
               present.find('C') == std::string::npos) {
      present += 'C';
      pathFind(paths, ans, 'C', length - 1, present);
      present.pop_back();
    }
  }
  if (present.find('H') != std::string::npos) {
    if (present[present.size() - 1] == 'G' &&
        present.find('I') == std::string::npos) {
      present += 'I';
      pathFind(paths, ans, 'I', length - 1, present);
      present.pop_back();
    } else if (present[present.size() - 1] == 'I' &&
               present.find('G') == std::string::npos) {
      present += 'G';
      pathFind(paths, ans, 'G', length - 1, present);
      present.pop_back();
    }
  }
  return;
}

int main() {
  std::cout << countPatternsFrom('B', 1) << "\n";
  std::cout << countPatternsFrom('C', 2) << "\n";
  std::cout << countPatternsFrom('D', 3) << "\n";
  std::cout << countPatternsFrom('E', 4) << "\n";
  std::cout << countPatternsFrom('E', 8) << "\n";
}