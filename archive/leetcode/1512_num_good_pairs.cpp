#include <iostream>
#include <map>
#include <vector>

class Solution {
  public:
  static int numIndenticalPairs(std::vector<int> &nums) {
    std::map<int, int> numMap;
    long totalPairs = 0;
    for (uint idx = 0u; idx < nums.size(); ++idx) {
      totalPairs += numMap[nums[idx]];
      numMap[nums[idx]]++;
    }
  return totalPairs;
  };
};

int main() {
  std::vector<int> nums;
  int t, x;
  std::cin >> t;

  while (t--) {
    std::cin>>x;
    nums.push_back(x);
  }
  std::cout<< Solution::numIndenticalPairs(nums) << std::endl;
  return 0;
}
