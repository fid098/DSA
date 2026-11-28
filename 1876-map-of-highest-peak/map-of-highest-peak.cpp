class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        /*
        1 = water
        0 = land

        if 1 turn to 0

        adjacent cells must have absolute height difference of at most 1

            [0,1
             0,0]

            [1, O
             ?, 1]

                graph
             [0, 0, 1
              1, 0, 0
              0, 0, 0]

                height
             [1, 1, O
              O, 1, 1
              1, -1, -1]

              
            push all water to queue, and in height make them 0
            all land cells, in heigh make -1(not assigned yet)
            push 0s to queue
            pop queue, add 1 + popped value and make neighbours that value
            add these neighbours to queue
            if neighbours == -1, 
            
        */

        int ROWS = isWater.size();
        int COLS = isWater[0].size();
        std::vector<std::vector<int>> height(ROWS, std::vector<int>(COLS, 0));
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int, int>> directions{{1,0}, {0,1}, {-1,0}, {0,-1}};
        

        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (isWater[r][c] == 0){
                    height[r][c] = -1;
                }
                if (isWater[r][c] == 1){
                    height[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nc < 0 || nc >= COLS || nr < 0 || nr >= ROWS){
                        continue;
                    }

                    if (height[nr][nc] == -1){
                        height[nr][nc] = height[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return height;
    }
};