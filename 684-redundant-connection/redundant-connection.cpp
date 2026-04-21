class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]); // path compression
            return parent[x];
        }

        bool unite(int x, int y) {
            int px = find(x);
            int py = find(y);

            if (px == py) return false; // cycle detected

            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n=edges.size();
      DSU dsu(n);

      for(auto &e:edges){
        if(!dsu.unite(e[0],e[1])){
            return e;
        }
      }

      return {};  
    }
};