class Solution {
public:
    bool solve(long long speed,vector<int>& piles, int h){
        int hours=0;
        for(auto it:piles){
            hours+=it/speed;
            hours+=it%speed?1:0;
            if(hours>h)return false;
        }
        if(hours>h)return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start=1,end=1e14;
        long long ans=0;
        while(start<=end){
           long long mid=start+(end-start)/2;
           if(solve(mid,piles,h)){
            ans=mid;
            end=mid-1;
           }else{
            start=mid+1;
           }
        }
        return (int)ans;
    }
};