#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int>> grid;

int main() {
    string str;
    while (getline(cin, str)) {
        vector<int> thisrow;
        for (char c : str) {
            thisrow.push_back(c == '#' ? 2 : 0) ;
        }
        grid.push_back(thisrow);
    }
    const int N = grid.size();
    int cr = N / 2;
    int cc = N / 2;
    int cd = 0;
    vector<int> dr = { -1, 0, 1, 0 };
    vector<int> dc = { 0, -1, 0, 1 };
    int ans = 0;
    for (int z = 0; z < 10000000; ++z) {
        if (min(cr,cc) < 1 || max(cr,cc) >= grid.size()-2) {
            cr += grid.size();
            cc += grid.size();
            vector<vector<int>> newgrid(grid.size() * 3, vector<int>(grid.size() * 3, false));
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid.size(); ++j) {
                    newgrid[grid.size() + i][grid.size() + j] = grid[i][j];
                }
            }
            grid = newgrid;
        }

        const int val = grid[cr][cc];
        if (val == 0) {
            cd = (cd + 1) % 4;
        } else if (val == 2) {
            cd = (cd + 3) % 4;
        } else if (val == 3) {
            cd = (cd + 2) % 4;
        }

        if (grid[cr][cc] == 1) ++ans;
        grid[cr][cc]++;
        grid[cr][cc] %= 4;

        cr += dr[cd];
        cc += dc[cd];
    }

    cout << "Infected: " << ans << endl;
}
