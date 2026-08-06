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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
        return head;
        int count=0;
        ListNode *temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        ListNode *ans=new ListNode(-1);
        ListNode *tail=ans;
        int d=count/k;
        temp=head;
        while(true)
        {
            if(count<k)
            break;

            int x=k;
            ListNode *d=NULL;
            while(temp && x--)
            {
               ListNode *t=new ListNode(temp->val);
               temp=temp->next;
               t->next=d;
               d=t;
            //    delete t;
            }
            tail->next=d;
            while(tail->next!=NULL)
            {
                tail=tail->next;
            }
            count-=k;
        }
        tail->next=temp;
        return ans->next;
    }
};