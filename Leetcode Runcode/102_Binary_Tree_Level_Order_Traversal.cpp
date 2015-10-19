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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> queue;    // record all valid nodes
        if(root != NULL)
        {
            queue.push_back(root);
            int nextLevelCount = 1;
            int index = 0;
            while(index < queue.size())
            {
                int currLevelCount = nextLevelCount;
                nextLevelCount = 0;
                vector<int> valueInLevel;
                // output level by level
                for(int i = index; i < index + currLevelCount; i++)
                {
                    root = queue.at(i);
                    valueInLevel.push_back(root->val);
                    if(root->left != NULL)
                    {
                        queue.push_back(root->left);
                        nextLevelCount++;
                    }
                    if(root->right != NULL)
                    {
                        queue.push_back(root->right);
                        nextLevelCount++;
                    }
                }
                res.push_back(valueInLevel);
                index = index + currLevelCount;
            }
        }
        return res;
    }
};