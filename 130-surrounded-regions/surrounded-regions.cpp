class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        std::vector<std::vector<bool>> safe(ROWS, std::vector<bool>(COLS, false));
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int, int>> directions{{0,1}, {1,0}, {-1,0}, {0,-1}};


        //if on the borders add to queue
        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if ((r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1 ) && board[r][c] == 'O'){
                    q.push({r, c});
                    safe[r][c] = true;
                }
            }
        }


        //from every boarder, find the connecting 0s and mark them safe 
        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS  && board[nr][nc] == 'O' && !safe[nr][nc]){
                        q.push({nr, nc});
                        safe[nr][nc] = true;
                    }
                }

            }
        }

        //mark every 0 that was not marked safe
        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (board[r][c] == 'O' && !safe[r][c]){
                    board[r][c] = 'X';
                }
            }
        }

        
    }
};