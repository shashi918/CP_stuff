//Range Extraction
/*
A format for expressing an ordered list of integers is to use a comma separated list of either

    individual integers
    or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"

Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:

range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
// returns "-6,-3-1,3-5,7-11,14,15,17-20"

Courtesy of rosettacode.org

*/
#include <iostream>
#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string ans = "";
  ans += std::to_string(args[0]);
  int counter = args[0];
  int flag = 0;
  for (int i = 1; i <= args.size() - 1; i++) {
    if (counter + 1 == args[i]) {
      flag++;
      counter++;
      if (i == args.size() - 1) {
        if (flag > 1)
          ans = ans + "-" + std::to_string(counter);
        if (flag == 1)
          ans = ans + "," + std::to_string(counter);
        return ans;
      }
    } else if (flag > 1) {
      ans = ans + "-" + std::to_string(counter) + "," + std::to_string(args[i]);
      counter = args[i];
      flag = 0;
    } else {
      if (flag == 1)
        ans = ans + "," + std::to_string(counter);
      ans = ans + "," + std::to_string(args[i]);
      counter = args[i];
      flag=0;
    }
  }

  return ans;
}
int main() {
  std::cout << range_extraction({-6, -3, -2, -1, 0,  1,  3,  4,  5,  7,
                                 8,  9,  10, 11, 14, 15, 17, 18, 19, 20})
            << "\n"; //-6,-3-1,3-5,7-11,14,15,17-20
  std::cout << range_extraction({-3, -2, -1, 2, 10, 15, 16, 18, 19, 20})
            << "\n"; //-3--1,2,10,15,16,18-20
  std::cout << range_extraction({72, 73, 76, 79, 80, 81, 82, 85})
            << "\n"; // 72,73,76,79-82,85
}

// std::string range_extraction(std::vector<int> args) {
//   for(auto i : args) {
//     std::cout<<i<<"\t";
//   }
//   std::cout<<"\n";
//   std::string ans = "";
//   ans += std::to_string(args[0]);
//   int counter = args[0];
//   int flag = 0;
//   for (int i = 1; i <= args.size() - 1; i++) {
//     if (counter + 1 == args[i]) {
//       flag++;
//       counter++;
//       if (i == args.size() - 1) {
//         if (flag > 1)
//           ans = ans + "-" + std::to_string(counter);
//         if (flag == 1)
//           ans = ans + "," + std::to_string(counter);
//         return ans;
//       }
//     } else if (flag > 1) {
//       ans = ans + "-" + std::to_string(counter) + "," +
//       std::to_string(args[i]); counter = args[i]; flag= 0;
//     } else {
//       if(flag==1)
//         ans = ans + "," + std::to_string(counter);
//         ans = ans + "," + std::to_string(args[i]);
//       counter = args[i];
//     }
//   }

//   return ans;
// }

// - 79,
//     -77, -73 --67, -65, -63, -60, -58 --54, -51 --49, -47 --45, -42 --36,
//     -34 --32, -30, -28, -24 --20, -18 --15, -13 --10, -8, -7, -4, -3, 0, 1,
//     6 - 8,
//     11 - 13

//         - 79,
//     -77, -73 --67, -65, -63, -60, -58 --54, -51 --49, -47 --45, -42 --36,
//     -34 --32, -30, -28, -24 --20, -18 --15, -13 --10, -8, -7, -4 --3, 0, 1,
//     6 - 8,
//     11 - 13
