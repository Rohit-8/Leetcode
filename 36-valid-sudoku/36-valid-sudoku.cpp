class Solution {
public:
    
     bool isValid(vector<vector<char>>& board, int x, int y, char c){
        //horizontal
        for(int i=0;i<9;i++){
            if(board[x][i] == c)
                return false;
        }
        //vertical
        for(int i=0;i<9;i++){
            if(board[i][y] == c)
                return false;
        }
        //inside it's block
        int strX = x/3;
        int strY = y/3;
        strX *=3;
        strY *=3;
        for(int i=strX;i<strX+3;i++){
            for(int j=strY;j<strY+3;j++){
                if(board[i][j] == c){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char c= board[i][j];
                    board[i][j] = '.';
                    if(isValid(board, i, j, c) == false)
                        return false;

                    board[i][j] = c;
                }
            }
        }
        
        return true;
    }
};