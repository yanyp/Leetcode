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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode* leftChild = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightChild = lowestCommonAncestor(root->right, p, q);
            if(leftChild != NULL && rightChild != NULL)
            {
                return root;
            }
            else if(leftChild != NULL)
            {
                return leftChild;
            }
            else if(rightChild != NULL)
            {
                return rightChild;
            }
            else
            {
                return NULL;
            }
        }
    }
};