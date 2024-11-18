class Solution {
public:
    int countGoodSubstrings(string s) {
    map<char,int> m;
    int start=0,end=0;
    int count=0;
    int k=3;
    while(end<s.length()){
        if(end-start+1<k){
            m[s[end]]++;
            end++;
        }else{
            m[s[end]]++;
            end++;
            if(m.size()==3){
                count++;
            }
            if(m[s[start]]==1){
                m[s[start]]--;
                m.erase(s[start]);
            }else{
                m[s[start]]--;
            }
            start++;
        }
    }
    return count;
    }
};