// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
#include <climits>
#include <iostream>

using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

void maxSubArraySumIdx(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0,
		start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here += a[i];

		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is " << max_so_far;
	cout << " , Starting index " << start
		<< " , Ending index " << end << endl;
}

int maxSubArraySumDynProg(int a[], int size)
{
	// dynamic programming
    vector<int> dp(size, 0); // memory
    dp[0] = a[0];
    int ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = max(a[i], a[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum << endl;

	max_sum = maxSubArraySumDynProg(a, n);
	cout << "(DynProg) Maximum contiguous sum is " << max_sum << endl;

	cout << "(Indexes) ";
	maxSubArraySumIdx(a, n);

	return 0;
}
