/**
 * LeetCode problem 1431
 * https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
 */

#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    static vector<bool> kidsWithCandies1(vector<int>& candies, int extraCandies) {
	    vector<bool> r;
	    int maxC = *(max_element(candies.begin(), candies.end()));
	    for(const int c : candies) if(c + extraCandies >= maxC) r.push_back(true); else r.push_back(false);
	    return r;
    }
   static vector<bool> kidsWithCandies2(vector<int>& candies, int extraCandies) {
	    vector<bool> r(candies.size());
	    int maxC = *(max_element(candies.begin(), candies.end()));
	    struct MC {
		    int _maxC, _ec;
		    MC(int maxC, int extraCandies): _maxC(maxC), _ec(extraCandies) {}
		    bool operator()(int n) { return (n + _ec >= _maxC); }
	    };
	    MC mc(maxC, extraCandies);
	    transform(candies.begin(), candies.end(), r.begin(), mc); 
	    return r;
    }
    static vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
	    vector<bool> result(candies.size());
	    int maxCandies = *(max_element(candies.begin(), candies.end()));
	    transform(candies.begin(), candies.end(), result.begin(), 
		[maxCandies, extraCandies](int n) { return n + extraCandies >= maxCandies; });
	    return result;
    }
 
};

    void print_vb(const vector<bool> &v){
	    for(const bool b : v) {
		    if(b) cout << "true";
		    else cout << "false";
		    cout << ",";
	    }
    };

int main()
{
    { // example 1
        vector<int> v = {2,3,5,1,3};
	int ec = 3;
        vector<bool> r = Solution::kidsWithCandies(v, ec);
	cout << "expected output: [true,true,true,false,true,]" << endl;
	cout << "result           ["; print_vb(r); cout << "]" << endl;
    }
    { // example 2
        vector<int> v = {4,2,1,1,2};
	int ec = 1;
        vector<bool> r = Solution::kidsWithCandies(v, ec);
	cout << "expected output: [true,false,false,false,false,]" << endl;
	cout << "result           ["; print_vb(r); cout << "]" << endl;
    }
    { // example 3
        vector<int> v = {12,1,12};
	int ec = 10;
        vector<bool> r = Solution::kidsWithCandies(v, ec);
	cout << "expected output: [true,false,true,]" << endl;
	cout << "result           ["; print_vb(r); cout << "]" << endl;
    }

    return 0;
}
