#include <iostream>
#include <list>
#include <set>

using namespace std;

int main() {
    const int step_size = 312;
    int sz = 1;
    int cur = 0;
    int at = 0;
    for (int i = 1; i <= 50000000; ++i) {
        at += step_size;
        at %= sz;
        if (at == 0) {
            cur = i;
        }
        sz++;
        at++;
    }
    cout << cur << endl;
}
