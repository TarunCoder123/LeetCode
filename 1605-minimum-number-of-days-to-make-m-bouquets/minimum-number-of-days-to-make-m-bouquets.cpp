class Solution {
public:
    bool solve(int mid,vector<int>& bloomDay, int m, int k){
        int count=0;
        int kcount=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                kcount++;
                if(kcount==k){
                    count++;
                    kcount=0;
                }
            }else{
                kcount=0;
            }
        }
        if(count>=m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int maxi=0;
        for(auto it:bloomDay)maxi=max(maxi,it);
        int start=1,end=maxi+1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(solve(mid,bloomDay,m,k)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};