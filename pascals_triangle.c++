#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	std::vector< std::vector<int> > vv;
    	for(int row = 0; row < numRows; row++)
    	{
    		std::vector<int> v;
    		int n = 1;
    		for(int i = 0; i <= row; i++)
    		{
    			v.push_back(n);
				n = n * (row - i) / (i + 1);
    		}
    		vv.push_back(v);
    	}
    	return vv;
    }
};

void print_solution(std::vector<std::vector<int> > vv)
{
	cout << "[" << endl;
	for(std::vector<std::vector<int> >::iterator ivv = vv.begin(); ivv != vv.end(); ivv++)
	{
		cout << "[";
		for(std::vector<int>::iterator iv = (*ivv).begin(); iv != (*ivv).end(); iv++)
					cout << (*iv) << ",";
		cout << "]" << endl;
	}
	cout << "]" << endl;
}

void solution(int rows)
{
	cout << "[" << endl;
	for(int r=0; r < rows; r++)
	{
		for(int a=0;a<rows-r;a++) cout << " ";
		cout << "[";
		int n = 1;
		for (int i = 0; i <= r; ++i)
		{
			cout << n;
			if(i < r) cout << ",";
			n = n * (r - i) / (i + 1);
		}
		cout << "]";
		if(r < rows-1) cout << ",";
		cout << endl;
	}
	cout << "]" << endl;
}

int main(int argc, const char* argv[])
{
	cout << "% " << argv[0] << endl;
	cout << "https://oj.leetcode.com/problems/pascals-triangle/\n\
\nGiven numRows, generate the first numRows of Pascal's triangle.\
\n\
\nFor example, given numRows = 5,\
\nReturn\
\n\
\n[\
\n     [1],\
\n    [1,1],\
\n   [1,2,1],\
\n  [1,3,3,1],\
\n [1,4,6,4,1]\
\n]\
\n" << endl;

	int test[] = { 0, 1, 2, 3, 4, 5, 10 };
	int test_size = sizeof(test)/sizeof(*test);

    for(int i=0; i < test_size; i++) {
	    cout << "T1: " <<  test[i] << endl;
        solution(test[i]);
        Solution s;
        print_solution(s.generate(test[i]));
	}
	return 0;
}
