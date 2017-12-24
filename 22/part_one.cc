#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<bool>> grid;

int main() {
    string str;
    while (getline(cin, str)) {
        vector<bool> thisrow;
        for (char c : str) {
            thisrow.push_back(c == '#');
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
    for (int z = 0; z < 10000; ++z) {
/*        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (i == cr && j == cc) cout << "*" << " ";
                else cout << grid[i][j] << " ";
            }
            cout << endl;
        }*/
        if (min(cr,cc) < 1 || max(cr,cc) >= grid.size()-2) {
            cr += grid.size();
            cc += grid.size();
            vector<vector<bool>> newgrid(grid.size() * 3, vector<bool>(grid.size() * 3, false));
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid.size(); ++j) {
                    newgrid[grid.size() + i][grid.size() + j] = grid[i][j];
                }
            }
            grid = newgrid;
        }
        bool node_clean = !grid[cr][cc];
        if (node_clean) cd = (cd + 1) % 4;
        else cd = (cd + 3) % 4;
        if (node_clean) {
            grid[cr][cc] = true;
            ++ans;
        } else grid[cr][cc] = false;
        cr += dr[cd];
        cc += dc[cd];
    }

    cout << "Infected: " << ans << endl;
}
