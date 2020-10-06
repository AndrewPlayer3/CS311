/*
 * Andrew Player
 * CS311
 * 10/03/2020
 * Header for Project 4
*/

#ifndef COUNTHSW_H_
#define COUNTHSW_H_

#include <iostream>
#include <vector>

int countHSW_recurse(std::vector<std::vector<int>> board, int cur_x, int cur_y, int squares_left);

int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y);

#endif
