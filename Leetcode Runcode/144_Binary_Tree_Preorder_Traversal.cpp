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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        TreeNode* node = root;
        while(stack.size() > 0 || node != NULL)
        {
            if(node != NULL)
            {
                res.push_back(node->val);   // not push itself
                if(node->right != NULL)
                    stack.push_back(node->right);   // right node comes first!
                node = node->left;
            }
            else
            {
                node = stack.back();
                stack.pop_back();
            }
        }
        return res;
    }
};