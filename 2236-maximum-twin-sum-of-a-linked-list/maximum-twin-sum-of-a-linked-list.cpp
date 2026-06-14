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
    ListNode* reverse(ListNode* temp){
        ListNode* prev=NULL;
        ListNode* curr=temp;
        ListNode* fur=NULL;
        while(curr!=NULL){
            fur=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fur;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
    // Firstly find the size of the LL
    int n=0;
    ListNode* temp=head;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }    

    cout<<n<<"nnnnn"<<endl;

    // middle one
    temp=head;
    int count=0;
    while(count!=n/2){
        temp=temp->next;
        count++;
    }

    // now reverse the Linked list
    ListNode* rev=reverse(temp);
    ListNode* curr=head;
    count=0;
    int maxi=0;
    int sum=0;
    while(count!=n/2+1 && (rev!=NULL &&  curr!=NULL)){
        if(rev!=NULL &&  curr!=NULL){
        sum=rev->val+curr->val;
        maxi=max(maxi,sum);
        }
        rev=rev->next;
        curr=curr->next;
        count++;
    }

    return maxi;

    }
};