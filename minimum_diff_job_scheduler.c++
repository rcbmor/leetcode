
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
	// .
    static int jobDifficulty(vector<int>& jobs, int days) {
		if(jobs.size() < days) return -1;

		return _dfs(jobs, 0, days, -1);
	}

	static int _dfs(vector<int>& jobs, int i, int d, int cur_max) {

		int cd=0, ed=0, res=0;

		if(i == jobs.size())
			if(d==0)
				return 0;
			else
				return INT16_MAX;

 		if(d==0)
			return INT16_MAX;

		cur_max = max(cur_max, jobs[i]);
		cd = _dfs(jobs, i+1, d, cur_max);
		ed = cur_max + _dfs(jobs, i+1, d-1, -1);
		res = min(cd,ed);
		return res;

	};

};

int main(int argc, const char* argv[])
{
	// example 0
	{
		cout << "Example 0: " << endl;
		vector<int> jobs = {6,5,4,3,2,1};
		int days = 2;
		int res_val = 7;

		int val = Solution::jobDifficulty(jobs, days);
		cout << "val: " << val << endl;
		cout << "res :" << res_val << endl;
		assert( val == res_val );
	}

	return 0;
}
