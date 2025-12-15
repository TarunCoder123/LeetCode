class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        int j=0;
        for(int i=0;i<n;){
            int j=i+1;
            int prev=i;
            int curr=j;
            long long len=1;
            while(j<n && (prices[curr]==prices[prev]-1)){
                j++;
                len++;
                prev=curr;
                curr=j;
            }
            cout<<i<<" i "<<j<<" j "<<endl;
            if(len>1)ans+=((len*(len+1))/2);
            else ans+=len;
            i=j;
        }
        return ans;
    }
};