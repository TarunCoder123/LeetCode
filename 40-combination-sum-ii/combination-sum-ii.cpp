class Solution {
public:
    void findCom(vector<int>& candidates, int target,int ind,vector<int> ds,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            findCom(candidates,target-candidates[i],i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       int n=candidates.size();
       vector<vector<int>> ans;
       vector<int> ds;
       findCom(candidates,target,0,ds,ans); 
       return ans;
    }
};