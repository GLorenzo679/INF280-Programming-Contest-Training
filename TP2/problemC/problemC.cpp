#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    const int NB_NODES_MAX = 1000;
    int current = 1;
    int tot_cost = 0;
    int min_flow = INT_MAX;
    typedef pair<pair<int, int>, pair<int, int>> Pipe;
    Pipe candidate;
    vector<Pipe> path;
    vector<Pipe> pipes;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;

        pipes.push_back(Pipe(make_pair(a, b), make_pair(c, f)));
    }

    long long dist[NB_NODES_MAX];
    fill(dist, dist + N, LLONG_MAX);

    // priority queue in reverse order
    priority_queue<Pipe, vector<Pipe>, greater<Pipe>> p_queue;

    p_queue.push(pipes[0]);
    dist[pipes[0].first.first] = 0;

    while (!p_queue.empty()) {
        auto [node_dist, node] = p_queue.top();
        p_queue.pop();

        if (dist[node] == node_dist)  // lazy priority queue
            for (auto v : nxt[node])
                if (node_dist + v.second < dist[v.first]) {
                    dist[v.first] = node_dist + v.second;
                    p_queue.push(make_pair(dist[v.first], v.first));
                }
    }

    cout << "Path:\n";

    for (int i = 0; i < int(path.size()); i++) {
        cout << path[i].first.first << " " << path[i].first.second << " "
             << path[i].second.first << " " << path[i].second.second << endl;

        min_flow = min(min_flow, path[i].second.second);
        tot_cost += path[i].second.first;
    }

    cout << unsigned long(1000 * 1000 * (float)min_flow / tot_cost);

    return 0;
}