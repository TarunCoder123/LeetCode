class Solution {
public:
    int minimumPushes(string word) {
       map<char,int> m;
       for(auto it:word){
          m[it]++;
       }
       vector<pair<int,char>> v;
       for(auto it:m){
        v.push_back({it.second,it.first});
       }
       sort(v.begin(),v.end());
       reverse(v.begin(),v.end());
        int ans=0;
        int total=0;
        int value=1;
        for(int i=0;i<v.size();i++){
            ans+=value*v[i].first;
            cout<<value*v[i].first<<" value*v[i].first "<<endl;
            total+=1;
            if(total>=8){
                total=0;
                value++;
            }
        }
        return ans;
    }
};