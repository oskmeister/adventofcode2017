#include <iostream>
#include <vector>

using namespace std;

int get_score(vector<int> &grid) {
	int score = 0;
    for (int t = 0; t < grid.size(); ++t) {
        const int cur_size = grid[t];
        if (cur_size == 0) continue;
        const int cycle_len = 2 * cur_size - 2;
        const int offset = ((t % cycle_len) < cur_size) ? (t % cycle_len) : (cycle_len - (t % cycle_len) - 1);
        if (offset == 0) score += t * cur_size;
    }
	return score;
}

int solve(vector<int> &grid) {
    int delta = 0;
    for (;;) {
        ++delta;
        bool ok = true;
        for (int t = 0; t < grid.size(); ++t) {
            const int cur_size = grid[t];
            if (cur_size == 0) continue;
            const int cycle_len = 2 * cur_size - 2;
            const int offset = (((t+delta) % cycle_len) < cur_size) ? ((t+delta) % cycle_len) : (cycle_len - ((t+delta) % cycle_len) - 1);
            if (offset == 0) ok = false;
        }
        if (ok) return delta;
    }
	return 1337;
}

int main() {
    vector<pair<int,int>> input;
    int d, r;
    while (cin >> d) {
        cin >> r;
        input.push_back({d,r});
    }
    const int max_depth = input.rbegin()->first;
    vector<int> grid(max_depth+1, 0);
    for (auto x : input) {
        grid[x.first] = x.second;
    }
    cout << "Score: " << get_score(grid) << endl;
    cout << "Earliest escape time: " << solve(grid) << endl;
}
