#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

struct Instr {
    string op;
    char mem;
    string param;
};

bool is_number(const string &s) {
    return s[0] == '-' || (s[0] > '0' && s[0] <= '9');
}

queue<long long> rcv_queues[2];
mutex mutexes[2];
condition_variable cond[2];

void execute(int id, const vector<Instr> &program) {
    vector<long long> mem(26, 0);
    mem['p' - 'a'] = id;
    long long send_count = 0;
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
            if (p.mem >= '0' && p.mem <= '9' && (p.mem-'0') > 0) {
                i += val;
                --i;
            } else if (mem[p.mem-'a'] > 0) {
                i += val;
                --i;
            }
        } else if (p.op == "add") {
            mem[p.mem-'a'] += val;
        } else if (p.op == "mod") {
            mem[p.mem-'a'] %= val;
        } else if (p.op == "snd") {
            std::unique_lock<std::mutex> lock(mutexes[id ^ 1]);
            rcv_queues[id ^ 1].push(val);
            cond[id ^ 1].notify_one();
            ++send_count;
        } else if (p.op == "rcv") {
            std::unique_lock<std::mutex> lock(mutexes[id]);
            cond[id].wait(lock, [&] { return !rcv_queues[id].empty(); });
            long long v = rcv_queues[id].front();
            rcv_queues[id].pop();
            mem[p.param[0]-'a'] = v;
        }
        if (id == 1) cout << send_count << endl;
    }
}

int main() {
    vector<Instr> program;
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
    thread t1(execute, 0, program);
    thread t2(execute, 1, program);
    t1.join();
    t2.join();
}
