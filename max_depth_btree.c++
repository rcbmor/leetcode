
#include <iostream>
#include <cmath>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct TreeNode * TreeNodeT;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {};
	  TreeNode(int x, TreeNodeT lt, TreeNodeT rt) : val(x), left(lt), right(rt) {};
};
  
class Solution {
public:
    static int maxDepth(TreeNode *root) {
		if(root == NULL) return 0;
        return fmax( maxDepth(root->left), maxDepth(root->right) ) + 1;
	}
};

int main(int argc, const char* argv[])
{
        cout << "% " << argv[0] << endl;

        TreeNode *test0 = NULL;
		TreeNode test1 = TreeNode(1);
		TreeNode test2 = TreeNode(2, &test1, NULL);
		TreeNode test3 = TreeNode(3, &test2, NULL);

        cout << "R0: " << Solution::maxDepth(test0) << endl;
        cout << "R1: " << Solution::maxDepth(&test1) << endl;
        cout << "R2: " << Solution::maxDepth(&test2) << endl;
        cout << "R3: " << Solution::maxDepth(&test3) << endl;

        return 0;
}