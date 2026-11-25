class Solution {
public:
    void dfs(int ROWS, int COLS,int row, int col, int& num_islands, std::set<std::vector<int>>& visited, std::vector<std::vector<char>>& grid){
        //out of bounds
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
            return;
        }

        //seen before or not eqaul to 1
        if (visited.count({row, col}) || grid[row][col] != '1'){
            return;
        }

        //if not visited and equal to 1
        visited.insert({row,col});
        dfs(ROWS, COLS, row + 1, col, num_islands, visited, grid);
        dfs(ROWS, COLS, row - 1, col, num_islands, visited, grid);
        dfs(ROWS, COLS, row, col + 1, num_islands, visited, grid);
        dfs(ROWS, COLS, row, col - 1, num_islands, visited, grid);
}
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int num_islands {0};
        std::set<std::vector<int>> visited;

        for (int row {0}; row < ROWS; row++){
            for (int col {0}; col < COLS; col++){
                if (grid[row][col] == '1' && !visited.count({row, col})){
                    num_islands += 1;
                    dfs(ROWS, COLS, row, col, num_islands, visited, grid);
                }
            }
        }
        
        return num_islands;
    }
};