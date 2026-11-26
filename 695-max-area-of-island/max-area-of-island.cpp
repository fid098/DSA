class Solution {
private:
    void dfs(int r, int c, int& max_area, int& cur_area, std::set<std::pair<int, int>>& visited, int ROWS, int COLS, vector<vector<int>>& grid){
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0 || visited.count({r,c})){
            return;
        }

        cur_area += 1;
        max_area = std::max(max_area, cur_area);
        visited.insert({r,c});

        dfs(r + 1, c, max_area, cur_area, visited, ROWS, COLS, grid);
        dfs(r - 1, c, max_area, cur_area, visited, ROWS, COLS, grid);
        dfs(r, c + 1, max_area, cur_area, visited, ROWS, COLS, grid);
        dfs(r, c - 1, max_area, cur_area, visited, ROWS, COLS, grid);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int max_area = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int cur_area = 0;
        std::set<std::pair<int, int>> visited;


        for (int r {0}; r < ROWS; r++){
            for (int c {0}; c < COLS; c++){
                if (grid[r][c] == 1 && !visited.count({r,c})){
                    int cur_area = 0;
                    dfs(r, c, max_area, cur_area, visited, ROWS, COLS, grid);
                }
            }
        }
        return max_area;
    }
};