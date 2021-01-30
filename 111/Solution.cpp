// *
//  * Definition for a binary tree node.

#include <vector>
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
    int min_depth = 1; 

    void find_min (vector <TreeNode*> round)
    {
        vector <TreeNode*> new_round;

        for(TreeNode* node : round)
        {
            if (node->left == nullptr && node->right == nullptr)
                return;

            if (node->left != nullptr)
                new_round.push_back(node->left);
            
            if (node->right != nullptr)
                new_round.push_back(node->right);
        }

        min_depth ++;
        return find_min(new_round);
    }



public:


    int minDepth(TreeNode* root) 
    {
        vector <TreeNode*> new_round;
        
        if (root == nullptr) return 0;
        
        new_round.push_back(root);
        find_min(new_round);

        return min_depth;
    }

};