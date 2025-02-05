/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans=NULL;
        ListNode *curr=NULL;
        int carry=0;
        while(l1 && l2)
        {
            int sum=l1->val + l2->val+carry;
            int nod=sum%10;
            carry=sum/10;

            ListNode * temp=new ListNode(nod);
            if(ans==NULL)
            {
                ans=temp;
                curr=ans;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
            }

            l1=l1->next;
            l2=l2->next;

        }


        // rest of the nodes in list 1
        while(l1)
        {
            int sum=l1->val + carry;
            int nod=sum%10;
            carry=sum/10;

            ListNode * temp=new ListNode(nod);
            if(ans==NULL)
            {
                ans=temp;
                curr=ans;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
            }

            l1=l1->next;
            // l2=l2->next;

        }

        
        // for rest nodes in list 2
        while(l2)
        {
            int sum=l2->val+carry;
            int nod=sum%10;
            carry=sum/10;

            ListNode * temp=new ListNode(nod);
            if(ans==NULL)
            {
                ans=temp;
                curr=ans;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
            }

            // l1=l1->next;
            l2=l2->next;

        }

        if(carry!=0)
        {
          ListNode *temp=new ListNode(carry);
          curr->next=temp;
        }

        return ans;
        
    }
};