#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Instr {
    string op;
    char mem;
    string param;
};

bool is_number(const string &s) {
    return s[0] == '-' || (s[0] > '0' && s[0] <= '9');
}

int main() {
    vector<Instr> program;
    vector<long long> mem(26, 0);
    for (;;) {
        string input;
        char memory;
        string param;
        if (!(cin >> input)) {
            break;
        }
        if (input == "snd" || input == "rcv") {
            char c;
            cin >> c;
            param.push_back(c);
        } else {
            cin >> memory >> param;
        }
        program.push_back({input, memory, param});
    }
    int lastplayed = -1;
    for (int i = 0; i < program.size(); ++i) {
        const Instr &p = program[i];
        long long val;
        if (is_number(p.param)) {
            val = stoi(p.param);
        } else {
            val = mem[p.param[0]-'a'];
        }
        if (p.op == "set") {
            mem[p.mem-'a'] = val;
        } else if (p.op == "mul") {
            mem[p.mem-'a'] *= val;
        } else if (p.op == "jgz") {
            if (mem[p.mem-'a'] > 0) {
                i += val;
                --i;
            }
        } else if (p.op == "add") {
            mem[p.mem-'a'] += val;
        } else if (p.op == "mod") {
            mem[p.mem-'a'] %= val;
        } else if (p.op == "snd") {
            cout << "Playing " << val << endl;
            lastplayed = val;
        } else if (p.op == "rcv") {
            if (mem[p.mem-'a'] != 0) {
                cout << "Last played sound:" << lastplayed << endl;
                return 0;
            }
        }
    }
}
