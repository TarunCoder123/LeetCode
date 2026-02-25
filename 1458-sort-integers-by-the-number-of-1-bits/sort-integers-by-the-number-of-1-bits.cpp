class Solution {
public:
    int setBitCount(int num){
        int count=0;
        while(num>0){
            int dig=num&1;
            count+=dig;
            num=(num>>1);
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> val;
        for(auto it:arr){
            int set_val=setBitCount(it);
            val.push_back({set_val,it});
        }
        sort(val.begin(),val.end());
        vector<int> ans;
        for(auto it:val){
            ans.push_back(it.second);
        }
        return ans;

    }
};