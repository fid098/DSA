class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        std::vector<std::pair<int, int>> directions {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        std::queue<std::pair<int, int>> q;

        //make every border O to T
        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                bool border = (r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1);
                if (board[r][c] == 'O' && border){
                    board[r][c] = 'T';
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr , dc] : directions){
                    int nr = dr + r;
                    int nc = dc + c;

                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || board[nr][nc] == 'X'){
                        continue;
                    }
                    if (board[nr][nc] == 'O'){
                        board[nr][nc] = 'T';
                        q.push({nr, nc});
                    }
                }
            }
        }


        //make every normal O to X
        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }


        //change every T to O
        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                if (board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
            }
        }


        

        
    }
};