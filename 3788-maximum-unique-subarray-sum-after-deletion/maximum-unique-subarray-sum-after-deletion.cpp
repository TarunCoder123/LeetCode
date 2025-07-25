class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]])
            {
                continue;
            }
            else
            {
                if(sum>0 && nums[i]<0)
                continue;
                else
                {
                mp[nums[i]]++;
                sum+=nums[i];
                ans=max(ans,sum);
                if(sum<0)
                sum=0;
                }
            }
        }
        return ans;
    }
};