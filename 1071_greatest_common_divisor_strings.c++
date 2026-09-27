/**
 * LeetCode problem 1071
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/
 */

#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    static string gcdOfStrings1(string str1, string str2) {
	    string gcd = "";
	    int match = 0;

	    for(int k=1; k <= str1.size(); k++) {
		    string prefix = str1.substr(0, k);

		    int m1=0, m2=0;
		    for(int i=0; i<str1.size(); i=i+k) {
			    m1 = str1.compare(i, k, prefix);
			    if(m1 != 0) break;
		    }

		    for(int i=0; i<str2.size(); i=i+k) {
			    m2 = str2.compare(i, k, prefix);
			    if(m2 != 0) break;
		    }
		    if((0 == m1) && (0 == m2)) gcd.assign(prefix);
	    }
	    return gcd;
    }

        static string gcdOfStrings(string str1, string str2) {
	    string gcd = "";
	    int match = 0;
	    int max = (str1.size() > str2.size())? str1.size() : str2.size();
	    for(int k=1; k <= str1.size(); k++) {
		    string prefix = str1.substr(0, k);
		    if(str1.length() % k != 0) continue;
		    if(str2.length() % k != 0) continue;
		    int m1=0, m2=0;
		    bool match = true;
		    for(int i=0; i <= max; i=i+k) {
			    if(i<str1.size())
				    m1 = str1.compare(i, k, prefix);
			    if(i<str2.size())
				    m2 = str2.compare(i, k, prefix);

			    if((0 != m1) ||  (0 != m2)) {
				    match = false;
				    break;
			    }
		    }
		    if(match) gcd.assign(prefix);
	    }
	    return gcd;
    }
 
};

int main()
{

    { // example 1
        string str1 = "ABCABC";
	string str2 = "ABC";
        string result =  Solution::gcdOfStrings(str1, str2);
        cout << result << endl;
    }
    { // example 2
        string str1 = "ABABAB";
	string str2 = "ABAB";
        string result =  Solution::gcdOfStrings(str1, str2);
        cout << result << endl;
    }
    { // example 3
        string str1 = "LEET";
	string str2 = "CODE";
        string result =  Solution::gcdOfStrings(str1, str2);
        cout << result << endl;
    }
    { // example 4
        string str1 = "AAAAAB";
	string str2 = "AAA";
        string result =  Solution::gcdOfStrings(str1, str2);
        cout << result << endl;
    }


    return 0;
}
