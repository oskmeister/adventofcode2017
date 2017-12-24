#include <cassert>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using Pattern = vector<vector<bool>>;

Pattern read_pattern(int len) {
    Pattern pat_grid;
    for (int j = 0; j < len; ++j) {
        string str;
        cin >> str;
        vector<bool> v(len, false);
        for (int k = 0; k < str.size(); ++k)
            if (str[k] == '#') v[k] = true;
        pat_grid.push_back(v);
    }
    return pat_grid;
}

Pattern rotate90(const Pattern &p) {
    auto m = p;
    const int N = m.size();
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < (N + 1) / 2; j++) {
            bool temp = m[i][j];
            m[i][j] = m[N-1-j][i];
            m[N-1-j][i] = m[N-1-i][N-1-j];
            m[N-1-i][N-1-j] = m[j][N-1-i];
            m[j][N-1-i] = temp;
        }
    }
    return m;
}

void add_flips(Pattern p, Pattern r, map<Pattern, Pattern> &m) {
    m[p] = r;
    reverse(p.begin(), p.end());
    m[p] = r;
    for (auto &v : p) reverse(v.begin(), v.end());
    m[p] = r;
    reverse(p.begin(), p.end());
    m[p] = r;
}

void add_rotations(Pattern p, Pattern r, map<Pattern, Pattern> &m) {
    add_flips(p, r, m);
    p = rotate90(p);
    add_flips(p, r, m);
    p = rotate90(p);
    add_flips(p, r, m);
    p = rotate90(p);
    add_flips(p, r, m);
}

Pattern iterate(Pattern p, map<Pattern, Pattern> &m) {
    assert(p.size() == p[0].size());
    const int N = p.size();
    const int new_size = N % 2 == 0 ? ( 3 * (N / 2) ) : ( 4 * (N / 3) );
    const int new_square_size = N % 2 == 0 ? 3 : 4;
    const int old_square_size = new_square_size - 1;
    const int num_squares = new_size / new_square_size;
    Pattern result(new_size, vector<bool>(new_size, false));
    for (int i = 0; i < num_squares; ++i) {
        for (int j = 0; j < num_squares; ++j) {
            int start_r = i * old_square_size;
            int start_c = j * old_square_size;
            Pattern subp(old_square_size, vector<bool>(old_square_size, false));
            for (int k = 0; k < old_square_size; ++k) {
                for (int l = 0; l < old_square_size; ++l) {
                    subp[k][l] = p[start_r+k][start_c+l];
                }
            }
            assert(m.count(subp) > 0);
            Pattern newp = m[subp];
            int start_r2 = i * new_square_size;
            int start_c2 = j * new_square_size;
            for (int k = 0; k < new_square_size; ++k) {
                for (int l = 0; l < new_square_size; ++l) {
                    result[start_r2+k][start_c2+l] = newp[k][l];
                }
            }
        }
    }
    return result;
}

int main() {
    map<Pattern, Pattern> m;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int len;
        cin >> len;
        Pattern pat_grid = read_pattern(len);
        Pattern res_grid = read_pattern(len+1);
        add_rotations(pat_grid, res_grid, m);
    }
    Pattern start = {{false, true, false}, {false, false, true}, {true, true, true}};
    auto next = iterate(start, m);
    for (auto r : next) {
        for (auto x : r) cout << x << " ";
        cout << endl;
    }
    next = iterate(next, m);
    for (auto r : next) {
        for (auto x : r) cout << x << " ";
        cout << endl;
    }
    next = iterate(next, m);
    for (auto r : next) {
        for (auto x : r) cout << x << " ";
        cout << endl;
    }
    next = iterate(next, m);
    for (auto r : next) {
        for (auto x : r) cout << x << " ";
        cout << endl;
    }
    next = iterate(next, m);
    int sum = 0;
    for (auto r : next) {
        for (auto x : r) {
            cout << x << " ";
            sum += x;
        }
        cout << endl;
    }
    cout << "Enabled after 5 iters is " << sum << endl;
    for (int i = 0; i < 13; ++i) next = iterate(next, m);
    sum = 0;
    for (auto r : next) {
        for (auto x : r) {
            cout << x << " ";
            sum += x;
        }
        cout << endl;
    }
    cout << "Enabled after 18 iters is " << sum << endl;
}
