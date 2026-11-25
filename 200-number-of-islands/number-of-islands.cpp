class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::queue<std::pair<int, int>> q;

        int num_islands {0};
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        std::vector<std::pair<int, int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


        for (int row {0}; row < ROWS; row++){
            for (int col {0}; col < COLS; col++){
                if (grid[row][col] == '1' && visited[row][col] == false){
                    num_islands += 1;
                    q.push({row, col});
                    visited[row][col] = true;

                    while (!q.empty()){
                    int n = q.size();
                    for (int i {}; i < n; i++){
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (auto [dr, dc] : directions){
                            int nr = r + dr;
                            int nc = c + dc;

                            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS){
                                continue;
                            }

                            if (grid[nr][nc] == '1' && visited[nr][nc] == false){
                                q.push({nr, nc});
                                visited[nr][nc] = true;
                            }
                        }

                    }
                }
                }
            }
        }
        
        return num_islands;
    }
};