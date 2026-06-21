class Solution {
public:
    void find(string digits,int ind,vector<string> &ans,string s,vector<string> m){
        if(ind==digits.length()){
            ans.push_back(s);
            return;
        }
        for(auto i:m[digits[ind]-'0']){
            s.push_back(i);
            find(digits,ind+1,ans,s,m);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> m(10,"");
        m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        find(digits,0,ans,s,m);
        // if(ans.size()==1)ans.pop_back();
        return ans;
    }
};