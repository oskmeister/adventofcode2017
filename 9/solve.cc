#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, real;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '!') ++i;
        else real.push_back(str[i]);
    }
    cout << real << endl;
    bool g = false;
    int d = 1;
    int s = 0;
    int ignored = 0;
    for (int i = 0; i < real.size(); ++i) {
        const char c = real[i];
        if (g) {
            if (c == '>') {
                g = false;
                continue;
            }
            ignored++;
        } else {
            if (c == '<') {
                g = true;
                continue;
            }
            if (c == '{') {
                ++d;
            } else if (c == '}') {
                --d;
                s += d;
            }
        }
    }

    cout << s << endl;
    cout << "Ignored: " << ignored << endl;
}
