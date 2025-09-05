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

    void minDist(TreeNode *root,int &pre,int &ans)
    {
       if(!root)
       return ;
       
       // left
       minDist(root->left,pre,ans);
       // node
       if(pre!=INT_MIN)                      // because for the first time this can give integer overflow            
       ans=min(ans,root->val-pre);

       pre=root->val;
       // right
       minDist(root->right,pre,ans);
       
    }

    int minDiffInBST(TreeNode* root) {
        
       // first logic => find the inorder traversal of the tree and the min of difference of the adjacent nodes

       // same with recursion
       int pre=INT_MIN;
       int ans=INT_MAX;
       minDist(root,pre,ans);
       return ans;


    }
};