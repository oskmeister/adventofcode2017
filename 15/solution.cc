#include <iostream>
#include <vector>

using namespace std;

const long long lowest_16 = (1LL<<16) - 1;

void part_two() {
    const int wanted = 5000000;
    vector<int> list_a;
    list_a.reserve(wanted);
    vector<int> list_b;
    list_b.reserve(wanted);

    {
        long long a = 783;
        while (list_a.size() < wanted) {
            a *= 16807LL;
            a %= 2147483647LL;
            if (a % 4 == 0) list_a.push_back(a);
        }
    }

    {
        long long b = 325;
        while (list_b.size() < wanted) {
            b *= 48271LL;
            b %= 2147483647LL;
            if (b % 8 == 0) list_b.push_back(b);
        }
    }

    int matches = 0;
    for (int i = 0; i < wanted; ++i) {
        long long fi = list_a[i];
        long long se = list_b[i];
        if ((fi & lowest_16) == (se & lowest_16)) {
            ++matches;
        }
    }
    cout << "Part two:" << matches << endl;
}

int main() {
    long long a = 783;
    long long b = 325;
    int matches = 0;
    for (int i = 0; i < 40000000; ++i) {
        a *= 16807LL;
        b *= 48271LL;
        a %= 2147483647LL;
        b %= 2147483647LL;
        if ((a & lowest_16) == (b & lowest_16)) {
            ++matches;
        }
    }
    cout << "Part one: " << matches << endl;
    part_two();

}
