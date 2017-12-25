#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Instr {
    string name, param1, param2;
};

vector<long long> memory;
vector<Instr> program;

long long &m(const string &s) {
    return memory[s[0]-'a'];
}

bool is_number(const string &s) {
    return (s[0] == '-' || (s[0] >= '0' && s[0] <= '9'));
}

long long v(const string &s) {
    if (is_number(s))
        return stoi(s);
    return memory[s[0]-'a'];
}

int main() {
    memory.resize(8, 0);
    memory[0] = 1;
    for (;;) {
        Instr i;
        if (!(cin >> i.name)) break;
        cin >> i.param1 >> i.param2;
        program.push_back(i);
    }
    int it = 0;
    for (int i = 0; i < program.size(); ++i) {
        if (i == 8) {
            int ans = 0;
            int start = memory[1];
            int end = memory[2];
            for (int x = start; x <= end; x += 17) {
                bool isp = true;
                for (long long j = 2; j * j <= x; ++j) {
                    if (x % j == 0) {
                        isp = false;
                        break;
                    }
                }
                ans += !isp;
            }
            cout << ans << endl;
            return 0;
        }
        const Instr &cur = program[i];
        if (cur.name == "set") {
            m(cur.param1) = v(cur.param2);
        } else if (cur.name == "sub") {
            m(cur.param1) -= v(cur.param2);
        } else if (cur.name == "mul") {
            m(cur.param1) *= v(cur.param2);
        } else {
            assert(cur.name == "jnz");
            if (v(cur.param1) != 0) {
                i += v(cur.param2);
                --i;
            }
        }
        for (int j = 0; j < 8; ++j) cout << memory[j] << " ";
        cout << endl;
    }
    for (int j = 0; j < 8; ++j) cout << memory[j] << " ";
    cout << endl;
}
