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
    void findLevel(TreeNode *root,int level,int &l1,int &l2,int x, int y)
    {
        if(!root)
        return ;

        if(l1!=-1 && l2!=-1)
        return ;

        if(root->val==x)
        l1=level;
        if(root->val==y)
        l2=level;

        findLevel(root->left,level+1,l1,l2,x,y);
        findLevel(root->right,level+1,l1,l2,x,y);
    }

    bool check_parent(TreeNode *root,int x,int y)
    {
        if(!root)
        return false;
        if(root->left && root->right)
        {
            if(root->left->val==x && root->right->val==y)
            return true;

            if(root->left->val==y && root->right->val==x)
            return true;
        }

        return check_parent(root->left,x,y) || check_parent(root->right,x,y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if(!root || (!root->left && !root->right))
        return false;
        int level=0,l1=-1,l2=-1;
        findLevel(root,0,l1,l2,x,y); 

        if(l1!=l2)
        return false;

        return !check_parent(root,x,y);
    }
};