class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int left=0;
        int right=0;
        int size=1e9;
        map<int,int> m;
        while(right<n){
            // base case
            m[cards[right]]++;
            if(m[cards[right]]>1){
                while(left<=right && m[cards[right]]!=1){
                    size=min(size,right-left+1);
                    m[cards[left]]--;
                    if(m[cards[left]]==0)m.erase(cards[left]);
                    left++;
                }
            }
            right++;
        }
        return size==1e9?-1:size;
    }
};