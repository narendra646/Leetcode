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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *curr=head;
        int count=0;
        while(curr)
        {
          count++;
          curr=curr->next;
        }

        if(count==1)
        return NULL;

        

        curr=head;
        int mid=count/2;
        while(mid--)
        {
            curr=curr->next;
        }

        ListNode *temp=head,*prev=NULL;
        while(temp!=curr)
        {
            prev=temp;
            temp=temp->next;
        }

        prev->next=temp->next;

        return head;
    }
};