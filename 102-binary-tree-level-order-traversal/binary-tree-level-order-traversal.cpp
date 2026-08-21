/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int countLevels(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        return 1 + max(countLevels(root->left),
                       countLevels(root->right));
    }

    void levelOrder(TreeNode *root,int l,vector<vector<int>>&ans)
    {
        if(!root)
        return;

        ans[l].push_back(root->val);
        levelOrder(root->left,l+1,ans);
        levelOrder(root->right,l+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level=countLevels(root);
        vector<vector<int>>ans(level);
        int l=0;
        levelOrder(root,l,ans);

        return ans;
    }
};