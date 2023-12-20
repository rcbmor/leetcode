
#include <vector>
#include <ostream>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution2 {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> seen;
		for(auto i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if(seen.count(complement))
				return {seen[complement], i};
			seen[nums[i]] = i;
		}
		return {}; // no pair found
	}
};


class Solution {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for(auto i = 0; i < nums.size()-1; i++)
			for(auto j = i+1; j < nums.size(); j++)
				if(target == nums[i]+nums[j]) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
		return result;
	}
};

void print_vector(const std::vector<int>& vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << vec[i];
  }
  std::cout << "]";
}

int main(int argc, const char* argv[])
{
	vector<int> test0 = {2,7,11,15};
	int target0 = 9;
	vector<int> solution0 = Solution::twoSum(test0, target0);
	print_vector(solution0);

	vector<int> test1 = {-3,4,3,90};
	int target1 = 0;
	vector<int> solution1 = Solution::twoSum(test1, target1);
	print_vector(solution1);

	vector<int> test2 = {2,5,5,11};
	int target2 = 10;
	vector<int> solution2 = Solution::twoSum(test2, target2);
	print_vector(solution2);

	return 0;
}
