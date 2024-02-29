
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>

#include <cassert>

using namespace std;

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

class Solution {
public:
	// Remove the duplicates in-place such that each unique element appears only once
	// The relative order of the elements should be kept the same.
	// Then return the number of unique elements in nums.
    static int removeDuplicates(vector<int>& nums) {
		int j = 0;
		for(int i=1; i < nums.size(); i++) {
			if(nums[j]!=nums[i]) {
				j++;
				nums[j]=nums[i];
			}
		}
		return j+1;
	}
};

int main(int argc, const char* argv[])
{
	// example 1
	{
		cout << "Example 1: " << endl;
		vector<int> nums = {1,1,2};
		int res_val = 2;
		vector<int> res_nums = {1,2,-1};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
	}

	// example 2
	{
		cout << "Example 2: " << endl;
		vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
		int res_val = 5;
		vector<int> res_nums = {0,1,2,3,4,-1,-1,-1,-1,-1};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
	}

	return 0;
}
