class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check_row[9][10] = {0};
        int check_col[9][10] = {0};
        int check_grid[9][10] = {0};
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                
                int num = board[i][j] - '0';
                int grid_index = (i/3)*3 + (j/3);
                if(check_row[i][num] > 0 || check_col[j][num] > 0 || check_grid[grid_index][num] > 0){
                    return false;
                }

                check_row[i][num] = 1;
                check_col[j][num] = 1;
                check_grid[grid_index][num] = 1;
            }
        }
        return true;
    }
};