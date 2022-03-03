#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<vector<char>> g, int w, int h, pair<int, int> src, pair<int, int> trg) {
    bool used[h][w];
    pair<int, int> parents[h][w];
    queue<pair<int, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            used[i][j] = false;
        }
    }
    used[src.first][src.second] = true;
    q.push(src);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == trg.first and cur.second == trg.second) {
            cout << "YES" << "\n";

            stack<pair<int, int>> r;
            pair<int, int> t = trg;
            while (t.first != src.first or t.second != src.second) {
                r.push(t);
                t = parents[t.first][t.second];
            }
            r.push(src);

            while (not r.empty()) {
                cout << r.top().second + 1 << ' ' << r.top().first + 1 << ' ';
                r.pop();
            }

            return;
        }

        if (cur.first > 0 and not used[cur.first - 1][cur.second] and g[cur.first - 1][cur.second] == '.') {
            parents[cur.first - 1][cur.second] = cur;
            q.push(make_pair(cur.first - 1, cur.second));
            used[cur.first - 1][cur.second] = true;
        }

        if (cur.first < h - 1 and not used[cur.first + 1][cur.second] and g[cur.first + 1][cur.second] == '.') {
            parents[cur.first + 1][cur.second] = cur;
            q.push(make_pair(cur.first + 1, cur.second));
            used[cur.first + 1][cur.second] = true;
        }

        if (cur.second > 0 and not used[cur.first][cur.second - 1] and g[cur.first][cur.second - 1] == '.') {
            parents[cur.first][cur.second - 1] = cur;
            q.push(make_pair(cur.first, cur.second - 1));
            used[cur.first][cur.second - 1] = true;
        }

        if (cur.second < w - 1 and not used[cur.first][cur.second + 1] and g[cur.first][cur.second + 1] == '.') {
            parents[cur.first][cur.second + 1] = cur;
            q.push(make_pair(cur.first, cur.second + 1));
            used[cur.first][cur.second + 1] = true;
        }
    }

    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;

    vector<vector<char>> g(h);
    for (auto& row: g) {
        string s;
        cin >> s;
        row = vector<char>(s.begin(), s.end());
    }

    bfs(g, w, h, make_pair(y1 - 1, x1 - 1), make_pair(y2 - 1, x2 - 1));
}
