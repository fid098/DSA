class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        /*
            0 represents water
            1 represents land

            an island is a 4 directionally connected group of 1s not connected to any other 1s
            there are two islands

            you may change 0s to 1s to connect two islands to form one island 
            return the smallest number of 0s to flip

            [0 1
            [1 0]
            either flip 0,0 or 1,1

            [0 2 0
             0 0 0
             0 0 1]

            either flip 1,1 and 2,1 or 1,2 and 1,3

            [1 1 1 1 1
             1 0 0 0 1
             1 0 1 0 1
             1 0 0 0 1
             1 1 1 1 1]

            theres three possible 1 flip options 
        */

        int ROWS = grid.size();
        int COLS = grid[0].size();

        std::vector<std::pair<int, int>> directions {{0,1}, {1,0}, {-1,0}, {0,-1}};
        std::queue<std::pair<int, int>> q;
        std::queue<std::pair<int, int>> bridge;

        //found a 1 
        bool not_found = true;
        for (int r {}; r < ROWS && not_found; r++){
            for (int c {}; c < COLS && not_found; c++){
                if (grid[r][c] == 1){
                    grid[r][c] = 2;
                    bridge.push({r, c});
                    q.push({r, c});
                    not_found = false;
                }
            }
        }

        //flood fill and made the island 2
        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nc < 0 || nr < 0 || nr >= ROWS || nc >= COLS){
                        continue;
                    }

                    if (grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        bridge.push({nr, nc});
                        q.push({nr, nc});
                    }

                }
            }
        }

        int steps {};
        while (!bridge.empty()){
            int n = bridge.size();
            for (int i {}; i < n; i++){
                auto [r, c] = bridge.front();
                bridge.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nc < 0 || nr < 0 || nr >= ROWS || nc >= COLS){
                        continue;
                    }

                    //if its another island
                    if (grid[nr][nc] == 1){
                        return steps;
                    }

                    //if its water, add to bridge
                    if (grid[nr][nc] == 0){
                        grid[nr][nc] = 2;
                        bridge.push({nr, nc});
                    }
                    
                }
            }
            steps++;
        }

        return -1;
    }
};