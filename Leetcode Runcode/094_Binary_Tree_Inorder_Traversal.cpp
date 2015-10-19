/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;
        if(root != NULL)
        {
            TreeNode* node = root;
            while(stack.size() > 0 || node != NULL) // 2nd condition for the 1st node
            {
                while(node != NULL) // before node becomes a leaf
                {
                    stack.push_back(node);
                    node = node->left;
                }
                node = stack.back();    // upper level
                stack.pop_back();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};