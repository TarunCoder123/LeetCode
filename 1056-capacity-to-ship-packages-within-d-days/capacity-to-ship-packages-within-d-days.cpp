class Solution {
public:
    bool solve(long long weight,vector<int>& piles, int days){
        int count=0;
        int count_days=1;
        // if(weight==2)cout<<count<<"count "<<count_days<<"count_days "<<endl;
        for(auto it:piles){
        // if(weight==2)cout<<count<<"count "<<count_days<<"count_days "<<endl;
            count+=it;
            if(it>weight)return false;
            if(count>weight){
               count=it;
               count_days++;
            }
        if(count_days>days)return false;
        }
        if(count_days>days)return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini=0;
        for(auto it:weights)mini=min(mini,it);
        long long start=mini,end=1e14;
        long long ans=0;
        while(start<=end){
           long long mid=start+(end-start)/2;
           if(solve(mid,weights,days)){
            ans=mid;
            end=mid-1;
           }else{
            start=mid+1;
           }
        }
        return (int)ans;  
    }
};