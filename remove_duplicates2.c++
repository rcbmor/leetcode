
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
	// Remove some duplicates in-place such that each unique element appears at most twice.
	// The relative order of the elements should be kept the same.
	// Return k after placing the final result in the first k slots of nums.
    static int removeDuplicates(vector<int>& nums) {

		int i = 0;

		for (const int num : nums)
			if (i < 2 || num > nums[i - 2])
				nums[i++] = num;

		return i;
	}
};

int main(int argc, const char* argv[])
{
	// example 0
	{
		cout << "Example 0: " << endl;
		vector<int> nums = {1,1,1};
		int res_val = 2;
		vector<int> res_nums = {1,1,-1};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
		for (int i = 0; i < k; i++) {
 			assert( nums[i] == res_nums[i] );
		}
	}

	// example 1
	{
		cout << "Example 1: " << endl;
		vector<int> nums = {1,1,1,2,2,3};
		int res_val = 5;
		vector<int> res_nums = {1,1,2,2,3,-1};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
		for (int i = 0; i < k; i++) {
 			assert( nums[i] == res_nums[i] );
		}
	}

	// example 2
	{
		cout << "Example 2: " << endl;
		vector<int> nums = {0,0,1,1,1,1,2,3,3};
		int res_val = 7;
		vector<int> res_nums = {0,0,1,1,2,3,3,-1,-1};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
		for (int i = 0; i < k; i++) {
 			assert( nums[i] == res_nums[i] );
		}
	}

	{
		cout << "Example 3: " << endl;
		vector<int> nums = {0};
		int res_val = 1;
		vector<int> res_nums = {0};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
		for (int i = 0; i < k; i++) {
 			assert( nums[i] == res_nums[i] );
		}
	}

	{
		cout << "Example 4: " << endl;
		vector<int> nums = {0,1};
		int res_val = 2;
		vector<int> res_nums = {0,1};

		int k = Solution::removeDuplicates(nums);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
		for (int i = 0; i < k; i++) {
 			assert( nums[i] == res_nums[i] );
		}
	}


	return 0;
}
