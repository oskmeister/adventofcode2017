#include <iostream>
#include <cassert>

using namespace std;

int calc(int X) {
    X -= 2;
    int s = 1;
    int c = 0;
    int a = 8;
    for (;;) {
        if (c + a > X) break;
        c += a; a += 8; s += 2;
    }
    if ((X-c) % (a / 4) < a / 8) {
        return s - ((X-c) % (a / 4));
    } else {
        return s - (a / 4) + ((X-c) % (a / 4)) + 2;
    }
}

int main() {
    int X;
    cin >> X;
    cout << calc(X) << endl;
}

