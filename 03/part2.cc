#include <iostream>

using namespace std;

const int sz = 1000;
const int dr[4] = {0, -1, 0, 1};
const int dc[4] = {1, 0, -1, 0};

int grid[sz][sz];

int main() {
    int X;
    cin >> X;

    int r = sz / 2;
    int c = sz / 2;

    grid[r][c] = 1;

    int steps = 1;

    int dir = 0;
    for (;;) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < steps; ++j) {

                r += dr[dir];
                c += dc[dir];

                grid[r][c] = grid[r+1][c] + grid[r][c+1] + grid[r-1][c] + grid[r][c-1]
                                   + grid[r-1][c-1] + grid[r-1][c+1] + grid[r+1][c-1] + grid[r+1][c+1];

                if (grid[r][c] > X) {
                    cout << grid[r][c] << endl;
                    return 0;
                }
            }
            dir = (dir + 1) % 4;
        }
        ++steps;
    }
}
