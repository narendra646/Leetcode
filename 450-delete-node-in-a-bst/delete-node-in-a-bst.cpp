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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return NULL;

        if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else
        {
            // leaf node 
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            // one child
            else if(!root->left)
            {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if(!root->right)
            {
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            // both child
            else
            {
                TreeNode *par=root,*ch=root->left;
                while(ch->right)
                {
                    par=ch;
                    ch=ch->right;
                }
                if(par!=root)
                {
                    par->right=ch->left;
                    ch->left=root->left;
                    ch->right=root->right;
                    delete root;
                    return ch;
                }
                else
                {
                    ch->right=par->right;
                    delete root;
                    return ch;
                }
            }
        }

        return root;
    }
};