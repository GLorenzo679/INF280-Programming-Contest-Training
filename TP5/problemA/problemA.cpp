#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<unsigned long long>> L(N, vector<unsigned long long>(N, 0));
    unsigned long long min_cost = 0;

    for (int i = 0; i < N; i++) {
        cin >> L[N - 1][i];
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = N - 1; i > 0; i--) {
        unsigned long long tmp = L[i][N - 1 - i] + L[i][N - 1 - i + 1];
        int idx = N - 1 - i + 1;

        for (int j = N - 1 - i + 2; j < N; j++) {
            if (tmp > L[i][j] + L[i][j - 1]) {
                tmp = L[i][j] + L[i][j - 1];
                idx = j;
            }
        }

        min_cost += tmp;

        for (int j = N - 1 - i; j < N; j++) {
            if (j != idx - 1 && j != idx && j < idx - 1) {
                L[i - 1][j + 1] = L[i][j];
            } else if (j == idx - 1) {
                continue;
            } else if (j == idx) {
                L[i - 1][j] = tmp;
            } else if (j != idx - 1 && j != idx && j > idx) {
                L[i - 1][j] = L[i][j];
            }
        }
    }

    cout << min_cost << endl;

    return 0;
}
