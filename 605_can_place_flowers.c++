/**
 * LeetCode problem 605
 * https://leetcode.com/problems/can-place-flowers/
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
    static bool canPlaceFlowers(vector<int>& f, int n) {
	    int e = 0;
	    int s = f.size();
	    if(0==n) return true;
	    for(int i = 0; i < s; i++) {
		    if( f[i] == 0 ) {
			    int l = ( (i == 0) || (f[i-1] == 0) ) ? 1 : 0;
			    int r = ( (i == s - 1) || (f[i+1] == 0) ) ? 1 : 0;
			    if((l)&&(r)) {
				    f[i]=1;
				    e+=1;
			    }
			    if(e>=n) return true;
		    }
	    }
	    return e>=n;
    }

};

int main()
{
    { // example 1
        vector<int> v = {1,0,0,0,1};
	int n = 1;
        bool r = Solution::canPlaceFlowers(v, n);
	cout << "expected output: true" << endl;
	cout << "result           " << r << endl;
    }
    { // example 2
        vector<int> v = {1,0,0,0,1};
	int n = 2;
        bool r = Solution::canPlaceFlowers(v, n);
	cout << "expected output: false" << endl;
	cout << "result           " << r << endl;
    }
    { // example 3
        vector<int> v = {1,0,0,0,0,1};
	int n = 2;
        bool r = Solution::canPlaceFlowers(v, n);
	cout << "expected output: false" << endl;
	cout << "result           " << r << endl;
    }
    { // example 4
        vector<int> v = {0,1,0};
	int n = 1;
        bool r = Solution::canPlaceFlowers(v, n);
	cout << "expected output: false" << endl;
	cout << "result           " << r << endl;
    }
    return 0;
}
