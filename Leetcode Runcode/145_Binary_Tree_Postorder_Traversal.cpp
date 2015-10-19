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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        if(root == NULL)
            return res;
        
        stack.push_back(root);
        TreeNode *preNode = NULL;
        while(stack.size() > 0)
        {
            TreeNode *currNode = stack.back();
            if((currNode->left == NULL && currNode->right == NULL) ||
                (preNode != NULL && (preNode == currNode->left || preNode == currNode->right)))
            {
                res.push_back(currNode->val);
                stack.pop_back();
                preNode = currNode;
            }
            else
            {
                if(currNode->right)
                    stack.push_back(currNode->right);
                if(currNode->left)
                    stack.push_back(currNode->left);
            }
        }
        return res;
    }
};