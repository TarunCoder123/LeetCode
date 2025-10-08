class Solution {
public:
    int binarySearch(long long val,vector<int> &potions){
        long long start=0;
        long long n=potions.size();
        long long end=n-1;
        long long ans=n;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(potions[mid]>=val){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       int len=potions.size();
       vector<int> ans(spells.size(),0);
       sort(potions.begin(),potions.end());
       for(int i=0;i<spells.size();i++){
       long long count=0;
        long long val=success/spells[i];
        long long rem=success%spells[i];
        if(rem==0){
            int ind=binarySearch(val,potions);
            cout<<val<<" "<<ind<<" "<<i<<endl;
            count+=(len-ind);
        }else{
            int ind1=binarySearch(val+1,potions);
            cout<<val+1<<" "<<ind1<<" "<<i<<endl;
            count+=(len-ind1);           
        }
        ans[i]=count;
       }
       return ans;
    }
};