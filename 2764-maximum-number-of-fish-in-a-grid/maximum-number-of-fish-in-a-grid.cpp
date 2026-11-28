class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        /*
            land = 0
            water cell has grid[r][c] num of fishes

            a fisher can start at any water cell 
            - catch all fishes in that cell
            - move an any adjacent water cell with fishes

            return the max number of fish the fisher can catch if he choosing his starting cell optimally, or 0 if no water cell exists

            [[0,2,1,0]
             [4,0,0,3]
             [1,0,0,4]
             [0,3,2,0]]

             put all the non zero in q
             -for each position, take that position and go through all directions, if the total is greater than the max so far, update
             -do that for all the values in the queue 


             
        */

        int ROWS = grid.size();
        int COLS = grid[0].size();
        int max_taken {};
        std::vector<std::pair<int, int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int r {}; r < ROWS; r++) {
            for (int c {}; c < COLS; c++) {
                // Start a fresh BFS for each unvisited lake
                if (grid[r][c] > 0) {
                    int total = grid[r][c];
                    grid[r][c] = 0; // Mark visited immediately upon pushing!

                    std::queue<std::pair<int, int>> q;
                    q.push({r, c});

                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();

                        for (auto [dr, dc] : directions) {
                            int nr = curr_r + dr;
                            int nc = curr_c + dc;

                            if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] == 0) {
                                continue;
                            }

                            total += grid[nr][nc];
                            grid[nr][nc] = 0; // Mark visited before pushing so it's never counted twice
                            q.push({nr, nc});
                        }
                    }

                    max_taken = std::max(max_taken, total);
                }
            }
        }

        return max_taken;
    }
};