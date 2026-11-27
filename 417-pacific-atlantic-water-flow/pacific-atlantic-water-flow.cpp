class Solution {
private:
    void dfs(int r, int c, std::vector<std::vector<bool>>& visited, int prevHeight, vector<vector<int>>& heights){
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] == true || heights[r][c] < prevHeight){
            return;
        }

        visited[r][c] = true;
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        std::vector<std::vector<int>> result;

        std::vector<std::vector<bool>> pac(ROWS, std::vector<bool>(COLS, false));
        std::vector<std::vector<bool>> atl(ROWS, std::vector<bool>(COLS, false));

        for (int r {}; r < ROWS; r++){
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, COLS - 1, atl, heights[r][COLS - 1], heights);
        }

        for (int c {}; c < COLS; c++){
            dfs(0, c, pac, heights[0][c], heights);
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c], heights);
        }

        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (atl[r][c] == true && pac[r][c] == true){
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};