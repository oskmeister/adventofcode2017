#include <iostream>
#include <vector>

using namespace std;

struct Action {
    int write_value;
    int movement;
    int goto_state;
};

struct State {
    Action actions[2];
};

int main() {
    char start_state;
    cin >> start_state;
    int steps;
    cin >> steps;

    const int num_states = 6;
    vector<State> states(num_states);
    for (int i = 0; i < num_states; ++i) {
        char state_index;
        cin >> state_index;
        for (int j = 0; j < 2; ++j) {
            int cond_value;
            cin >> cond_value;
            State &s = states[i];
            Action &a = s.actions[j];
            cin >> a.write_value;
            cin >> a.movement;
            char go_to_state;
            cin >> go_to_state;
            a.goto_state = go_to_state - 'A';
        }
    }

    vector<int> tape(1);
    int tape_index = 0;
    int at_state = 0;
    for (int i = 0; i < steps; ++i) {
//        cout << "now at " << tape_index << endl;
        if (tape_index == -1) {
            tape.insert(tape.begin(), 0);
            tape_index++;
        } else if (tape_index == tape.size()) {
            tape.push_back(0);
        }
        const State &s = states[at_state];
        const Action &a = s.actions[tape[tape_index]];
        tape[tape_index] = a.write_value;
        tape_index += a.movement;
        at_state = a.goto_state;
    }

    int ans = 0;
    for (int x : tape) {
        ans += x;
    }
    cout << ans << endl;
}
