#include "counthsw.h"

int countHSW_recurse(std::vector<std::vector<int>> board, int cur_x, int cur_y, int finish_x, int finish_y, int squares_left) {   
    if(cur_x < 0 || cur_y < 0
      || cur_x > board.size() - 1
      || cur_y > board[0].size() - 1
      || board[cur_x][cur_y] == 1) return 0;
    board[cur_x][cur_y] = 1;
    if(cur_x == finish_x && cur_y == finish_y
           && squares_left == 0) {
        return 1;
    }
    int total = 0;
    int temp_x = cur_x;
    int temp_y = cur_y;
    int squares_temp = squares_left;
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            if(i == 0 && j == 0) continue;
            cur_y += j;
            cur_x += i;
            if(cur_x < 0 || cur_y < 0
            || cur_x > board.size() - 1
            || cur_y > board[0].size() - 1
            || board[cur_x][cur_y] == 1) {
                cur_x = temp_x;
                cur_y = temp_y;
                continue;
            }
            squares_left--;
            total += countHSW_recurse(board, cur_x, cur_y, finish_x, finish_y, squares_left);
            squares_left = squares_temp;
            cur_y = temp_y;
            cur_x = temp_x;
        }
    }
    return total;
}

int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y) {
    
    std::vector<std::vector<int>> board(dim_x, std::vector<int>(dim_y, 0));
    board[hole_x][hole_y] = 1; 
    int squares_left = dim_x*dim_y-2;
    int count = countHSW_recurse(board, start_x, start_y, finish_x, finish_y, squares_left);                                                                         
    return count;

}                