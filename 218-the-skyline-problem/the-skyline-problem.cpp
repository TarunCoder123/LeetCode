class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       vector<pair<int,int>> events;
       for(auto it:buildings){
        events.push_back({it[0],-1*it[2]});
        events.push_back({it[1],it[2]});
       }
       sort(events.begin(),events.end());
       int prevMax=0;
       multiset<int> heights;
       heights.insert(0);
       vector<vector<int>> ans;

       for(auto it:events){
        int point=it.first;
        int h=it.second;

        if(h<0){
            heights.insert(-h);
        }else{
            heights.erase(heights.find(h));
        }

        int currMax=*heights.rbegin();

        if(currMax!=prevMax){
            ans.push_back({point, currMax});
            prevMax = currMax;
        }
       }
       return ans;
    }
};