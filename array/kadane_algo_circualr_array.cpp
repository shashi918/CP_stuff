#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
    return (a > b);
}
int kadane(vector<int>&);
int maxSubarraySumCircular(vector<int>& nums) {
    int max_kadane = kadane(nums);
    if (max_kadane < 0)
        return max_kadane;
    else {
        int max_wrap = 0;
    for (auto i = nums.begin(); i < nums.end(); i++)
    {
        max_wrap += *i;
        *i = -(*i);
    }
    max_wrap = max_wrap + kadane(nums);
    return (max_wrap > max_kadane) ? max_wrap : max_kadane;
    }
}

int kadane(vector<int>& nums) {
    int max_so_far = 0;
    int max_current = 0;
    std::vector<int>::iterator it;
    for ( it = nums.begin(); it < nums.end(); it++)
    {
       max_current += *it;
       if(max_so_far < max_current)
            max_so_far = max_current;
        if(max_current < 0)
            max_current = 0;
    }
    if(max_so_far <= 0)
        max_so_far = *min_element(nums.begin(),nums.end(),comp);
    return max_so_far;
}

int main() {
    std::vector<int> v ={1,-2,3,-2};
    int n = maxSubarraySumCircular(v);
    printf("%d\n",n);
    return 0;
}

