
#include <climits>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {

private:
	int ans = INT_MIN;

public:

    int maxPathSum(TreeNode* root) 
    {
    	findMax(root);
    	return ans;
    }

    int findMax (TreeNode* node)
    {
    	int sum = node->val;
    	int left_max  = 0;
    	int right_max = 0;
    	if (node->left != nullptr)  left_max  = max(left_max,  findMax(node->left) );
    	if (node->right != nullptr) right_max = max(right_max, findMax(node->right));


        ans = max(ans, sum+left_max+right_max);
    	return sum + max(left_max, right_max);
    }
};