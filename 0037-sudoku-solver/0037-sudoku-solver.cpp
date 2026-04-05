class Solution {
public:
    int check_R[10][10];
    int check_C[10][10];
    int check_S[4][4][10];
    int check(int i, int j, int v){
        if(check_R[i][v] == 1 || check_C[j][v] == 1 || check_S[i/3][j/3][v] == 1){
            return 1;
        }
        return 0;
    }
    bool Try(int r, int c, vector<vector<char>>& board){
        if(r == 9){
            return true;
        }
        int next_r = (c == 8) ? r + 1 : r;
        int next_c = (c == 8) ? 0 : c + 1;
        if(board[r][c] != '.'){
            return Try(next_r, next_c, board);
        }
        for(int v = 1; v <= 9; v++){
            if(check(r,c,v) == 0){
                check_R[r][v] = 1;
                check_C[c][v] = 1;
                check_S[r/3][c/3][v] = 1;
                board[r][c] = v + '0';
                if(Try(next_r, next_c, board)){
                    return true;
                }
                board[r][c]= '.';
                check_R[r][v] = check_C[c][v] = check_S[r/3][c/3][v] = 0;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j <= 9; j++){
                check_R[i][j] = check_C[i][j] = 0;
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 9; k++){
                    check_S[i][j][k] = 0;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    check_R[i][board[i][j] - '0'] = 1;
                    check_C[j][board[i][j] - '0'] = 1;
                    check_S[i/3][j/3][board[i][j] - '0'] = 1;
                }
            }
        }
        Try(0, 0, board);
    }
};