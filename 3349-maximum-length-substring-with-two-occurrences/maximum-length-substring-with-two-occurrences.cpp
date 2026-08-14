class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n=s.length();
       vector<int> v(26,0);
       int l=0;
       int ans=0;
       for(int r=0;r<n;r++){
          v[s[r]-'a']++;
          while(v[s[r]-'a']>2){
            v[s[l]-'a']--;
            l++;
          }
          ans=max(ans,r-l+1);
       } 
       return ans;
    }
};