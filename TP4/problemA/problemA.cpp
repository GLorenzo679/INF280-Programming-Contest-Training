#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int u, int val, vector<int>& id, vector<vector<int>>& s_children,
         vector<vector<int>>& d_children) {
    id[u] = val;

    for (int v : s_children[u]) {
        if (id[v] == val) continue;
        if (id[v] != -1) {
            cout << "0\n";
            exit(0);
        }
        dfs(v, val, id, s_children, d_children);
    }

    for (int v : d_children[u]) {
        if (id[v] == !val) continue;
        if (id[v] != -1) {
            cout << "0\n";
            exit(0);
        }
        dfs(v, !val, id, s_children, d_children);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> s_children(N + 1);
    vector<vector<int>> d_children(N + 1);
    vector<int> id(N + 1, -1);

    for (int i = 0; i < M; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        if (type == 'S') {
            s_children[a].push_back(b);
            s_children[b].push_back(a);
        } else {
            d_children[a].push_back(b);
            d_children[b].push_back(a);
        }
    }

    string output = "1";

    for (int i = 1; i <= N; i++) {
        if (id[i] == -1) {
            dfs(i, 1, id, s_children, d_children);
            output += "0";
        }
    }

    cout << output << endl;

    return 0;
}
