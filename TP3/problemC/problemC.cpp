#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int START_B = 0;
const int START_E = 1;

struct Edge {
    int to, cost;
};

vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        cout << "current_dist: " << current_dist << " u: " << u << endl;

        if (current_dist > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to, cost = edge.cost;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});

                cout << "dist[" << v << "]: " << dist[v] << endl;
            }
        }
    }

    return dist;
}

int main() {
    int B, E, P, N, M;
    cin >> B >> E >> P >> N >> M;

    vector<vector<Edge>> graphB(N), graphE(N), graphP(N);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        graphB[u].push_back({v, B});
        graphB[v].push_back({u, B});

        graphE[u].push_back({v, E});
        graphE[v].push_back({u, E});

        graphP[u].push_back({v, P});
        graphP[v].push_back({u, P});
    }

    vector<int> distB = dijkstra(0, graphB);
    vector<int> distE = dijkstra(1, graphE);
    vector<int> distP = dijkstra(N - 1, graphP);

    int min_energy = INT_MAX;

    for (int i = 0; i < N; ++i) {
        if (distB[i] != INT_MAX && distE[i] != INT_MAX && distP[i] != INT_MAX) {
            min_energy = min(min_energy, distB[i] + distE[i] + distP[i]);
        }
    }

    cout << min_energy << endl;

    return 0;
}
