class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int len = grid.size();
        int width = grid[0].size();
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < width; ++j) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    pair<int, int> start = {i, j};
                    q.push(start);
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        if(cur.first-1 >= 0 && cur.first-1 < len && cur.second >= 0 && cur.second < width) {
                            if(grid[cur.first-1][cur.second] == '1') {
                                grid[cur.first-1][cur.second] = '0';
                                pair<int, int> up = {cur.first-1, cur.second};
                                q.push(up);
                            }
                        }
                        if(cur.first+1 >= 0 && cur.first+1 < len && cur.second >= 0 && cur.second < width) {
                            if(grid[cur.first+1][cur.second] == '1') {
                                grid[cur.first+1][cur.second] = '0';
                                pair<int, int> down = {cur.first+1, cur.second};
                                q.push(down);
                            }
                        }
                        if(cur.first >= 0 && cur.first < len && cur.second-1 >= 0 && cur.second-1 < width) {
                            if(grid[cur.first][cur.second-1] == '1') {
                                grid[cur.first][cur.second-1] = '0';
                                pair<int, int> left = {cur.first, cur.second-1};
                                q.push(left);
                            }
                        }
                        if(cur.first >= 0 && cur.first < len && cur.second+1 >= 0 && cur.second+1 < width) {
                            if(grid[cur.first][cur.second+1] == '1') {
                                grid[cur.first][cur.second+1] = '0';
                                pair<int, int> right = {cur.first, cur.second+1};
                                q.push(right);
                            }
                        }
                    }
                    island++;
                }
            }
        }
        return island;
    }
};
