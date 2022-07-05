#include <iostream>
#include <set>
#include <vector>

using namespace std;

void initEdge(vector<int>* in, vector<int>* out, int v, int w) {
    out[v].push_back(w);
    in[w].push_back(v);
}

void initGraph(int n, int m, const string& colors, vector<int>* in, vector<int>* out) {
    set<pair<char, char>> asc = {make_pair('R', 'G'), make_pair('G', 'B'), make_pair('B', 'R')};

    int v, w;
    for (int i = 0; i < m; i++) {
        cin >> v >> w;
        if (colors[v - 1] == colors[w - 1]) {
            initEdge(in, out, v - 1, w - 1 + n);
            initEdge(in, out, v - 1 + n, w - 1);
            initEdge(in, out, w - 1, v - 1 + n);
            initEdge(in, out, w - 1 + n, v - 1);
        } else if (asc.count(make_pair(colors[v - 1], colors[w - 1]))) {
            initEdge(in, out, v - 1 + n, w - 1 + n);
            initEdge(in, out, w - 1, v - 1);
        } else {
            initEdge(in, out, w - 1 + n, v - 1 + n);
            initEdge(in, out, v - 1, w - 1);
        }
    }
}

void sort_by_out_time(vector<int>* out, bool* used, vector<int>& sorted_by_out_time, int v) {
    if (used[v]) return;
    used[v] = true;
    for (int w: out[v]) {
        sort_by_out_time(out, used, sorted_by_out_time, w);
    }
    sorted_by_out_time.push_back(v);
}

void paint(vector<int>* in, int* components, int color, int v) {
    if (components[v] != -1) return;
    components[v] = color;
    for (int w: in[v]) {
        paint(in, components, color, w);
    }
}

void initComponents(int n, vector<int>* in, vector<int>* out, int* components) {
    bool used[2 * n];
    vector<int> sorted_by_out_time;
    for (int i = 0; i < 2 * n; i++) {
        used[i] = false;
        components[i] = -1;
    }
    for (int i = 0; i < 2 * n; i++) {
        sort_by_out_time(out, used, sorted_by_out_time, i);
    }
    int color = 0;
    for (int i = 2 * n - 1; i > -1; i--) {
        if (components[sorted_by_out_time[i]] == -1) {
            paint(in, components, color, sorted_by_out_time[i]);
            color++;
        }
    }
}

bool initColors(int n, const int* components, bool* colors) {
    for (int i = 0; i < n; i++) {
        if (components[i] == components[i + n]) {
            return false;
        } else {
            colors[i] = components[i] > components[i + n];
        }
    }
    return true;
}

void printResult(int n, string startColors, const bool* colors) {
    for (int i = 0; i < n; i++) {
        if (startColors[i] == 'R') {
            cout << (colors[i] ? 'G' : 'B');
        } else if (startColors[i] == 'G') {
            cout << (colors[i] ? 'B' : 'R');
        } else {
            cout << (colors[i] ? 'R' : 'G');
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string startColors;
    cin >> startColors;

    vector<int> in[2 * n], out[2 * n];
    initGraph(n, m, startColors, in, out);

    int components[2 * n];
    initComponents(n, in, out, components);

    bool colors[n];
    if (initColors(n, components, colors)) {
        printResult(n, startColors, colors);
    } else {
        cout << "Impossible";
    }
}
