#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 2000

vector<int> neigh[MAX];
bool vis[MAX];

bool dfs(int at) {
    if (vis[at]) return false;
    vis[at] = true;
    for (auto n : neigh[at]) {
        dfs(n);
    }
    return true;
}

int main() {
    for (int i = 0; i < MAX; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int cur;
            cin >> cur;
            neigh[i].push_back(cur);
        }
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int n : neigh[cur]) {
            if (!vis[n]) {
                vis[n] = true;
                q.push(n);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX; ++i) ans += vis[i];
    cout << ans << endl;

    for (int i = 0; i < MAX; ++i) vis[i] = false;

    int comp = 0;
    for (int i = 0; i < MAX; ++i) {
        comp += dfs(i) ? 1 : 0;
    }
    cout << comp << " components" << endl;
}
