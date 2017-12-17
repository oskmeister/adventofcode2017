#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Instruction {
    int type;
    int a, b;
    char c1, c2;
};

int main() {
    vector<Instruction> program;
    for (;;) {
        string s;
        if (!(cin >> s)) break;
        if (s == "spin") {
            int a;
            cin >> a;
            Instruction i = {0, a, 0, 'a', 'a'};
            program.push_back(i);
        } else if (s == "swap") {
            int a, b;
            cin >> a >> b;
            Instruction i = {1, a, b, 'a', 'a'};
            program.push_back(i);
        } else if (s == "swapname") {
            char a, b;
            cin >> a >> b;
            Instruction i = {2, 0, 0, a, b};
            program.push_back(i);
        }
    }

    string order;
    for (char c = 'a'; c <= 'p'; ++c) order.push_back(c);

    set<string> seen;
    seen.insert(order);

    vector<string> history;
    history.push_back(order);

    for (;;) {
        for (Instruction i : program) {
            if (i.type == 0) {
                rotate(order.rbegin(), order.rbegin() + i.a, order.rend());
            } else if (i.type == 1) {
                swap(order[i.a], order[i.b]);
            } else if (i.type == 2) {
                auto ai = find(order.begin(), order.end(), i.c1);
                auto bi = find(order.begin(), order.end(), i.c2);
                swap(*ai, *bi);
            }
        }
        if (seen.find(order) != seen.end()) {
            cout << "Cycle found after " << history.size() << " moves" << endl;
            break;
        }
        seen.insert(order);
        history.push_back(order);
    }

    cout << "First: " << history[1] << endl;
    cout << "Billionth: " << history[1000000000 % history.size()] << endl;
}
