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
    
    pair<int,int> getsumandcount(TreeNode *root)
    {
        if(!root)
        return {0,0};
        
        pair<int,int>left=getsumandcount(root->left);
        pair<int,int>right=getsumandcount(root->right);
        
        int count=left.first+right.first+1;
        int sum=left.second+right.second+root->val;

        return {count,sum};

    }

    void solve(TreeNode *root,int &ans)
    {
        if (!root)
        return;
        pair<int,int>p=getsumandcount(root);

        if(p.second/p.first==root->val)
        ans++;
        
        solve(root->left,ans);
        solve(root->right,ans);

    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root,ans);

        return ans;
    }
};