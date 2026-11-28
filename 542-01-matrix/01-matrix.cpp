class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int ROWS = mat.size();
        int COLS = mat[0].size();

        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int, int>> directions {{0,1}, {1,0}, {0,-1}, {-1,0}};


        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (visited[r][c] == false && mat[r][c] == 0){
                    q.push({r, c});
                    visited[r][c] = true;
                }
            } 
        }

        int distance = 1;
        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || visited[nr][nc] == true){
                        continue;
                    }
                    
                    if (mat[nr][nc] == 1){
                        mat[nr][nc] = distance;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            distance++;
        }

        return mat;

    }
};