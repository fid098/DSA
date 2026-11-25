class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::queue<std::pair<int, int>> q;

        std::vector<std::pair<int, int>> directions{{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        int perimeter {};

        bool found = false;
        for (int r {}; r < ROWS && !found; r++){
            for (int c {}; c < COLS && !found; c++){
                if (visited[r][c] == false && grid[r][c] == 1){
                    visited[r][c] = true;
                    q.push({r, c});
                    found = true;
                }
            }
        }


        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [dr, dc] = q.front();
                q.pop();
                perimeter += 4;

                for (std::pair<int, int>& direction : directions){
                    int nr = dr + direction.first;
                    int nc = dc + direction.second;
                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS){
                        continue;
                    }
                    if (grid[nr][nc] == 1){
                        perimeter--;

                        if (visited[nr][nc] == false){
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                }

            }
        }

        return perimeter;
    }
};