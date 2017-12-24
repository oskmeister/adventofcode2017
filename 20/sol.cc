#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Particle {
    long long cx, cy, cz,
              vx, vy, vz,
              ax, ay, az;
    bool operator ==(const Particle &other) const {
        return cx == other.cx && cy == other.cy && cz == other.cz;
    }
};

void step(vector<Particle> &v) {
    for (auto &p : v) {
        p.vx += p.ax;
        p.vy += p.ay;
        p.vz += p.az;
        p.cx += p.vx;
        p.cy += p.vy;
        p.cz += p.vz;
    }
    sort(v.begin(), v.end(), [](const Particle &p1, const Particle &p2) {
        if (p1.cx != p2.cx)
            return p1.cx < p2.cx;
        if (p1.cy != p2.cy)
            return p1.cy < p2.cy;
        return p1.cz < p2.cz;
    });
    vector<Particle> newv;
    for (int i = 0; i < v.size(); ++i) {
        bool skip = false;
        if (i > 0 && v[i - 1] == v[i]) skip = true;
        if (i < v.size() - 1 && v[i + 1] == v[i]) skip = true;
        if (!skip) newv.push_back(v[i]);
    }
    v = newv;
}

int main() {
    vector<Particle> v;
    for (;;) {
        Particle p;
        if (scanf("p=<%lld,%lld,%lld>, v=<%lld,%lld,%lld>, a=<%lld,%lld,%lld>\n",
                &p.cx, &p.cy, &p.cz,
                &p.vx, &p.vy, &p.vz,
                &p.ax, &p.ay, &p.az) != 9) break;
        v.push_back(p);
    }

    for (;;) {
        step(v);
        cout << v.size() << endl;
    }
}
