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
    bool check(TreeNode *root,long long &prev)
    {
        if(!root)
        return 1;

        bool lft=check(root->left,prev);
        if(lft==0)
        return 0;

        if(root->val<=prev)
        return 0;

        prev=root->val;
        return check(root->right,prev);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
        return true;
        if(!root->left && !root->right)
        return true;

        long long prev = LLONG_MIN;
        return check(root,prev);
    }
};