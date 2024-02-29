
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

class Solution1 {
public:
	// Remove all occurrences of val in nums in-place.
	// The order of the elements may be changed.
	// Then return the number of elements in nums which are not equal to val.
	// Consider the number of elements in nums which are not equal to val be k,
	//   to get accepted, you need to do the following things:
	//   Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
	//   The remaining elements of nums are not important as well as the size of nums.
	// Return k.
    static int removeElement(vector<int>& nums, int val) {
		int v = 0, v2 = 0;
		cout << " val: " << val << endl;
		cout << " nums: "; print_vector(nums); cout << endl;

		for(auto i = nums.begin(); i < nums.end(); i++) {
			if(val == *i) v++;
		}

		for(auto i = nums.begin(), j = nums.end()-1; i <= j;) {
			if(i==j) {
				if( (val==*i) && (val==*j) ) v2++;
				i++;
				j--;
			} else if( (val==*i) && (val!=*j) ) {
				swap(*i,*j);
				v2++;
				i++;
				j--;
			} else if( (val==*j) && (val!=*i) ) {
				i++;
			} else if( (val==*i) && (val==*j) ) {
				v2++;
				j--;
			} else {
				// both different
				i++;
			}
		}
		cout << "  v : " << v << endl;
		cout << "  v2: " << v2 << endl;

		return nums.size() - v;	
	}
};

class Solution {
public:
	static int removeElement(vector<int>& nums, int val) {
		int j=0;int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val){
                count++;
                nums[j++]=nums[i];                
            }
        }
        return count;
	}
};

int main(int argc, const char* argv[])
{
	// example 1
	{
		cout << "Example 1: " << endl;
		vector<int> nums = {3,2,2,3};
		int val = 3;
		int res_val = 2;
		vector<int> res_nums = {2,2,-1,-1};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		cout << "nums :" ; print_vector(nums); cout << endl;
		cout << "res  :" ; print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 2
	{
		cout << "Example 2: " << endl;
		// Input:
		vector<int> nums = {0,1,2,2,3,0,4,2};
		int val = 2;
		// Output:
		int res_val = 5;
		vector<int> res_nums = {0,1,4,0,3,-1,-1,-1};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 3
	{
		cout << "Example 3: " << endl;
		// Input:
		vector<int> nums = {3,3};
		int val = 3;
		// Output:
		int res_val = 0;
		vector<int> res_nums = {3,3};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 4
	{
		cout << "Example 4: " << endl;
		// Input:
		vector<int> nums = {3};
		int val = 3;
		// Output:
		int res_val = 0;
		vector<int> res_nums = {3};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 5
	{
		cout << "Example 5: " << endl;
		// Input:
		vector<int> nums = {3,1,3};
		int val = 3;
		// Output:
		int res_val = 1;
		vector<int> res_nums = {1,3,3};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 6
	{
		cout << "Example 6: " << endl;
		// Input:
		vector<int> nums = {3,1,1};
		int val = 3;
		// Output:
		int res_val = 2;
		vector<int> res_nums = {1,1,3};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 7
	{
		cout << "Example 7: " << endl;
		// Input:
		vector<int> nums = {1,1,3};
		int val = 3;
		// Output:
		int res_val = 2;
		vector<int> res_nums = {1,1,3};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	// example 8
	{
		cout << "Example 8: " << endl;
		// Input:
		vector<int> nums = {1,2,3};
		int val = 5;
		// Output:
		int res_val = 3;
		vector<int> res_nums = {1,2,3};

		int k = Solution::removeElement(nums, val);
		cout << "k: " << k << endl;
		print_vector(nums); cout << endl;
		print_vector(res_nums); cout << endl;

		assert( k == res_val );
		// std::sort(nums.begin(), nums.begin() + k);
		// for (int i = 0; i < nums.size(); i++) {
		// 	assert( nums[i] == res_nums[i] );
		// }
	}

	return 0;
}
