class Solution {
public:
    pair<int,bool> finds(int start,int end, vector<int> &v){
        if(v.empty()) return {-1,false};

        if(start < end){ // moving forward
            auto it = lower_bound(v.begin(), v.end(), start + 1);
            if (it != v.end() && *it <= end) {
                return {*it, true};
            }
        }else{ // moving backward
            auto it = upper_bound(v.begin(), v.end(), start - 1);
            if (it != v.begin()) {
                --it;
                if (*it >= end) {
                    return {*it, true};
                }
            }
        }
        return {-1,false};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,vector<int>> mx,my;

        for(auto &it:obstacles){
            mx[it[0]].push_back(it[1]);
            my[it[1]].push_back(it[0]);
        }

        // IMPORTANT: sort for binary search
        for(auto &it:mx) sort(it.second.begin(), it.second.end());
        for(auto &it:my) sort(it.second.begin(), it.second.end());

        int x=0,y=0,dir=1;
        int ans = 0;

        for(auto cmd:commands){
            if(cmd==-1){ // right
                dir = dir==4?1:dir+1;
            }
            else if(cmd==-2){ // left
                dir = dir==1?4:dir-1;
            }
            else{
                if(dir==1){ // up
                    int ny = y + cmd;
                    auto val = finds(y, ny, mx[x]);
                    if(val.second) y = val.first - 1;
                    else y = ny;
                }
                else if(dir==3){ // down
                    int ny = y - cmd;
                    auto val = finds(y, ny, mx[x]);
                    if(val.second) y = val.first + 1;
                    else y = ny;
                }
                else if(dir==2){ // right
                    int nx = x + cmd;
                    auto val = finds(x, nx, my[y]);
                    if(val.second) x = val.first - 1;
                    else x = nx;
                }
                else{ // left (dir==4)
                    int nx = x - cmd;
                    auto val = finds(x, nx, my[y]);
                    if(val.second) x = val.first + 1;
                    else x = nx;
                }
            }
            ans = max(ans, x*x + y*y);
        }
        return ans;
    }
};