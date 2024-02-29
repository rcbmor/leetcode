
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	// merge nums1 and nums2 into a singla array sorted in non-decreasing order
	static void merge(vector<int>& nums1, vector<int>& nums2, int n) {
		vector<int> _nums1(nums1);
		auto m = nums1.size() - nums2.size();
		auto i = 0, j = 0, k = 0;
		while( (i < m) && (j < n) ) {
			if( _nums1[i] <= nums2[j] ) {
				nums1[k] = _nums1[i];
				i++;
			} else {
				nums1[k] = nums2[j];
				j++;
			}
			k++;
		}
		while(j<n) {
			nums1[k] = nums2[j];
			j++;
			k++;
		}
		while(i<m) {
			nums1[k] = _nums1[i];
			i++;
			k++;
		}
		return ;
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
	// example 1
	{
		vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2, 5, 6};
		int n=3;
		vector<int> res = {1,2,2,3,5,6};

		std::cout << "num1: ";
		print_vector(nums1);
		std::cout << "\n";

		std::cout << "num2: ";
		print_vector(nums2);
		std::cout << "\n";

		Solution::merge(nums1, nums2, n);
		std::cout << "numr: ";
		print_vector(nums1);
		std::cout << "\n";
		std::cout << "res : ";
		print_vector(res);
		std::cout << "\n";
	}
	// example 2
	{
		vector<int> nums1 = {1}, nums2 = {};
		int n=0;
		vector<int> res = {1};

		Solution::merge(nums1, nums2, n);
		print_vector(nums1);
		std::cout << "\n";
		print_vector(res);
		std::cout << "\n";
	}
	// example 3
	{
		vector<int> nums1 = {0}, nums2 = {1};
		int n=1;
		vector<int> res = {1};

		Solution::merge(nums1, nums2, n);
		print_vector(nums1);
		std::cout << "\n";
		print_vector(res);
		std::cout << "\n";
	}
	// example 4
	{
		vector<int> nums1 = {4,5,6,0,0,0}, nums2 = {1,2,3};
		int n=3;
		vector<int> res = {1,2,3,4,5,6};

		Solution::merge(nums1, nums2, n);
		print_vector(nums1);
		std::cout << "\n";
		print_vector(res);
		std::cout << "\n";
	}
	return 0;
}
