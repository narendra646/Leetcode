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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris order traversal
        vector<int>ans;
        if(!root)
        return ans;
        while(root)
        { 
            if(root->left)               // left exist means make the extra edge
            {
                // chekc if the left is already traversed
                TreeNode *curr=root->left;
                while(curr->right && curr->right!=root)
                curr=curr->right;

                if(curr->right!=NULL)                       // means already traversed 
                {
                    curr->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
                else
                {
                    curr->right=root;
                    root=root->left;
                }
            }
            else                // does't exist means print the value and move the right
            {
                ans.push_back(root->val);
                root=root->right;
            }
        }

        return ans;
    }
};