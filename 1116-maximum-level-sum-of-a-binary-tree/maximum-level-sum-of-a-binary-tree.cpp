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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int sum=INT_MIN,level=-1;
        int l=1;
        while(!q.empty())
        {
            int n=q.size();
            int s=0;
            while(n--)
            {
                TreeNode * el=q.front();
                q.pop();
                s+=el->val;
                if(el->left)
                q.push(el->left);

                if(el->right)
                q.push(el->right);
            }
            if(s>sum)
            {
               sum=s;
               level=l;
            }
            l++;
        }       

        return level; 
    }
};