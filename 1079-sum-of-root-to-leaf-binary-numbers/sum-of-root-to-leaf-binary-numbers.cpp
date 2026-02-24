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
    void getcodes(TreeNode* root,string str,vector<string>&codes)
    {
        if(!root)
        return ;

        str+=to_string(root->val);

        // the leaf node
        if(!root->left && !root->right)
        {
            codes.push_back(str);
            return ;
        }

        getcodes(root->left,str,codes);
        getcodes(root->right,str,codes);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string>codes;
        getcodes(root,"",codes);

        int sum=0;
        for(int i=0;i<codes.size();i++)
        {
            int s=0;
            string st=codes[i];
            int m=1;
            for(int j=st.size()-1;j>=0;j--)
            {
               int bit=st[j]-'0';
               s+=bit*m;
               m*=2;
            }
            sum+=s;
        }

        return sum;
        
    }
};