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
    void find(TreeNode *root, int depth, int &ans)
    {
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL)
        {
            ans = min(ans, depth);
            return;
        }

        find(root->left, depth + 1, ans);
        find(root->right, depth + 1, ans);
    }

    int minDepth(TreeNode* root) {

         if(!root)
         return 0;

        int ans=INT_MAX;
        find(root,1,ans);
        return ans;
    }
};