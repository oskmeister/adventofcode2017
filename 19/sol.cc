#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> grid;
    for (;;) {
        string cur;
        if (!getline(cin, cur)) break;
        grid.push_back(cur);
    }

    int cr = 0;
    int cc;
    for (int i = 0; i < grid[0].size(); ++i) {
        if (grid[0][i] == '|') {
            cc = i;
            break;
        }
    }

    const vector<int> dr = { 1, 0, -1, 0};
    const vector<int> dc = { 0, 1, 0, -1};
    int cd = 0;

    string s;
    int steps = 0;
    while (grid[cr][cc] != ' ') {
        char c = grid[cr][cc];
        if (c >= 'A' && c <= 'Z') {
            s.push_back(c);
        }
        if (c == '+') {
            int nd1 = (cd + 1) % 4;
            int nd2 = (cd + 3) % 4;
            int nr1 = cr + dr[nd1];
            int nc1 = cc + dc[nd1];
            int nr2 = cr + dr[nd2];
            int nc2 = cc + dc[nd2];

            if (grid[nr1][nc1] == ' ') {
                cd = nd2;
            } else {
                cd = nd1;
            }
        }
        cr += dr[cd]; cc += dc[cd];
        ++steps;
    }
    cout << s << endl;
    cout << "Steps: " << steps << endl;

}
