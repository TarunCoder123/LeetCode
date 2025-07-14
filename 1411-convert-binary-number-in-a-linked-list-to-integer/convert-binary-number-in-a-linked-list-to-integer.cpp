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
    int getDecimalValue(ListNode* head) {
        // reverse the linked the list
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        int ans=0;
        int val=1;
        while(prev!=NULL){
            cout<<ans<<" ";
            ans=ans+(val*prev->val);
            prev=prev->next;
            val=val<<1;
        }
        return ans;
    }
};