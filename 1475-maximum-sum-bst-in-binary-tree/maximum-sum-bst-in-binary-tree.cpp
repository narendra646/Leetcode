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

   class Box{
      public:
      bool BST;
      int sum;
      int mini,maxi;
      Box(int data)
      {
         BST=1;
         sum=data;
         mini=data;
         maxi=data;
      }
   };

class Solution {
public:

     Box* find(TreeNode* root,int &ans)
     {
        if(!root->left && !root->right)
        {
            ans=max(ans,root->val);
            return new Box(root->val);
        }
        else if(!root->left && root->right)
        {
            Box* head=find(root->right,ans);
            if(head->BST && head->mini>root->val)
            {
                head->sum+=root->val;
                ans=max(ans,head->sum);
                head->mini=root->val;
                return head;
            }
            else
            {
                head->BST=0;
                head->sum=0;
                return head;
            }
        }
        else if(root->left && !root->right)
        {
            Box* head=find(root->left,ans);
            if(head->BST && head->maxi<root->val)
            {
                head->sum+=root->val;
                ans=max(ans,head->sum);
                head->maxi=root->val;
                return head;
            }
            else
            {
                head->BST=0;
                head->sum=0;
                return head;
            }
        }
        else
        {
            Box* lhead=find(root->left,ans);
            Box* rhead=find(root->right,ans);

            if(lhead->BST && rhead->BST && lhead->maxi<root->val && rhead->mini>root->val)
            {
                Box* head=new Box(root->val);
                head->sum+=(lhead->sum+rhead->sum);
                ans=max(ans,head->sum);
                head->mini=lhead->mini;
                head->maxi=rhead->maxi;
                return head;
            }
            else
            {
                // ans=max(ans,max(lhead->sum,rhead->sum));
                lhead->BST=0;
                return lhead;
            }
        }
     }

    int maxSumBST(TreeNode* root) {
        int sum=0;
        find(root,sum);
        return sum;
        
    }
};