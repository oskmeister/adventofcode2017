#include <iostream>
#include <list>

using namespace std;

int main() {
    const int step_size = 312;
    list<int> l;
    l.push_back(0);
    auto it = l.begin();
    for (int i = 1; i <= 2017; ++i) {
        for (int j = 0; j < step_size; ++j) {
            it++;
            if (it == l.end()) it = l.begin();
        }
        ++it;
        if (it == l.end()) it = l.begin();
        it = l.insert(it, i);
    }
    ++it;
    if (it == l.end()) it = l.begin();
    cout << *it << endl;
}
