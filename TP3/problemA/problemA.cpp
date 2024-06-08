#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int y, x;
};

int get_idx_node(int x, int y, int C) { return y * C + x; }

string bfs(int startX, int startY, int endX, int endY,
           vector<vector<char>> grid) {
    int R = grid.size();
    int C = grid[0].size();

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    unordered_map<int, Node> parent;
    queue<Node> q;
    string path = "";

    unordered_map<char, pair<int, int>> directions = {
        {'U', {0, -1}}, {'D', {0, 1}}, {'L', {-1, 0}}, {'R', {1, 0}}};

    parent[get_idx_node(startX, startY, C)] = {-1, -1};
    q.push({startY, startX});
    visited[startY][startX] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.x == endX && node.y == endY) {
            while (parent[get_idx_node(node.x, node.y, C)].x != -1) {
                Node p = parent[get_idx_node(node.x, node.y, C)];
                if (p.x < node.x)
                    path = "R" + path;
                else if (p.x > node.x)
                    path = "L" + path;
                else if (p.y < node.y)
                    path = "D" + path;
                else if (p.y > node.y)
                    path = "U" + path;

                node = p;
            }

            return path;
        }

        for (auto [dir, d] : directions) {
            int newX = node.x + d.first;
            int newY = node.y + d.second;

            if (newX >= 0 && newX < C && newY >= 0 && newY < R &&
                grid[newY][newX] != '#' && !visited[newY][newX]) {
                parent[get_idx_node(newX, newY, C)] = {node.y, node.x};
                q.push({newY, newX});
                visited[newY][newX] = true;
            }
        }
    }

    return "";
}

int main() {
    int C, R;
    cin >> C >> R;
    vector<vector<char>> grid(R, vector<char>(C));

    int startX, startY, endX, endY = -1;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                startX = j;
                startY = i;
            } else if (grid[i][j] == 'D') {
                endX = j;
                endY = i;
            }
        }
    }

    cout << bfs(startX, startY, endX, endY, grid) << endl;

    return 0;
}
