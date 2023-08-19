class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int c = 0;
                if(i > 0 and (board[i - 1][j] == -1 or board[i - 1][j] == 1))
                    c++;
                if(i + 1 < n and (board[i + 1][j] == 1 or board[i + 1][j] == -1))
                    c++;
                if(j > 0 and (board[i][j - 1] == 1 or board[i][j - 1] == -1))
                    c++;
                if(j + 1 < m and (board[i][j + 1] == 1 or board[i][j + 1] == -1))
                    c++;
                if(i > 0 and j > 0 and (board[i - 1][j - 1] == 1 or board[i - 1][j - 1] == -1))
                    c++;
                if(i > 0 and j + 1 < m and (board[i - 1][j + 1] == 1 or board[i - 1][j + 1] == -1))
                    c++;
                if(i + 1 < n and j > 0 and (board[i + 1][j - 1] == 1 or board[i + 1][j - 1] == -1))
                    c++;
                if(i + 1 < n and j + 1 < m and (board[i + 1][j + 1] == 1 or board[i + 1][j + 1] == -1))
                    c++;
                
                // check for alive or dead
                if((c < 2 or c > 3) and board[i][j] == 1)
                    board[i][j] = -1;
                else if(c == 3 and board[i][j] == 0)
                    board[i][j] = -2;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == -2)
                    board[i][j] = 1;
            }
        }
        
        return;
    }
};