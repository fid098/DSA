class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0){
            return -1;
        }

        int ROWS = grid.size();
        int COLS = grid[0].size();
        int shortestPath = -1;
        int currentStretch = 1;

        std::vector<std::pair<int, int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        std::queue<std::pair<int, int>> q;
        q.push({0,0});
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        visited[0][0] = true;

        while (q.size() > 0){
            int n = q.size();
            for (int i {}; i < n; i++){
                std::pair<int, int> coords = q.front();
                q.pop();

                if (coords.first == ROWS - 1 && coords.second == COLS - 1){
                    shortestPath = currentStretch;
                    return shortestPath;
                }

                for (const std::pair<int, int> neighbour : directions){
                    int dr = coords.first + neighbour.first;
                    int dc = coords.second + neighbour.second;
                    if (dr >= 0 && dr < ROWS && dc >= 0 && dc < COLS && grid[dr][dc] == 0 && !visited[dr][dc]){
                        visited[dr][dc] = true;
                        q.push({dr, dc});
                    }
                }

            }
            currentStretch++;
        }

        return -1;
    }
};