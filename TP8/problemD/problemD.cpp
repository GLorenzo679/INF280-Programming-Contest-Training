#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int manhattanDistance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> checkpoints(N);
    for (int i = 0; i < N; ++i) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    // dp[i][j] will store the minimum distance to reach checkpoint i with j
    // skips
    vector<vector<int>> dp(N, vector<int>(K + 1, INT_MAX));

    dp[0][0] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[i - 1][j] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + manhattanDistance(
                                                            checkpoints[i - 1],
                                                            checkpoints[i]));
            }

            if (j > 0) {
                // p is the last checkpoint before i
                for (int p = 0; p < i; p++) {
                    // skips is the number of checkpoints
                    // skipped between p and i
                    int skips = i - p - 1;
                    if (j >= skips && dp[p][j - skips] != INT_MAX) {
                        dp[i][j] = min(dp[i][j],
                                       dp[p][j - skips] +
                                           manhattanDistance(checkpoints[p],
                                                             checkpoints[i]));
                    }
                }
            }
        }
    }

    int result = INT_MAX;
    for (int j = 0; j <= K; ++j) result = min(result, dp[N - 1][j]);

    cout << result << endl;

    return 0;
}
