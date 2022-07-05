#include <iostream>
#include <vector>

using namespace std;

const int maxN = 20000;
vector<int> g[maxN];
bool used[maxN], point[maxN];
int timeIn[maxN], up[maxN], t = 0;

int dfs(int parent, int src) {
    timeIn[src] = up[src] = t++;
    used[src] = true;
    int pointsCount = 0, power = 0;
    for (int& trg : g[src]) {
        if (used[trg]) {
            up[src] = trg != parent ? min(timeIn[trg], up[src]) : up[src];
        } else {
            power++;
            pointsCount += dfs(src, trg);
            up[src] = min(up[src], up[trg]);
            point[src] |= parent != src and timeIn[src] <= up[trg] or parent == src and power > 1;
        }
    }
    return pointsCount + int(point[src]);
}

int main() {
    int n, m, src, trg;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        used[i] = point[i] = false;
    }

    for (int i = 0; i < m; i++) {
        cin >> src >> trg;
        g[src - 1].push_back(trg - 1);
        g[trg - 1].push_back(src - 1);
    }

    cout << dfs(0, 0) << '\n';
    for (int i = 0; i < n; i++) {
        if (point[i]) {
            cout << i + 1 << '\n';
        }
    }
}
