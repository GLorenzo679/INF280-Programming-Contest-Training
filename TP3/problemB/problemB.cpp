#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
    int x, y, r;
} Point;

int bfs(vector<vector<int>> &graph, int start) {
    int N = graph.size();
    vector<bool> visited(N, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    int reachCount = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        reachCount++;

        for (int neighbor = 0; neighbor < N; neighbor++) {
            if (graph[node][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return reachCount;
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);

    // read the points
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y >> points[i].r;
    }

    // construct the graph
    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            int dist = dx * dx + dy * dy;

            if (dist <= points[i].r * points[i].r) graph[i][j] = 1;
            if (dist <= points[j].r * points[j].r) graph[j][i] = 1;
        }
    }

    // BFS for each node
    int maxReach = 0;
    for (int i = 0; i < N; i++) maxReach = max(maxReach, bfs(graph, i));

    cout << maxReach << endl;

    return 0;
}
