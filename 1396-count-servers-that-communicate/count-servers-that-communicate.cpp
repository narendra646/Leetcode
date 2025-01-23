class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    bool b = 0;
                    // search in same row
                    for (int k = 0; k < col; k++) {
                        if (k != j && grid[i][k] == 1)
                            b = 1;
                    }

                    // search in same column  
                    for (int l = 0; l < row; l++) {
                        if (l != i && grid[l][j] == 1)
                            b = 1;
                    }

                    if (b == 1)
                        ans++;
                }
            }
        }

        return ans;
    }
};