/*
 * Andrew Player
 * CS311
 * 10/06/2020
 * Source for Project 4
*/

#include "counthsw.h"

int countHSW_recurse(std::vector<std::vector<int>>& board, int dim_x, int dim_y, int cur_x, int cur_y, int finish_x, int finish_y, int squares_left) {   

    // Test for valid location
    if(cur_x < 0 || cur_y < 0
      || cur_x > dim_x - 1
      || cur_y > dim_y - 1
      || board[cur_x][cur_y] == 1) return 0;
    board[cur_x][cur_y] = 1;

    // Test for complete solution
    if(cur_x == finish_x && cur_y == finish_y
           && squares_left == 0) {
        return 1;
    }

    // Temp variables to restore after recursive call
    int total = 0;
    int temp_x = cur_x;
    int temp_y = cur_y;
    int squares_temp = squares_left;
    
    // Go through every adjacent and diagonal place
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            
            // No need to test the current place
            if(i == 0 && j == 0) continue;
            
            // Walk the spider
            cur_y += j;
            cur_x += i;
            
            // Test the place here to save a recursive call.
            if(cur_x < 0 || cur_y < 0
            || cur_x > board.size() - 1
            || cur_y > board[0].size() - 1
            || board[cur_x][cur_y] == 1) {
                cur_x = temp_x;
                cur_y = temp_y;
                continue;
            }

            squares_left--;
            
            total += countHSW_recurse(board, dim_x, dim_y, cur_x, cur_y, finish_x, finish_y, squares_left);
            
            // Restore the variables.
            board[cur_x][cur_y] = 0;
            squares_left = squares_temp;
            cur_y = temp_y;
            cur_x = temp_x;
        }
    }
    return total;
}

// Preconditions: dim_x > 0           && dim_y > 0
//                dim_x > hole_x >= 0  && dim_y > hole_y >= 0 
//                dim_x > start_x >= 0  && dim_y > start_x >= 0 
//                dim_x > finish_x >= 0  && dim_y > finish_y >= 0
int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y) {
    
    std::vector<std::vector<int>> board(dim_x, std::vector<int>(dim_y, 0));
    board[hole_x][hole_y] = 1; 
    int squares_left = dim_x*dim_y-2;
    int count = countHSW_recurse(board, dim_x, dim_y, start_x, start_y, finish_x, finish_y, squares_left);                                                                         
    return count;

}                