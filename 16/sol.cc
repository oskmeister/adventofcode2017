#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

std::function<string(string,int)> generate_perm() {
    string order;

    for (char c = 'a'; c <= 'p'; ++c) order.push_back(c);

    for (;;) {
        string s;
        if (!(cin >> s)) break;
        if (s == "spin") {
            int a;
            cin >> a;
            rotate(order.rbegin(), order.rbegin() + a, order.rend());
        } else if (s == "swap") {
            int a, b;
            cin >> a >> b;
            swap(order[a], order[b]);
        } else if (s == "swapname") {
            char a, b;
            cin >> a >> b;
            auto ai = find(order.begin(), order.end(), a);
            auto bi = find(order.begin(), order.end(), b);
            swap(*ai, *bi);
        }
    }

    vector<int> perm(16);
    for (int i = 0; i < 16; ++i) {
        perm[i] = find(order.begin(), order.end(), ('a'+i)) - order.begin();
    }

    return [perm](const string &s, int iterations) {
        string result(16, 'a');
        for (int i = 0; i < 16; ++i) {
            result[perm[i]] = s[i];
        }
        return result;
    };
}

int main() {
    auto f = generate_perm();
    string order;
    for (char c = 'a'; c <= 'p'; ++c) order.push_back(c);
    auto result = f(order, 1);
    cout << "Once: " << result << endl;
    for (int i = 0; i < 999999999; ++i) result = f(result, 1);
    cout << "10^9: " << result << endl;
}
