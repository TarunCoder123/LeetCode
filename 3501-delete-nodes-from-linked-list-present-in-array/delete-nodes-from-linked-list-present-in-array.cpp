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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> m;
       for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
       }
       ListNode* prev=NULL;
       ListNode* temp=head;
       ListNode* start=NULL;
       while(temp!=NULL){
          int val=temp->val;
          if(m.find(val)==m.end()){
            if(start==NULL){
                start=temp;
                prev=temp;
            }else{
                prev->next=temp;
                prev=prev->next;
            }
          }
          temp=temp->next;
       }
       prev->next=NULL;
       return start;
    }
};