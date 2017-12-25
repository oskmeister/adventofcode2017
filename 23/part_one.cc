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
    for (;;) {
        Instr i;
        if (!(cin >> i.name)) break;
        cin >> i.param1 >> i.param2;
        program.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < program.size(); ++i) {
        for (int j = 0; j < 8; ++j) cout << memory[j] << " ";
        cout << endl;
        const Instr &cur = program[i];
        if (cur.name == "set") {
            m(cur.param1) = v(cur.param2);
        } else if (cur.name == "sub") {
            m(cur.param1) -= v(cur.param2);
        } else if (cur.name == "mul") {
            ++ans;
            m(cur.param1) *= v(cur.param2);
        } else {
            assert(cur.name == "jnz");
            if (v(cur.param1) != 0) {
                i += v(cur.param2);
                --i;
            }
        }
    }
    cout << "Mul called " << ans << " times." << endl;
}
