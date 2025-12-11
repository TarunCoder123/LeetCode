class Solution {
public:
    int countCoveredBuildings(int mmm, vector<vector<int>>& buildings) {

        map<int,int> xmin_row, xmax_row;
        map<int,int> ymin_col, ymax_col;

        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            // min/max x in each row y
            if (!xmin_row.count(y)) xmin_row[y] = x;
            else xmin_row[y] = min(xmin_row[y], x);

            if (!xmax_row.count(y)) xmax_row[y] = x;
            else xmax_row[y] = max(xmax_row[y], x);

            // min/max y in each column x
            if (!ymin_col.count(x)) ymin_col[x] = y;
            else ymin_col[x] = min(ymin_col[x], y);

            if (!ymax_col.count(x)) ymax_col[x] = y;
            else ymax_col[x] = max(ymax_col[x], y);
        }

        int count = 0;
        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            if (xmin_row[y] < x && x < xmax_row[y] &&
                ymin_col[x] < y && y < ymax_col[x]) 
            {
                count++;
            }
        }

        return count;
    }
};
