#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int inf = INT32_MAX - 10000;

void bellman_ford(int n, const vector<pair<pair<int, int>, int>>& es, int src) {
    int dists[n], parents[n], step = 0, cur;
    bool used[n], changed = true;
    vector<int> result;
    stack<int> path;

    for (int i = 0; i < n; i++) {
        dists[i] = i == src ? 0 : inf;
        used[i] = false;
    }

    while (step < n - 1 and changed) {
        changed = false;
        for (const auto & e : es) {
            if (dists[e.first.first] < inf and dists[e.first.second] > dists[e.first.first] + e.second) {
                dists[e.first.second] = max(-inf, dists[e.first.first] + e.second);
                parents[e.first.second] = e.first.first;
                changed = true;
            }
        }
        step += 1;
    }

    for (const auto & e : es) {
        if (dists[e.first.first] < inf and dists[e.first.second] > dists[e.first.first] + e.second) {
            parents[e.first.second] = e.first.first;

            cur = e.first.second;
            while (not used[cur]) {
                path.push(cur);
                used[cur] = true;
                cur = parents[cur];
            }

            result.push_back(cur);
            while(path.top() != cur) {
                result.push_back(path.top());
                path.pop();
            }

            cout << "YES" <<'\n';
            cout << result.size() << '\n';
            for (int v : result) {
                cout << v + 1 << ' ';
            }
            return;
        }
    }
    cout << "NO";
}

int main() {
    int n, w;
    cin >> n;
    vector<pair<pair<int, int>, int>> es;

    for (int i = 0; i < n; i++) {
        es.emplace_back(make_pair(n, i), 0);
        for (int j = 0; j < n; j++) {
            cin >> w;
            if (w != 100000) {
                es.emplace_back(make_pair(i, j), w);
            }
        }
    }

    bellman_ford(n + 1, es, n);
}

