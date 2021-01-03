// *
//  * Definition for a binary tree node.

#include <set>



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
    int min_depth; 

    void find_min (vector<TreeNode> round)
    {

        vector <TreeNode> new_round;

        min_depth ++;
        for(TreeNode node : round)
        {
            if (node.left != nullptr)
                new_round.push_back(node.left);
            if (node.right != nullptr)
                new_round.push_back(node.right);
        }

        return find_min(new_round);

    }



public:


    int minDepth(TreeNode* root) 
    {
        vector <TreeNode> new_round;
        new_round.push_back(root);
        find_min(new_round);
        return min_depth;
    }

};