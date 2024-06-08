#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(int x, vector<int> &repr) {
    if (repr[x] < 0) return x;
    return repr[x] = find(repr[x], repr);
}

bool unite(int a, int b, vector<int> &repr) {
    a = find(a, repr);
    b = find(b, repr);

    if (a == b) return false;
    if (repr[a] > repr[b]) swap(a, b);

    repr[a] += repr[b];
    repr[b] = a;

    return true;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;

    vector<pair<int, pair<int, int>>> edges;
    vector<int> repr(N, -1);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            edges.push_back({dx * dx + dy * dy, {i, j}});
        }
    }

    // Kruskal's algorithm
    sort(edges.begin(), edges.end());
    int max_edge = 0;

    for (auto edge : edges) {
        if (unite(edge.second.first, edge.second.second, repr))
            max_edge = max(max_edge, edge.first);
    }

    cout << max_edge << endl;

    return 0;
}