class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1) {
                    int cur_area = 1;
                    grid[i][j] = 0;
                    queue<pair<int, int>> q;
                    pair<int, int> first_pair = {i, j};
                    q.push(first_pair);
                    while(!q.empty()) {
                        pair<int, int> cur_pair = q.front();
                        q.pop();
                        if(0 <= cur_pair.first-1 && cur_pair.first-1 < rows && 0 <= cur_pair.second && cur_pair.second < cols) {
                            if(grid[cur_pair.first-1][cur_pair.second] == 1) {
                                grid[cur_pair.first-1][cur_pair.second] = 0;
                                cur_area++;
                                pair<int, int> up = {cur_pair.first-1, cur_pair.second};
                                q.push(up);
                            }
                        }
                        if(0 <= cur_pair.first+1 && cur_pair.first+1 < rows && 0 <= cur_pair.second && cur_pair.second < cols) {
                            if(grid[cur_pair.first+1][cur_pair.second] == 1) {
                                grid[cur_pair.first+1][cur_pair.second] = 0;
                                cur_area++;
                                pair<int, int> down = {cur_pair.first+1, cur_pair.second};
                                q.push(down);
                            }
                        }
                        if(0 <= cur_pair.first && cur_pair.first < rows && 0 <= cur_pair.second-1 && cur_pair.second-1 < cols) {
                            if(grid[cur_pair.first][cur_pair.second-1] == 1) {
                                grid[cur_pair.first][cur_pair.second-1] = 0;
                                cur_area++;
                                pair<int, int> left = {cur_pair.first, cur_pair.second-1};
                                q.push(left);
                            }
                        }
                        if(0 <= cur_pair.first && cur_pair.first < rows && 0 <= cur_pair.second+1 && cur_pair.second+1 < cols) {
                            if(grid[cur_pair.first][cur_pair.second+1] == 1) {
                                grid[cur_pair.first][cur_pair.second+1] = 0;
                                cur_area++;
                                pair<int, int> right = {cur_pair.first, cur_pair.second+1};
                                q.push(right);
                            }
                        }
                    }
                    if(cur_area > max_area) {
                        max_area = cur_area;
                    }
                }
            }
        }
        return max_area;
    }
};
