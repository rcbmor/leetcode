
#include <iostream>

using namespace std;

class Solution {
public:
    static int singleNumber(int A[], int n) {
	int num = 0, i;
	for(i=0; i<n; i++)
		num ^= A[i];
	return num;
    }
};

int main(int argc, const char* argv[])
{
	cout << "% " << argv[0] << endl;

	int test0[] = { 1 };
	int test1[] = { 1, 2, 3, 1, 3 };

	cout << "R0: " << Solution::singleNumber(test0, 1) << endl;
	cout << "R1: " << Solution::singleNumber(test1, 5) << endl;

	return 0;
}
