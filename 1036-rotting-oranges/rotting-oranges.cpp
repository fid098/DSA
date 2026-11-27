class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::vector<std::pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        std::queue<std::pair<int, int>> q;
        int fresh {0};


        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (grid[r][c] == 2 && visited[r][c] == false){
                    q.push({r,c});
                    visited[r][c] = true;
                }
                if (grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        int minute = 0;
        while (!q.empty() && fresh > 0){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || visited[nr][nc] == true || grid[nr][nc] == 0){
                        continue;
                    }
                    if (grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                        fresh--;
                    }
                }
            }
            minute++;
        }

        if (fresh > 0){
            return -1;
        }
        else{
            return minute;
        }
    }
};