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
    void Inorder(TreeNode *root,vector<int>&inorder)
    {
       if(!root)
       return;
       
       Inorder(root->left,inorder);
       inorder.push_back(root->val);
       Inorder(root->right,inorder);

    }

    void replace(TreeNode *root,vector<int>&inorder,int &index)
    {
        if(!root)
        return;

        replace(root->left,inorder,index);
        root->val=inorder[index++];
        replace(root->right,inorder,index);
    }

    void recoverTree(TreeNode* root) {
       vector<int>inorder;
       Inorder(root,inorder);
       int first=-1,second=-1;
       for(int i=0;i<inorder.size()-1;i++)
       {
          if(inorder[i]>inorder[i+1])
          {
            if(first==-1)
            first=i;

            second=i+1;
          }
       }
      swap(inorder[first],inorder[second]);
      int index=0;
      replace(root,inorder,index);

    }
};