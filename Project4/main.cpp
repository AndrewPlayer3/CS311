#include "counthsw.h"
#include "chrono"

int main() {

    int dim_x = 3;
    int dim_y = 5;
    int hole_x = 0;
    int hole_y = 0;
    int start_x = 1;
    int start_y = 1;
    int finish_x = 2;
    int finish_y = 4;

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    int count = countHSW(dim_x, dim_y, hole_x, hole_y, start_x, start_y, finish_x, finish_y);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    std::cout << count <<  std::endl;
    std::cout << "Time: " << time.count() << std::endl;

    return 0;

}