#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<pair<int,int>> v;
map<pair<int, long long>, pair<int,int>> cache;

pair<int, int> solve(int cur, long long bits) {
    if (cache.find(make_pair(cur, bits)) != cache.end())
        return cache[make_pair(cur, bits)];
    auto ans = make_pair(0,0);
    for (int i = 0; i < v.size(); ++i) {
        if ((1LL<<i) & bits) continue;
        auto p = v[i];
        const int to_add = p.first + p.second;
        if (p.first == cur) {
            auto p1 = solve(p.second, bits | (1LL << i));
            p1.first += 1;
            p1.second += to_add;
            if (p1 > ans) ans = p1;
        }
        if (p.second == cur) {
            auto p2 = solve(p.first, bits | (1LL << i));
            p2.first += 1;
            p2.second += to_add;
            if (p2 > ans) ans = p2;
        }
    }
    cache[make_pair(cur, bits)] = ans;
    return ans;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    cout << solve(0, 0).second << endl;
}
